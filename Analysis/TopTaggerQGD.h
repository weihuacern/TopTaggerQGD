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
                          std::vector<double> &recoJetsBtag_forTagger
                         )
{
  if( !( (runtype == "Normal") || (runtype == "MCTruth") || (runtype == "QGD") ) )
  {
    std::cout << "Invalid run Type!! Please Check!" << std::endl;
    return ;
  }

  jetsLVec_forTagger.clear(); recoJetsBtag_forTagger.clear();
  for(unsigned int ij=0; ij<inijetsLVec.size(); ij++)
  {
    if( !AnaFunctions::jetPassCuts(inijetsLVec[ij], AnaConsts::pt30Arr) ) continue; 
    if( runtype == "MCTruth" && (inirecoJetsFlavor[ij]>6 || inirecoJetsFlavor[ij]==0) ) continue;
    if( runtype == "QGD" && (iniqgLikelihood[ij]<0.5 && iniqgLikelihood[ij]>=0) ) continue;

    jetsLVec_forTagger.push_back(inijetsLVec.at(ij));
    recoJetsBtag_forTagger.push_back(inirecoJetsBtag.at(ij));
  }
  return ;
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