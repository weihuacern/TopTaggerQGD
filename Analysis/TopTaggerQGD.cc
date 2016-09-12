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

#include "TopTaggerQGD.h"

void LoopTopTaggerCheck( TTFactors& myTTFactors, QCDSampleWeight& myTopTaggerCheckSampleWeight )
{
  BasicQGDHistgram myBasicQGDHistgram;
  myBasicQGDHistgram.BookHistgram( (dir_out + "TopTaggerQGDCheck.root").c_str() );
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
        (myBasicQGDHistgram.h_b_jetid)->Fill(pdgid,thisweight);
        (myBasicQGDHistgram.h_b_jetid_qglikelihood)->Fill(pdgid,qgLikelihood.at(i),thisweight);

        (myBasicQGDHistgram.h_b_qglikelihood)->Fill(qgLikelihood.at(i),thisweight);
        (myBasicQGDHistgram.h_b_qgptd)->Fill(qgPtD.at(i),thisweight);
        (myBasicQGDHistgram.h_b_qgaxis2)->Fill(qgAxis2.at(i),thisweight);
        (myBasicQGDHistgram.h_b_qgmult)->Fill(qgMult.at(i),thisweight);
        
        if(std::abs(pdgid) >= 1 && std::abs(pdgid) <= 3)
        { 
          (myBasicQGDHistgram.h_b_qglikelihood_ljets)->Fill(qgLikelihood.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgptd_ljets)->Fill(qgPtD.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgaxis2_ljets)->Fill(qgAxis2.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgmult_ljets)->Fill(qgMult.at(i),thisweight);
        }
        else if(std::abs(pdgid) == 4)
        {
          (myBasicQGDHistgram.h_b_qglikelihood_cjets)->Fill(qgLikelihood.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgptd_cjets)->Fill(qgPtD.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgaxis2_cjets)->Fill(qgAxis2.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgmult_cjets)->Fill(qgMult.at(i),thisweight);
        }
        else if(std::abs(pdgid) == 5)
        {
          (myBasicQGDHistgram.h_b_qglikelihood_bjets)->Fill(qgLikelihood.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgptd_bjets)->Fill(qgPtD.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgaxis2_bjets)->Fill(qgAxis2.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgmult_bjets)->Fill(qgMult.at(i),thisweight);
        }
        else if(pdgid == 21)
        { 
          (myBasicQGDHistgram.h_b_qglikelihood_gjets)->Fill(qgLikelihood.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgptd_gjets)->Fill(qgPtD.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgaxis2_gjets)->Fill(qgAxis2.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgmult_gjets)->Fill(qgMult.at(i),thisweight);
        }
        else if(pdgid == 0)
        { 
          (myBasicQGDHistgram.h_b_qglikelihood_pjets)->Fill(qgLikelihood.at(i),thisweight); 
          (myBasicQGDHistgram.h_b_qgptd_pjets)->Fill(qgPtD.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgaxis2_pjets)->Fill(qgAxis2.at(i),thisweight);
          (myBasicQGDHistgram.h_b_qgmult_pjets)->Fill(qgMult.at(i),thisweight);
        }
        else{ std::cout << "Not a quark, gluon or pileup jet, what the fuck!! PDGID : " << pdgid << std::endl; }
      }
    }//end of inner loop
    i++;
  }//end of QCD Samples loop

  (myBasicQGDHistgram.oFile)->Write();
  (myBasicQGDHistgram.oFile)->Close();
  return ;
}

