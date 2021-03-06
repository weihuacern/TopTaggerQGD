#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <stdlib.h>

#include "TH1D.h"
#include "TH2D.h"
#include "THStack.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TChain.h"
#include "TList.h"

#include "Math/QuantFuncMathCore.h"
#include "TMath.h"

#include "SusyAnaTools/Tools/NTupleReader.h"
#include "SusyAnaTools/Tools/baselineDef.h"

//Header file for new top tagger
#include "TopTagger/TopTagger/include/TopTagger.h"
#include "TopTagger/TopTagger/include/TopTaggerResults.h"
#include "TopTagger/TopTagger/include/TopTaggerUtilities.h"
//#include "TaggerTest/include/TaggerUtility.h"
//#include "TaggerTest/include/PlotUtility.h"

#include "TriggerEff.h"
#include "QCDReWeighting.h"
#include "TTFactors.h"
#include "BasicQGDHistgram.h"
#include "EffHistgram.h"
#include "MisTagHistgram.h"

//Scale Tfactors with the Tfactor from Real Data
#include "ConstantsSnippet.h"

//all the root file for plotting will go to this directory
std::string dir_out = "RootForPlotting/";

//baseline cut function definition, no need since move to QCD style root file
static BaselineVessel *myBaselineVessel;
void mypassBaselineFunc(NTupleReader& tr)
{
  (*myBaselineVessel)(tr);
}

//search bin definition, with era
//SearchBins mySearchBins("SB_59_2016");
//SearchBins mySearchBins("SB_Aggregate_ICHEP_2016");
//Trigger Eff
TriggerEff myTriggerEff;
//overall scale for all plots, will be set to be 1 if no special need
const double Scale = 1;
//const double Scale = 591.5/2153.736;

void prepareJetsForTagger(
                          std::string runtype,
                          const std::vector<TLorentzVector> &inijetsLVec, 
                          const std::vector<int> &inirecoJetsFlavor,
                          const std::vector<double> &iniqgLikelihood,
                          const std::vector<double> &inirecoJetsBtag, 
                          std::vector<TLorentzVector> &jetsLVec_forTagger, 
                          std::vector<double> &recoJetsBtag_forTagger,
                          std::vector<double> &qgLikelihood_forTagger
                         )
{
  if( !( (runtype == "Normal") || (runtype == "MCTruth") || (runtype == "QGD") ) )
  {
    std::cout << "Invalid run Type!! Please Check!" << std::endl;
    return ;
  }

  jetsLVec_forTagger.clear(); recoJetsBtag_forTagger.clear(); qgLikelihood_forTagger.clear();
  for(unsigned int ij=0; ij<inijetsLVec.size(); ij++)
  {
    if( !AnaFunctions::jetPassCuts(inijetsLVec[ij], AnaConsts::pt30Arr) ) continue; 
    if( runtype == "MCTruth" && (inirecoJetsFlavor[ij]==21 || inirecoJetsFlavor[ij]==0) ) continue;
    if( runtype == "QGD" ) 
    {
      if( inirecoJetsBtag.at(ij)<0.46 )//do not apply QGD on b jet
      {
        if( iniqgLikelihood[ij]<0.1 && iniqgLikelihood[ij]>=0 ) continue;
      }
    }
    jetsLVec_forTagger.push_back(inijetsLVec.at(ij));
    recoJetsBtag_forTagger.push_back(inirecoJetsBtag.at(ij));
    qgLikelihood_forTagger.push_back(iniqgLikelihood.at(ij));
  }
  if(jetsLVec_forTagger.size()<1){ std::cout << "0 jets for tagger input!! Run mode : " << runtype << std::endl; }
  return ;
}

