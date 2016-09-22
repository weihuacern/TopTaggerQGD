#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"

#include "ConstantsSnippet.h"

class BasicQGDHistgram
{
 public:
  void BookHistgram(const char *);
  TFile *oFile;
  //plot for basic check
  TH1D *h_b_ht, *h_b_jetid;

  TH1D *h_b_jeteta, *h_b_jeteta_ljets, *h_b_jeteta_cjets, *h_b_jeteta_bjets, *h_b_jeteta_gjets, *h_b_jeteta_pjets;
  TH1D *h_b_jetpt, *h_b_jetpt_ljets, *h_b_jetpt_cjets, *h_b_jetpt_bjets, *h_b_jetpt_gjets, *h_b_jetpt_pjets;
  
  TH1D *h_b_qglikelihood, *h_b_qglikelihood_ljets, *h_b_qglikelihood_cjets, *h_b_qglikelihood_bjets, *h_b_qglikelihood_gjets, *h_b_qglikelihood_pjets;
  TH1D *h_b_qgptd, *h_b_qgptd_ljets, *h_b_qgptd_cjets, *h_b_qgptd_bjets, *h_b_qgptd_gjets, *h_b_qgptd_pjets;
  TH1D *h_b_qgaxis2, *h_b_qgaxis2_ljets, *h_b_qgaxis2_cjets, *h_b_qgaxis2_bjets, *h_b_qgaxis2_gjets, *h_b_qgaxis2_pjets;
  TH1D *h_b_qgmult, *h_b_qgmult_ljets, *h_b_qgmult_cjets, *h_b_qgmult_bjets, *h_b_qgmult_gjets, *h_b_qgmult_pjets;

  TH1D *h_b_qglikelihoodjetetabin[JETSETA_BINS], *h_b_qglikelihoodjetptbin[JETSPT_BINS];
  TH1D *h_b_qgptdjetetabin[JETSETA_BINS], *h_b_qgptdjetptbin[JETSPT_BINS];
  TH1D *h_b_qgaxis2jetetabin[JETSETA_BINS], *h_b_qgaxis2jetptbin[JETSPT_BINS];
  TH1D *h_b_qgmultjetetabin[JETSETA_BINS], *h_b_qgmultjetptbin[JETSPT_BINS];

  TH1D *h_b_qglikelihoodjetetaptbin[JETSETA_BINS][JETSPT_BINS];
  TH1D *h_b_qgptdjetetaptbin[JETSETA_BINS][JETSPT_BINS];
  TH1D *h_b_qgaxis2jetetaptbin[JETSETA_BINS][JETSPT_BINS];
  TH1D *h_b_qgmultjetetaptbin[JETSETA_BINS][JETSPT_BINS];

  TH2D *h_b_jetid_qglikelihood;
};