void LoopTopTaggerEff( TTFactors& myTTFactors, QCDSampleWeight& myTopTaggerEffSampleWeight )
{
  EffHistgram myEffHistgram;
  myEffHistgram.BookHistgram( (dir_out + "TopTaggerEff.root").c_str() );
  //clock to monitor the run time
  size_t t0 = clock();
  std::vector<QCDSampleInfo>::iterator iter_QCDSampleInfos;
  int i = 0;

  //use class BaselineVessel in the SusyAnaTools/Tools/baselineDef.h file
  std::string spec = "TopTaggerTest";
  myBaselineVessel = new BaselineVessel(spec);
  std::cout << "TopTagger Efficiency calculation: " << std::endl;
  for(iter_QCDSampleInfos = myTopTaggerEffSampleWeight.QCDSampleInfos.begin(); iter_QCDSampleInfos != myTopTaggerEffSampleWeight.QCDSampleInfos.end(); iter_QCDSampleInfos++)
  {  
    //use class NTupleReader in the SusyAnaTools/Tools/NTupleReader.h file
    NTupleReader tr((*iter_QCDSampleInfos).chain);
     //initialize the type3Ptr defined in the customize.h
    AnaFunctions::prepareTopTagger();
    //The passBaseline is registered here
    tr.registerFunction(&mypassBaselineFunc);

    double thisweight = (*iter_QCDSampleInfos).weight;
    std::cout <<"Sample Type: "<< (*iter_QCDSampleInfos).QCDTag << "; Weight: " << thisweight << std::endl;
    
    while(tr.getNextEvent())
    {
      if(tr.getEvtNum()%20000 == 0) std::cout << tr.getEvtNum() << "\t" << ((clock() - t0)/1000000.0) << std::endl;
      bool passnJets = tr.getVar<bool>("passnJets"+spec);
      if(!passnJets) continue;

      double met = tr.getVar<double>("met");
      int njets30 = tr.getVar<int>("cntNJetsPt30Eta24"+spec);
      int njets50 = tr.getVar<int>("cntNJetsPt50Eta24"+spec);
      double ht = tr.getVar<double>("HT"+spec);
      TLorentzVector mht_TLV = AnaFunctions::calcMHT(tr.getVec<TLorentzVector>("jetsLVec"), AnaConsts::pt30Eta24Arr);
      double mht = mht_TLV.Pt();
      int nbotjets = tr.getVar<int>("cntCSVS"+spec);

      //jet related variables
      std::vector<TLorentzVector> jetsLVec = tr.getVec<TLorentzVector>("jetsLVec");
      std::vector<double> qgLikelihood = tr.getVec<double>("qgLikelihood");
      std::vector<double> qgPtD = tr.getVec<double>("qgPtD");
      std::vector<double> qgAxis2 = tr.getVec<double>("qgAxis2");
      std::vector<int> qgMult = tr.getVec<int>("qgMult");
      std::vector<int> recoJetsFlavor= tr.getVec<int>("recoJetsFlavor"); //[-5,-1] and [1,5] are quark jet, 21 is gluon jet, then what the hell is 0 ??
      //std::vector<>  = tr.getVec<>("");
      //(myMisTagHistgram.h_b_ht)->Fill(ht,thisweight);

      //Top tagger efficiency study
      //Get gen top TLVec
      const std::vector<TLorentzVector> &genDecayLVec = tr.getVec<TLorentzVector>("genDecayLVec");
      const std::vector<int> &genDecayIdxVec = tr.getVec<int>("genDecayIdxVec");
      const std::vector<int> &genDecayPdgIdVec = tr.getVec<int>("genDecayPdgIdVec");
      const std::vector<int> &genDecayMomIdxVec = tr.getVec<int>("genDecayMomIdxVec");
      std::vector<TLorentzVector> GenTop = GetGenTopLVec(genDecayLVec, genDecayPdgIdVec, genDecayIdxVec, genDecayMomIdxVec);
      //Get recotop TLVec in 3 types : old tagger, mc truth and qg
      TLorentzVector metLVec; metLVec.SetPtEtaPhiM(tr.getVar<double>("met"), 0, tr.getVar<double>("metphi"), 0);
      std::vector<TLorentzVector> *jetsLVec_forTagger = new std::vector<TLorentzVector>(); std::vector<double> *recoJetsBtag_forTagger = new std::vector<double>();
      //normal top tagger, no QGD
      prepareJetsForTagger(
                           "Normal",
                           jetsLVec, 
                           recoJetsFlavor,
                           qgLikelihood,
                           tr.getVec<double>("recoJetsBtag_0"), 
                           (*jetsLVec_forTagger), 
                           (*recoJetsBtag_forTagger)
                          );
      TopTagger tt_Normal; tt_Normal.setCfgFile("Example_TopTagger.cfg");
      const std::vector<TLorentzVector> &jetsLVec_ForTop_Normal = (*jetsLVec_forTagger); const std::vector<double> &recoJetsBtag_ForTop_Normal = (*recoJetsBtag_forTagger);
      std::vector<Constituent> constituents_Normal = ttUtility::packageConstituents(jetsLVec_ForTop_Normal, recoJetsBtag_ForTop_Normal); tt_Normal.runTagger(constituents_Normal);
      const TopTaggerResults& ttr_Normal = tt_Normal.getResults(); std::vector<TopObject*> NTop_Normal = ttr_Normal.getTops();
      
      //top tagger with quark jet info only
      prepareJetsForTagger(
                           "MCTruth",
                           jetsLVec,
                           recoJetsFlavor,
                           qgLikelihood,
                           tr.getVec<double>("recoJetsBtag_0"),
                           (*jetsLVec_forTagger),
                           (*recoJetsBtag_forTagger)
                          );
      TopTagger tt_MCTruth; tt_MCTruth.setCfgFile("Example_TopTagger.cfg");
      const std::vector<TLorentzVector> &jetsLVec_ForTop_MCTruth = (*jetsLVec_forTagger); const std::vector<double> &recoJetsBtag_ForTop_MCTruth = (*recoJetsBtag_forTagger);
      std::vector<Constituent> constituents_MCTruth = ttUtility::packageConstituents(jetsLVec_ForTop_MCTruth, recoJetsBtag_ForTop_MCTruth); tt_MCTruth.runTagger(constituents_MCTruth);
      const TopTaggerResults& ttr_MCTruth = tt_MCTruth.getResults(); std::vector<TopObject*> NTop_MCTruth = ttr_MCTruth.getTops();

      //top tagger with qgl hard cut
      prepareJetsForTagger(
                           "QGD",
                           jetsLVec,
                           recoJetsFlavor,
                           qgLikelihood,
                           tr.getVec<double>("recoJetsBtag_0"),
                           (*jetsLVec_forTagger),
                           (*recoJetsBtag_forTagger)
                          );
      TopTagger tt_QGD; tt_QGD.setCfgFile("Example_TopTagger.cfg");
      const std::vector<TLorentzVector> &jetsLVec_ForTop_QGD = (*jetsLVec_forTagger); const std::vector<double> &recoJetsBtag_ForTop_QGD = (*recoJetsBtag_forTagger);
      std::vector<Constituent> constituents_QGD = ttUtility::packageConstituents(jetsLVec_ForTop_QGD, recoJetsBtag_ForTop_QGD); tt_QGD.runTagger(constituents_QGD);
      const TopTaggerResults& ttr_QGD = tt_QGD.getResults(); std::vector<TopObject*> NTop_QGD = ttr_QGD.getTops();
    
      //matching...dR only
      std::vector<TopObject*> MatchNTop_Normal; std::vector<TopObject*> MatchNTop_MCTruth; std::vector<TopObject*> MatchNTop_QGD;
      std::vector<TLorentzVector> MatchGenTop_Normal; std::vector<TLorentzVector> MatchGenTop_MCTruth; std::vector<TLorentzVector> MatchGenTop_QGD;
      GetMatchedTop(NTop_Normal , MatchNTop_Normal , GenTop, MatchGenTop_Normal );
      GetMatchedTop(NTop_MCTruth, MatchNTop_MCTruth, GenTop, MatchGenTop_MCTruth);
      GetMatchedTop(NTop_QGD    , MatchNTop_QGD    , GenTop, MatchGenTop_QGD    );
      //efficiency plots
      for(auto& i:GenTop)
      {
        (myEffHistgram.h_denominator_gentoppt)->Fill(i.Pt(),thisweight);
        (myEffHistgram.h_denominator_met)->Fill(met,thisweight);
        (myEffHistgram.h_denominator_njets30)->Fill(njets30,thisweight);
        (myEffHistgram.h_denominator_njets50)->Fill(njets50,thisweight);
        (myEffHistgram.h_denominator_ht)->Fill(ht,thisweight);
        (myEffHistgram.h_denominator_mht)->Fill(mht,thisweight);
        (myEffHistgram.h_denominator_nbotjets)->Fill(nbotjets,thisweight);
      }
      for(auto& i:MatchGenTop_Normal)
      {
        (myEffHistgram.h_numerator_normal_gentoppt)->Fill(i.Pt(),thisweight);
        (myEffHistgram.h_numerator_normal_met)->Fill(met,thisweight);
        (myEffHistgram.h_numerator_normal_njets30)->Fill(njets30,thisweight);
        (myEffHistgram.h_numerator_normal_njets50)->Fill(njets50,thisweight);
        (myEffHistgram.h_numerator_normal_ht)->Fill(ht,thisweight);
        (myEffHistgram.h_numerator_normal_mht)->Fill(mht,thisweight);
        (myEffHistgram.h_numerator_normal_nbotjets)->Fill(nbotjets,thisweight);
      }
      for(auto& i:MatchGenTop_MCTruth)
      {
        (myEffHistgram.h_numerator_mctruth_gentoppt)->Fill(i.Pt(),thisweight);
        (myEffHistgram.h_numerator_mctruth_met)->Fill(met,thisweight);
        (myEffHistgram.h_numerator_mctruth_njets30)->Fill(njets30,thisweight);
        (myEffHistgram.h_numerator_mctruth_njets50)->Fill(njets50,thisweight);
        (myEffHistgram.h_numerator_mctruth_ht)->Fill(ht,thisweight);
        (myEffHistgram.h_numerator_mctruth_mht)->Fill(mht,thisweight);
        (myEffHistgram.h_numerator_mctruth_nbotjets)->Fill(nbotjets,thisweight);
      }
      for(auto& i:MatchGenTop_QGD)
      {
        (myEffHistgram.h_numerator_qgd_gentoppt)->Fill(i.Pt(),thisweight);
        (myEffHistgram.h_numerator_qgd_met)->Fill(met,thisweight);
        (myEffHistgram.h_numerator_qgd_njets30)->Fill(njets30,thisweight);    
        (myEffHistgram.h_numerator_qgd_njets50)->Fill(njets50,thisweight);
        (myEffHistgram.h_numerator_qgd_ht)->Fill(ht,thisweight);
        (myEffHistgram.h_numerator_qgd_mht)->Fill(mht,thisweight);
        (myEffHistgram.h_numerator_qgd_nbotjets)->Fill(nbotjets,thisweight);
      }
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

  //use class BaselineVessel in the SusyAnaTools/Tools/baselineDef.h file
  std::string spec = "TopTaggerTest";
  myBaselineVessel = new BaselineVessel(spec);
  std::cout << "TopTagger MisTag calculation: " << std::endl;
  for(iter_QCDSampleInfos = myTopTaggerMisTagSampleWeight.QCDSampleInfos.begin(); iter_QCDSampleInfos != myTopTaggerMisTagSampleWeight.QCDSampleInfos.end(); iter_QCDSampleInfos++)
  {
    //use class NTupleReader in the SusyAnaTools/Tools/NTupleReader.h file
    NTupleReader tr((*iter_QCDSampleInfos).chain);
    //initialize the type3Ptr defined in the customize.h
    AnaFunctions::prepareTopTagger();
    //The passBaseline is registered here
    tr.registerFunction(&mypassBaselineFunc);
    
    double thisweight = (*iter_QCDSampleInfos).weight;
    std::cout <<"Sample Type: "<< (*iter_QCDSampleInfos).QCDTag << "; Weight: " << thisweight << std::endl;

    while(tr.getNextEvent())
    {
      if(tr.getEvtNum()%20000 == 0) std::cout << tr.getEvtNum() << "\t" << ((clock() - t0)/1000000.0) << std::endl;
      bool passnJets = tr.getVar<bool>("passnJets"+spec);
      if(!passnJets) continue;

      double met = tr.getVar<double>("met");
      int njets30 = tr.getVar<int>("cntNJetsPt30Eta24"+spec);
      int njets50 = tr.getVar<int>("cntNJetsPt50Eta24"+spec);
      double ht = tr.getVar<double>("HT"+spec);
      TLorentzVector mht_TLV = AnaFunctions::calcMHT(tr.getVec<TLorentzVector>("jetsLVec"), AnaConsts::pt30Eta24Arr);
      double mht = mht_TLV.Pt();
      int nbotjets = tr.getVar<int>("cntCSVS"+spec);

      //jet related variables
      std::vector<TLorentzVector> jetsLVec = tr.getVec<TLorentzVector>("jetsLVec");
      std::vector<double> qgLikelihood = tr.getVec<double>("qgLikelihood");
      std::vector<double> qgPtD = tr.getVec<double>("qgPtD");
      std::vector<double> qgAxis2 = tr.getVec<double>("qgAxis2");
      std::vector<int> qgMult = tr.getVec<int>("qgMult");
      std::vector<int> recoJetsFlavor= tr.getVec<int>("recoJetsFlavor"); //[-5,-1] and [1,5] are quark jet, 21 is gluon jet, then what the hell is 0 ??
      
      //Denominator for Mistag rate
      (myMisTagHistgram.h_denominator_met)->Fill(met,thisweight);
      (myMisTagHistgram.h_denominator_njets30)->Fill(njets30,thisweight);
      (myMisTagHistgram.h_denominator_njets50)->Fill(njets50,thisweight);
      (myMisTagHistgram.h_denominator_ht)->Fill(ht,thisweight);
      (myMisTagHistgram.h_denominator_mht)->Fill(mht,thisweight);
      (myMisTagHistgram.h_denominator_nbotjets)->Fill(nbotjets,thisweight);

      //configure top tagger
      TLorentzVector metLVec; metLVec.SetPtEtaPhiM(tr.getVar<double>("met"), 0, tr.getVar<double>("metphi"), 0);
      std::vector<TLorentzVector> *jetsLVec_forTagger = new std::vector<TLorentzVector>(); std::vector<double> *recoJetsBtag_forTagger = new std::vector<double>();
    
      //normal top tagger, no QGD
      prepareJetsForTagger(
                           "Normal",
                           jetsLVec, 
                           recoJetsFlavor,
                           qgLikelihood,
                           tr.getVec<double>("recoJetsBtag_0"), 
                           (*jetsLVec_forTagger), 
                           (*recoJetsBtag_forTagger)
                          );
      TopTagger tt_Normal; tt_Normal.setCfgFile("Example_TopTagger.cfg");
      const std::vector<TLorentzVector> &jetsLVec_ForTop_Normal = (*jetsLVec_forTagger); const std::vector<double> &recoJetsBtag_ForTop_Normal = (*recoJetsBtag_forTagger);
      std::vector<Constituent> constituents_Normal = ttUtility::packageConstituents(jetsLVec_ForTop_Normal, recoJetsBtag_ForTop_Normal); tt_Normal.runTagger(constituents_Normal);
      const TopTaggerResults& ttr_Normal = tt_Normal.getResults();
      //std::vector<TopObject*> Ntop = ttr.getTops();
      //std::vector<TopObject> NtopCand = ttr.getTopCandidates();
      if( (ttr_Normal.getTops()).size()>=1 ) 
      { 
        (myMisTagHistgram.h_numerator_normal_met)->Fill(met,thisweight);
        (myMisTagHistgram.h_numerator_normal_njets30)->Fill(njets30,thisweight);
        (myMisTagHistgram.h_numerator_normal_njets50)->Fill(njets50,thisweight);
        (myMisTagHistgram.h_numerator_normal_ht)->Fill(ht,thisweight);
        (myMisTagHistgram.h_numerator_normal_mht)->Fill(mht,thisweight);
        (myMisTagHistgram.h_numerator_normal_nbotjets)->Fill(nbotjets,thisweight);
      }

      prepareJetsForTagger(
                           "MCTruth",
                           jetsLVec,
                           recoJetsFlavor,
                           qgLikelihood,
                           tr.getVec<double>("recoJetsBtag_0"),
                           (*jetsLVec_forTagger),
                           (*recoJetsBtag_forTagger)
                          );
      TopTagger tt_MCTruth; tt_MCTruth.setCfgFile("Example_TopTagger.cfg");
      const std::vector<TLorentzVector> &jetsLVec_ForTop_MCTruth = (*jetsLVec_forTagger); const std::vector<double> &recoJetsBtag_ForTop_MCTruth = (*recoJetsBtag_forTagger);
      std::vector<Constituent> constituents_MCTruth = ttUtility::packageConstituents(jetsLVec_ForTop_MCTruth, recoJetsBtag_ForTop_MCTruth); tt_MCTruth.runTagger(constituents_MCTruth);
      const TopTaggerResults& ttr_MCTruth = tt_MCTruth.getResults();
      if( (ttr_MCTruth.getTops()).size()>=1 )
      {
        (myMisTagHistgram.h_numerator_mctruth_met)->Fill(met,thisweight);
        (myMisTagHistgram.h_numerator_mctruth_njets30)->Fill(njets30,thisweight);
        (myMisTagHistgram.h_numerator_mctruth_njets50)->Fill(njets50,thisweight);
        (myMisTagHistgram.h_numerator_mctruth_ht)->Fill(ht,thisweight);
        (myMisTagHistgram.h_numerator_mctruth_mht)->Fill(mht,thisweight);
        (myMisTagHistgram.h_numerator_mctruth_nbotjets)->Fill(nbotjets,thisweight);
      }

      prepareJetsForTagger(
                           "QGD",
                           jetsLVec,
                           recoJetsFlavor,
                           qgLikelihood,
                           tr.getVec<double>("recoJetsBtag_0"),
                           (*jetsLVec_forTagger),
                           (*recoJetsBtag_forTagger)
                          );
      TopTagger tt_QGD;
      tt_QGD.setCfgFile("Example_TopTagger.cfg");
      const std::vector<TLorentzVector> &jetsLVec_ForTop_QGD = (*jetsLVec_forTagger); const std::vector<double> &recoJetsBtag_ForTop_QGD = (*recoJetsBtag_forTagger);
      std::vector<Constituent> constituents_QGD = ttUtility::packageConstituents(jetsLVec_ForTop_QGD, recoJetsBtag_ForTop_QGD); tt_QGD.runTagger(constituents_QGD);
      const TopTaggerResults& ttr_QGD = tt_QGD.getResults();
      if( (ttr_QGD.getTops()).size()>=1 )
      {
        (myMisTagHistgram.h_numerator_qgd_met)->Fill(met,thisweight);
        (myMisTagHistgram.h_numerator_qgd_njets30)->Fill(njets30,thisweight);    
        (myMisTagHistgram.h_numerator_qgd_njets50)->Fill(njets50,thisweight);
        (myMisTagHistgram.h_numerator_qgd_ht)->Fill(ht,thisweight);
        (myMisTagHistgram.h_numerator_qgd_mht)->Fill(mht,thisweight);
        (myMisTagHistgram.h_numerator_qgd_nbotjets)->Fill(nbotjets,thisweight);
      }
    }//end of inner loop
    i++;
  }//end of QCD Samples loop

  (myMisTagHistgram.oFile)->Write();
  (myMisTagHistgram.oFile)->Close();
  return ;
}

int main(int argc, char* argv[])
{
  if (argc < 4)
  {
    std::cerr <<"Please give at least 4 arguments " << "RunMode " << " " << "runListEff " << " " << "runListMisTag"<< " " << "runListQCD " << std::endl;
    std::cerr <<" Valid configurations are " << std::endl;
    std::cerr <<" ./QCD RunMode runList_QCD.txt runList_Eff.txt runList_MisTag.txt" << std::endl;
    return -1;
  }

  std::string RunMode = argv[1];
  std::string inputFileList_QCDMC = argv[2];
  std::string inputFileList_Eff = argv[3];
  std::string inputFileList_MisTag = argv[4];
  
  std::cout << "The valid run modes are: Check, Eff, MisTag" << std::endl;
  std::cout << "The run mode we have right now is: " << RunMode << std::endl;
  //define my TTFactors class to stroe counts and Translation factors
  TTFactors myTTFactors;

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

  //Sample needed in the efficiency calculation loop
  QCDSampleWeight myTopTaggerEffSampleWeight;
  myTopTaggerEffSampleWeight.QCDSampleInfo_push_back( "_TTJets_Inc"  , 831.76   , 10259872, LUMI, 1, inputFileList_Eff.c_str() );

  //sample needed in the mistag rate loop
  QCDSampleWeight myTopTaggerMisTagSampleWeight;
  //myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-400To600"  ,    10.73,       1020309, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-600To800"  ,  0.853*3,       5712221, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-800To1200" ,  0.394*3,       1944423, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-1200To2500", 0.0974*3,        513471, LUMI, 1.23, inputFileList_MisTag.c_str() );
  myTopTaggerMisTagSampleWeight.QCDSampleInfo_push_back( "_ZJetsToNuNu_HT-2500ToInf" ,0.00230*3,        405752, LUMI, 1.23, inputFileList_MisTag.c_str() );

  if( RunMode == "Check" )
  {
    LoopTopTaggerCheck( myTTFactors, myTopTaggerEffSampleWeight );
    return 0;
  }
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
