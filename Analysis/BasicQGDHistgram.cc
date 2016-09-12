#include "BasicQGDHistgram.h"

void BasicQGDHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
 
  h_b_ht = new TH1D("h_b_ht","",100,0,2000);
  h_b_jetid = new TH1D("h_b_jetid","",50,-25,25);
  
  h_b_qglikelihood = new TH1D("h_b_qglikelihood","",500,-3,2);
  h_b_qglikelihood_ljets = new TH1D("h_b_qglikelihood_ljets","",500,-3,2);
  h_b_qglikelihood_cjets = new TH1D("h_b_qglikelihood_cjets","",500,-3,2);
  h_b_qglikelihood_bjets = new TH1D("h_b_qglikelihood_bjets","",500,-3,2);
  h_b_qglikelihood_gjets = new TH1D("h_b_qglikelihood_gjets","",500,-3,2);
  h_b_qglikelihood_pjets = new TH1D("h_b_qglikelihood_pjets","",500,-3,2);
  
  h_b_qgptd = new TH1D("h_b_qgptd","",100,0,2);
  h_b_qgptd_ljets = new TH1D("h_b_qgptd_ljets","",200,0,2);
  h_b_qgptd_cjets = new TH1D("h_b_qgptd_cjets","",200,0,2);
  h_b_qgptd_bjets = new TH1D("h_b_qgptd_bjets","",200,0,2);
  h_b_qgptd_gjets = new TH1D("h_b_qgptd_gjets","",200,0,2);
  h_b_qgptd_pjets = new TH1D("h_b_qgptd_pjets","",200,0,2);

  h_b_qgaxis2 = new TH1D("h_b_qgaxis2","",50,0,1);
  h_b_qgaxis2_ljets = new TH1D("h_b_qgaxis2_ljets","",200,0,1);
  h_b_qgaxis2_cjets = new TH1D("h_b_qgaxis2_cjets","",200,0,1);
  h_b_qgaxis2_bjets = new TH1D("h_b_qgaxis2_bjets","",200,0,1);
  h_b_qgaxis2_gjets = new TH1D("h_b_qgaxis2_gjets","",200,0,1);
  h_b_qgaxis2_pjets = new TH1D("h_b_qgaxis2_pjets","",200,0,1);

  h_b_qgmult = new TH1D("h_b_qgmult","",50,0,50);
  h_b_qgmult_ljets = new TH1D("h_b_qgmult_ljets","",50,0,50);
  h_b_qgmult_cjets = new TH1D("h_b_qgmult_cjets","",50,0,50);
  h_b_qgmult_bjets = new TH1D("h_b_qgmult_bjets","",50,0,50);
  h_b_qgmult_gjets = new TH1D("h_b_qgmult_gjets","",50,0,50);
  h_b_qgmult_pjets = new TH1D("h_b_qgmult_pjets","",50,0,50);

  h_b_jetid_qglikelihood = new TH2D("h_b_jetid_qglikelihood","",50,-25,25,50,-3,2);
 
  return ;
}
