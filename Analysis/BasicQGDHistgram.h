#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"

class BasicQGDHistgram
{
 public:
  void BookHistgram(const char *);
  TFile *oFile;
  //plot for basic check
  TH1D *h_b_ht, *h_b_jetid;
  
  TH1D *h_b_qglikelihood, *h_b_qglikelihood_ljets, *h_b_qglikelihood_cjets, *h_b_qglikelihood_bjets, *h_b_qglikelihood_gjets, *h_b_qglikelihood_pjets;
  TH1D *h_b_qgptd, *h_b_qgptd_ljets, *h_b_qgptd_cjets, *h_b_qgptd_bjets, *h_b_qgptd_gjets, *h_b_qgptd_pjets;
  TH1D *h_b_qgaxis2, *h_b_qgaxis2_ljets, *h_b_qgaxis2_cjets, *h_b_qgaxis2_bjets, *h_b_qgaxis2_gjets, *h_b_qgaxis2_pjets;
  TH1D *h_b_qgmult, *h_b_qgmult_ljets, *h_b_qgmult_cjets, *h_b_qgmult_bjets, *h_b_qgmult_gjets, *h_b_qgmult_pjets;

  TH2D *h_b_jetid_qglikelihood;
};
