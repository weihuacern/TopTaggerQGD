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

#include "QGDNtupleValidation.h"

void LoopQGDValidation( QCDSampleWeight& myTopTaggerCheckSampleWeight )
{
  EffHistgram myEffHistgram;
  myEffHistgram.BookHistgram( (dir_out + "TopTaggerQGDCheck.root").c_str() );
  //clock to monitor the run time
  size_t t0 = clock();
  std::vector<QCDSampleInfo>::iterator iter_QCDSampleInfos;
  int i = 0;

  std::cout << "TopTagger QCD check: " << std::endl;
  for(iter_QCDSampleInfos = myTopTaggerCheckSampleWeight.QCDSampleInfos.begin(); iter_QCDSampleInfos != myTopTaggerCheckSampleWeight.QCDSampleInfos.end(); iter_QCDSampleInfos++)
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
      //(myMisTagHistgram.h_b_ht)->Fill(ht,thisweight);
      //basic distribution for jet
      for(auto i=0;i<jetsLVec.size();i++)
      {
        int pdgid = recoJetsFlavor.at(i);
        //(myEffHistgram.h_b_jetid)->Fill(pdgid,thisweight);
        //(myEffHistgram.h_b_jetid_qglikelihood)->Fill(pdgid,qgLikelihood.at(i),thisweight);

      }
    }//end of inner loop
    i++;
  }//end of QCD Samples loop

  (myEffHistgram.oFile)->Write();
  (myEffHistgram.oFile)->Close();
  return ;
}

int main(int argc, char* argv[])
{
  if (argc < 1)
  {
    std::cerr <<"Please give at least 1 argument " << "runList_QGDValidation " << std::endl;
    std::cerr <<" Valid configurations are " << std::endl;
    std::cerr <<" ./QCD runList_QGDValidation.txt" << std::endl;
    return -1;
  }

  std::string inputFileList_QCDMC = argv[2];
  
  //Sample needed in the basic check loop
  QCDSampleWeight myTopTaggerQCDSampleWeight;
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT100to200"  , 27540000, 71140904, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT200to300"  , 1735000 , 55433477, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT300to500"  , 366800  , 54706298, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT500to700"  , 29370   , 63337753, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT700to1000" , 6524    , 45453945, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT1000to1500", 1064    , 15316362, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT1500to2000", 121.5   , 11650581, LUMI, 1, inputFileList_QCDMC.c_str() );
  myTopTaggerQCDSampleWeight.QCDSampleInfo_push_back( "_QCD_HT2000toInf" , 25.42   ,  6007777, LUMI, 1, inputFileList_QCDMC.c_str() );

  LoopQGDValidation( myTopTaggerQCDSampleWeight );
  return 0;
}
