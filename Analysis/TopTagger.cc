#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <fstream>
#include <vector>

#include "SusyAnaTools/Tools/samples.h"

#include "TStopwatch.h"
#include "TString.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TPad.h"
#include "TStyle.h"

#include "Math/QuantFuncMathCore.h"
#include "TMath.h"
#include "TLorentzVector.h"

#include "TopTagger.h"

void LoopTopTaggerEff( TTFactors& myTTFactors, QCDSampleWeight& myTopTaggerEffSampleWeight )
{
  EffHistgram myEffHistgram;
  myEffHistgram.BookHistgram( (dir_out + "TopTaggerEff.root").c_str() );
  //clock to monitor the run time
  size_t t0 = clock();
  std::vector<QCDSampleInfo>::iterator iter_QCDSampleInfos;
  int i = 0;

  std::cout << "TopTagger Efficiency calculation: " << std::endl;

  for(iter_QCDSampleInfos = myTopTaggerEffSampleWeight.QCDSampleInfos.begin(); iter_QCDSampleInfos != myTopTaggerEffSampleWeight.QCDSampleInfos.end(); iter_QCDSampleInfos++)
  {  
    //use class NTupleReader in the SusyAnaTools/Tools/NTupleReader.h file
    NTupleReader tr((*iter_QCDSampleInfos).chain);
 
    double thisweight = (*iter_QCDSampleInfos).weight;
    std::cout <<"Sample Type: "<< (*iter_QCDSampleInfos).QCDTag << "; Weight: " << thisweight << std::endl;
    
    while(tr.getNextEvent())
    {
      if(tr.getEvtNum()%20000 == 0) std::cout << tr.getEvtNum() << "\t" << ((clock() - t0)/1000000.0) << std::endl;

      //jet related variables
      std::vector<TLorentzVector> jetsLVec = tr.getVec<TLorentzVector>("jetsLVec");
      std::vector<double> qgLikelihood = tr.getVec<double>("qgLikelihood");
      std::vector<double> qgPtD = tr.getVec<double>("qgPtD");
      std::vector<double> qgAxis2 = tr.getVec<double>("qgAxis2");
      std::vector<int> qgMult = tr.getVec<int>("qgMult");
      std::vector<int> recoJetsFlavor= tr.getVec<int>("recoJetsFlavor"); //[-5,-1] and [1,5] are quark jet, 21 is gluon jet, then what the hell is 0 ??
      //std::vector<>  = tr.getVec<>("");

    }//end of inner loop
    i++;
  }//end of QCD Samples loop

  (myEffHistgram.oFile)->Write();
  (myEffHistgram.oFile)->Close();
  return ;
}

void LoopTopTaggerMisTag( TTFactors& myTTFactors, QCDSampleWeight& myTopTaggerMisTagSampleWeight )
{
  MisTagHistgram myMisTagHistgram;
  myMisTagHistgram.BookHistgram( (dir_out + "TopTaggerMisTag.root").c_str() );
  //clock to monitor the run time
  size_t t0 = clock();
  std::vector<QCDSampleInfo>::iterator iter_QCDSampleInfos;
  int i = 0;

  std::cout << "TopTagger MisTag calculation: " << std::endl;

  for(iter_QCDSampleInfos = myTopTaggerMisTagSampleWeight.QCDSampleInfos.begin(); iter_QCDSampleInfos != myTopTaggerMisTagSampleWeight.QCDSampleInfos.end(); iter_QCDSampleInfos++)
  {
    //use class NTupleReader in the SusyAnaTools/Tools/NTupleReader.h file
    NTupleReader tr((*iter_QCDSampleInfos).chain);

    double thisweight = (*iter_QCDSampleInfos).weight;
    std::cout <<"Sample Type: "<< (*iter_QCDSampleInfos).QCDTag << "; Weight: " << thisweight << std::endl;

    while(tr.getNextEvent())
    {
      if(tr.getEvtNum()%20000 == 0) std::cout << tr.getEvtNum() << "\t" << ((clock() - t0)/1000000.0) << std::endl;
      double met = tr.getVar<double>("met");

      //jet related variables
      std::vector<TLorentzVector> jetsLVec = tr.getVec<TLorentzVector>("jetsLVec");
      std::vector<double> qgLikelihood = tr.getVec<double>("qgLikelihood");
      std::vector<double> qgPtD = tr.getVec<double>("qgPtD");
      std::vector<double> qgAxis2 = tr.getVec<double>("qgAxis2");
      std::vector<int> qgMult = tr.getVec<int>("qgMult");
      std::vector<int> recoJetsFlavor= tr.getVec<int>("recoJetsFlavor"); //[-5,-1] and [1,5] are quark jet, 21 is gluon jet, then what the hell is 0 ??
      //std::vector<>  = tr.getVec<>("");

    }//end of inner loop
    i++;
  }//end of QCD Samples loop

  (myMisTagHistgram.oFile)->Write();
  (myMisTagHistgram.oFile)->Close();
  return ;
}

int main(int argc, char* argv[])
{
  if (argc < 3)
  {
    std::cerr <<"Please give at least 3 arguments " << "RunMode " << " " << "runListEff " << " " << "runListMisTag"<< std::endl;
    std::cerr <<" Valid configurations are " << std::endl;
    std::cerr <<" ./QCD RunMode runList_Eff.txt runList_MisTag.txt" << std::endl;
    return -1;
  }

  std::string RunMode = argv[1];
  std::string inputFileList_Eff = argv[2];
  std::string inputFileList_MisTag = argv[3];
  
  std::cout << "The valid run modes are: Eff, MisTag" << std::endl;
  std::cout << "The run mode we have right now is: " << RunMode << std::endl;
  //define my TTFactors class to stroe counts and Translation factors
  TTFactors myTTFactors;
  //myTriggerEff.SelfTest();
  //Sample needed in the calculation and expectation loop
  QCDSampleWeight myTopTaggerEffSampleWeight;
  myTopTaggerEffSampleWeight.QCDSampleInfo_push_back( "_TTJets_Inc"  , 831.76   , 10259872, LUMI, 1, inputFileList_Eff.c_str() );

  //sample needed in the basic check loop
  QCDSampleWeight myTopTaggerMisTagSampleWeight;
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-400To600"  ,    10.73,       1020309, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-600To800"  ,  0.853*3,       5712221, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-800To1200" ,  0.394*3,       1944423, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-1200To2500", 0.0974*3,        513471, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-2500ToInf" ,0.00230*3,        405752, LUMI, 1.23, inputFileList_MisTag.c_str() );

  if( RunMode == "Eff" )
  {
    LoopTopTaggerEff( myTTFactors, myTopTaggerEffSampleWeight );
    return 0;
  }
  else if( RunMode == "MisTag" )
  {
    LoopTopTaggerMisTag( myTTFactors, myTopTaggerMisTagSampleWeight );
    return 0;
  }
  else
  {
    std::cout << "Invalide RunMode!!" << std::endl;
    return 0;
  }

  return 0;
}
