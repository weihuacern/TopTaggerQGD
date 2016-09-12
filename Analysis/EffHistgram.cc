#include "EffHistgram.h"

void EffHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
  h_gen_top_pt  = new TH1D("h_gen_top_pt" ,"",10000,0,10000);
  h_reco_top_pt = new TH1D("h_reco_top_pt","",10000,0,10000);

  h_denominator_gentoppt = new TH1D("h_denominator_gentoppt","",50,0,1000);
  h_numerator_normal_gentoppt = new TH1D("h_numerator_normal_gentoppt","",50,0,1000);
  h_numerator_mctruth_gentoppt = new TH1D("h_numerator_mctruth_gentoppt","",50,0,1000);
  h_numerator_qgd_gentoppt = new TH1D("h_numerator_qgd_gentoppt","",50,0,1000);

  h_denominator_met = new TH1D("h_denominator_met","",50,0,1000);
  h_denominator_njets30 = new TH1D("h_denominator_njets30","",20,0,20);
  h_denominator_njets50 = new TH1D("h_denominator_njets50","",20,0,20);
  h_denominator_ht = new TH1D("h_denominator_ht","",60,0,3000);
  h_denominator_mht = new TH1D("h_denominator_mht","",50,0,1000);
  h_denominator_nbotjets = new TH1D("h_denominator_nbotjets","",20,0,20);

  h_numerator_normal_met = new TH1D("h_numerator_normal_met","",50,0,1000);
  h_numerator_normal_njets30 = new TH1D("h_numerator_normal_njets30","",20,0,20);
  h_numerator_normal_njets50 = new TH1D("h_numerator_normal_njets50","",20,0,20);
  h_numerator_normal_ht = new TH1D("h_numerator_normal_ht","",60,0,3000);
  h_numerator_normal_mht = new TH1D("h_numerator_normal_mht","",50,0,1000);
  h_numerator_normal_nbotjets = new TH1D("h_numerator_normal_nbotjets","",20,0,20);

  h_numerator_mctruth_met = new TH1D("h_numerator_mctruth_met","",50,0,1000);
  h_numerator_mctruth_njets30 = new TH1D("h_numerator_mctruth_njets30","",20,0,20);
  h_numerator_mctruth_njets50 = new TH1D("h_numerator_mctruth_njets50","",20,0,20);
  h_numerator_mctruth_ht = new TH1D("h_numerator_mctruth_ht","",60,0,3000);
  h_numerator_mctruth_mht = new TH1D("h_numerator_mctruth_mht","",50,0,1000);
  h_numerator_mctruth_nbotjets = new TH1D("h_numerator_mctruth_nbotjets","",20,0,20);

  h_numerator_qgd_met = new TH1D("h_numerator_qgd_met","",50,0,1000);
  h_numerator_qgd_njets30 = new TH1D("h_numerator_qgd_njets30","",20,0,20);
  h_numerator_qgd_njets50 = new TH1D("h_numerator_qgd_njets50","",20,0,20);
  h_numerator_qgd_ht = new TH1D("h_numerator_qgd_ht","",60,0,3000);
  h_numerator_qgd_mht = new TH1D("h_numerator_qgd_mht","",50,0,1000);
  h_numerator_qgd_nbotjets = new TH1D("h_numerator_qgd_nbotjets","",20,0,20);

  return ;
}
