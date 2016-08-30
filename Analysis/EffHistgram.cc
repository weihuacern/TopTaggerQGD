#include "EffHistgram.h"

void EffHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
 
  h_b_ht = new TH1D("h_b_ht","",100,0,2000);
  h_b_jetid = new TH1D("h_b_jetid","",50,-25,25);
  
  h_b_qglikelihood = new TH1D("h_b_qglikelihood","",50,-3,2);
  h_b_qglikelihood_qjets = new TH1D("h_b_qglikelihood_qjets","",50,-3,2);
  h_b_qglikelihood_gjets = new TH1D("h_b_qglikelihood_gjets","",50,-3,2);
  h_b_qglikelihood_pjets = new TH1D("h_b_qglikelihood_pjets","",50,-3,2);
  
  h_b_qgptd = new TH1D("h_b_qgptd","",20,0,2);
  h_b_qgptd_qjets = new TH1D("h_b_qgptd_qjets","",20,0,2);
  h_b_qgptd_gjets = new TH1D("h_b_qgptd_gjets","",20,0,2);
  h_b_qgptd_pjets = new TH1D("h_b_qgptd_pjets","",20,0,2);

  h_b_qgaxis2 = new TH1D("h_b_qgaxis2","",10,0,1);
  h_b_qgaxis2_qjets = new TH1D("h_b_qgaxis2_qjets","",10,0,1);
  h_b_qgaxis2_gjets = new TH1D("h_b_qgaxis2_gjets","",10,0,1);
  h_b_qgaxis2_pjets = new TH1D("h_b_qgaxis2_pjets","",10,0,1);

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
  return ;
}
