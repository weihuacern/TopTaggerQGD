#include "EffHistgram.h"

void EffHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
 
  h_b_ht = new TH1D("h_b_ht","",100,0,2000);
  h_b_jetid = new TH1D("h_b_jetid","",50,-25,25);
  
  h_b_qglikelihood = new TH1D("h_b_qglikelihood","",500,-3,2);
  h_b_qglikelihood_qjets = new TH1D("h_b_qglikelihood_qjets","",500,-3,2);
  h_b_qglikelihood_gjets = new TH1D("h_b_qglikelihood_gjets","",500,-3,2);
  h_b_qglikelihood_pjets = new TH1D("h_b_qglikelihood_pjets","",500,-3,2);
  
  h_b_qgptd = new TH1D("h_b_qgptd","",100,0,2);
  h_b_qgptd_qjets = new TH1D("h_b_qgptd_qjets","",200,0,2);
  h_b_qgptd_gjets = new TH1D("h_b_qgptd_gjets","",200,0,2);
  h_b_qgptd_pjets = new TH1D("h_b_qgptd_pjets","",200,0,2);

  h_b_qgaxis2 = new TH1D("h_b_qgaxis2","",50,0,1);
  h_b_qgaxis2_qjets = new TH1D("h_b_qgaxis2_qjets","",200,0,1);
  h_b_qgaxis2_gjets = new TH1D("h_b_qgaxis2_gjets","",200,0,1);
  h_b_qgaxis2_pjets = new TH1D("h_b_qgaxis2_pjets","",200,0,1);

  h_b_qgmult = new TH1D("h_b_qgmult","",50,0,50);
  h_b_qgmult_qjets = new TH1D("h_b_qgmult_qjets","",50,0,50);
  h_b_qgmult_gjets = new TH1D("h_b_qgmult_gjets","",50,0,50);
  h_b_qgmult_pjets = new TH1D("h_b_qgmult_pjets","",50,0,50);

  h_b_jetid_qglikelihood = new TH2D("h_b_jetid_qglikelihood","",50,-25,25,50,-3,2);
 
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