std::vector<TLorentzVector> GetGenTopLVec(
                                          std::vector<TLorentzVector> genDecayLVec,
                                          std::vector<int> genDecayPdgIdVec,
                                          std::vector<int> genDecayIdxVec,
                                          std::vector<int> genDecayMomIdxVec
                                         )
{
  std::vector<TLorentzVector> tLVec;
  for(unsigned it=0; it<genDecayLVec.size(); it++)
  {
    int pdgId = genDecayPdgIdVec.at(it);
    if( std::abs(pdgId)==6 )
    {
      for(unsigned ig=0; ig<genDecayLVec.size(); ig++)
      {
        if( genDecayMomIdxVec.at(ig) == genDecayIdxVec.at(it) )
        {
          int pdgId = genDecayPdgIdVec.at(ig);
          if( std::abs(pdgId)==24 )
          {
            int flag = 0;
            for(unsigned iq=0; iq<genDecayLVec.size(); iq++)
            {
              if( genDecayMomIdxVec.at(iq) == genDecayIdxVec.at(ig) )
              {
                int pdgid = genDecayPdgIdVec.at(iq);
                if( std::abs(pdgid)==11 || std::abs(pdgid)==13 || std::abs(pdgid)==15 ) flag++;
              }
            }
            if(!flag) tLVec.push_back(genDecayLVec.at(it));
          }
        }
      }//dau. loop
    }//top cond
  }//genloop
  return tLVec;
}

bool GetMatchedTop(
                   std::vector<TopObject*> Top, 
                   std::vector<TopObject*> &MachedTop, 
                   std::vector<TLorentzVector> Gentop, 
                   std::vector<TLorentzVector> &MGentop
                  )
{
  bool match = false;
  if(Gentop.size()==0) return match;
  double DeltaR = 0.4;
  for(unsigned nt=0; nt<Top.size();nt++)
  {
    double deltaRMin = 100000.;
    unsigned tid = -1;
    for(unsigned gent = 0; gent < Gentop.size(); gent++) 
    { // Loop over objects
      const double dr = Top[nt]->p().DeltaR(Gentop.at(gent));
      if( dr < deltaRMin ) {deltaRMin = dr; tid = gent;}
    }
    if(deltaRMin < DeltaR)
    {
      MachedTop.push_back(Top[nt]);
      MGentop.push_back(Gentop[tid]);
      match = true;
    }
  }
  return match;
}

/*
bool GetMatchedTop(
                   std::vector<TLorentzVector> Top,
                   std::vector<TLorentzVector> &MachedTop,
                   std::vector<TLorentzVector> Gentop,
                   std::vector<TLorentzVector> &MGentop
                  )
{
  bool match = false;
  if(Gentop.size()==0) return match;
  double DeltaR = 0.4;
  for(unsigned nt=0; nt<Top.size();nt++)
  {
    double deltaRMin = 100000.;
    unsigned tid = -1;
    for(unsigned gent = 0; gent < Gentop.size(); gent++)
    { // Loop over objects 
      const double dr = Top[nt].DeltaR(Gentop.at(gent));
      if( dr < deltaRMin ) {deltaRMin = dr; tid = gent;}
    }
    if(deltaRMin < DeltaR)
    {
      MachedTop.push_back(Top[nt]);
      MGentop.push_back(Gentop[tid]);
      match = true;
    }
  }
  return match;
}
*/

int Set_jetptbin_number( double jetpt )
{
  int jetptbin_num = -1;

  for(int i=0;i<JETSPT_BINS;i++)
  {
    if(i!=JETSPT_BINS-1)
    {
      if(jetpt >= jetptbins_edge[i] && jetpt < jetptbins_edge[i+1]){ jetptbin_num = i; return jetptbin_num; }
    }
    else
    {
      if(jetpt >= jetptbins_edge[i]){ jetptbin_num = i; return jetptbin_num; }
    }
  }

  return jetptbin_num;
}


int Set_jetetabin_number( double jeteta )
{
  int jetetabin_num = -1;

  for(int i=0;i<JETSPT_BINS;i++)
  {
    if(i!=JETSPT_BINS-1)
    {
      if(jeteta >= jetetabins_edge[i] && jeteta < jetetabins_edge[i+1]){ jetetabin_num = i; return jetetabin_num; }
    }
    else
    {
      if(jeteta >= jetetabins_edge[i]){ jetetabin_num = i; return jetetabin_num; }
    }
  }

  return jetetabin_num;
}


//##########functions to calculate Delta_R and Delta Phi###############
double DeltaPhi(double phi1, double phi2) 
{
  double result = phi1 - phi2;
  while (result > M_PI)    result -= 2 * M_PI;
  while (result <= -M_PI)  result += 2 * M_PI;
  return result;
}

double DeltaR(double eta1, double phi1, double eta2, double phi2) 
{
  double deta = eta1 - eta2;
  double dphi = DeltaPhi(phi1, phi2);
  return std::sqrt(deta*deta + dphi*dphi);
}
