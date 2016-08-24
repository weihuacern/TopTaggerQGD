#include "MisTagHistgram.h"

void MisTagHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
  //closure plots on different variables
  h_pred_met = new TH1D("h_pred_met","",50,0,1000);
  h_pred_njets30 = new TH1D("h_pred_njets30","",20,0,20);
  h_pred_njets50 = new TH1D("h_pred_njets50","",20,0,20);
  h_pred_mt2 = new TH1D("h_pred_mt2","",50,0,1000);
  h_pred_ht = new TH1D("h_pred_ht","",60,0,3000);
  h_pred_mht = new TH1D("h_pred_mht","",50,0,1000);
  h_pred_ntopjets = new TH1D("h_pred_ntopjets","",20,0,20);
  h_pred_nbjets = new TH1D("h_pred_nbjets","",20,0,20);

  h_exp_met = new TH1D("h_exp_met","",50,0,1000);
  h_exp_njets30 = new TH1D("h_exp_njets30","",20,0,20);
  h_exp_njets50 = new TH1D("h_exp_njets50","",20,0,20);
  h_exp_mt2 = new TH1D("h_exp_mt2","",50,0,1000);
  h_exp_ht = new TH1D("h_exp_ht","",60,0,3000);
  h_exp_mht = new TH1D("h_exp_mht","",50,0,1000);
  h_exp_ntopjets = new TH1D("h_exp_ntopjets","",20,0,20);
  h_exp_nbjets = new TH1D("h_exp_nbjets","",20,0,20);

  return ;
}

