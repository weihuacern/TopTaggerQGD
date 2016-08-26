#include "MisTagHistgram.h"

void MisTagHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");

  h_denominator_met = new TH1D("h_denominator_met","",50,0,1000);
  h_denominator_njets30 = new TH1D("h_denominator_njets30","",20,0,20);
  h_denominator_njets50 = new TH1D("h_denominator_njets50","",20,0,20);
  h_denominator_mt2 = new TH1D("h_denominator_mt2","",50,0,1000);
  h_denominator_ht = new TH1D("h_denominator_ht","",60,0,3000);
  h_denominator_mht = new TH1D("h_denominator_mht","",50,0,1000);
  h_denominator_ntopjets = new TH1D("h_denominator_ntopjets","",20,0,20);
  h_denominator_nbjets = new TH1D("h_denominator_nbjets","",20,0,20);

  h_numerator_normal_met = new TH1D("h_numerator_normal_met","",50,0,1000);
  h_numerator_normal_njets30 = new TH1D("h_numerator_normal_njets30","",20,0,20);
  h_numerator_normal_njets50 = new TH1D("h_numerator_normal_njets50","",20,0,20);
  h_numerator_normal_mt2 = new TH1D("h_numerator_normal_mt2","",50,0,1000);
  h_numerator_normal_ht = new TH1D("h_numerator_normal_ht","",60,0,3000);
  h_numerator_normal_mht = new TH1D("h_numerator_normal_mht","",50,0,1000);
  h_numerator_normal_ntopjets = new TH1D("h_numerator_normal_ntopjets","",20,0,20);
  h_numerator_normal_nbjets = new TH1D("h_numerator_normal_nbjets","",20,0,20);

  h_numerator_mctruth_met = new TH1D("h_numerator_mctruth_met","",50,0,1000);
  h_numerator_mctruth_njets30 = new TH1D("h_numerator_mctruth_njets30","",20,0,20);
  h_numerator_mctruth_njets50 = new TH1D("h_numerator_mctruth_njets50","",20,0,20);
  h_numerator_mctruth_mt2 = new TH1D("h_numerator_mctruth_mt2","",50,0,1000);
  h_numerator_mctruth_ht = new TH1D("h_numerator_mctruth_ht","",60,0,3000);
  h_numerator_mctruth_mht = new TH1D("h_numerator_mctruth_mht","",50,0,1000);
  h_numerator_mctruth_ntopjets = new TH1D("h_numerator_mctruth_ntopjets","",20,0,20);
  h_numerator_mctruth_nbjets = new TH1D("h_numerator_mctruth_nbjets","",20,0,20);

  h_numerator_qgd_met = new TH1D("h_numerator_qgd_met","",50,0,1000);
  h_numerator_qgd_njets30 = new TH1D("h_numerator_qgd_njets30","",20,0,20);
  h_numerator_qgd_njets50 = new TH1D("h_numerator_qgd_njets50","",20,0,20);
  h_numerator_qgd_mt2 = new TH1D("h_numerator_qgd_mt2","",50,0,1000);
  h_numerator_qgd_ht = new TH1D("h_numerator_qgd_ht","",60,0,3000);
  h_numerator_qgd_mht = new TH1D("h_numerator_qgd_mht","",50,0,1000);
  h_numerator_qgd_ntopjets = new TH1D("h_numerator_qgd_ntopjets","",20,0,20);
  h_numerator_qgd_nbjets = new TH1D("h_numerator_qgd_nbjets","",20,0,20);

  return ;
}

