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
  h_b_jetid_qglikelihood = new TH2D("h_b_jetid_qglikelihood","",50,-25,25,50,-3,2);
 
  h_gen_top_pt  = new TH1D("h_gen_top_pt" ,"",10000,0,10000);
  h_reco_top_pt = new TH1D("h_reco_top_pt","",10000,0,10000);

  return ;
}
