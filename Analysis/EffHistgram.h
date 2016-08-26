#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"

class EffHistgram
{
 public:
  void BookHistgram(const char *);
  TFile *oFile;
  //plot for basic check
  TH1D *h_b_ht, *h_b_jetid;
  TH1D *h_b_qglikelihood, *h_b_qglikelihood_qjets, *h_b_qglikelihood_gjets, *h_b_qglikelihood_pjets;
  TH2D *h_b_jetid_qglikelihood;

  TH1D *h_gen_top_pt;
  TH1D *h_reco_top_pt;
};
