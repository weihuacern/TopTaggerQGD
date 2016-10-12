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
  TH1D *h_b_jetcharge, *h_b_jetcharge_ljets, *h_b_jetcharge_cjets, *h_b_jetcharge_bjets, *h_b_jetcharge_gjets, *h_b_jetcharge_pjets;
  
  TH1D *h_b_qglikelihood, *h_b_qglikelihood_ljets, *h_b_qglikelihood_cjets, *h_b_qglikelihood_bjets, *h_b_qglikelihood_gjets, *h_b_qglikelihood_pjets;
  TH1D *h_b_qgptd, *h_b_qgptd_ljets, *h_b_qgptd_cjets, *h_b_qgptd_bjets, *h_b_qgptd_gjets, *h_b_qgptd_pjets;
  TH1D *h_b_qgaxis2, *h_b_qgaxis2_ljets, *h_b_qgaxis2_cjets, *h_b_qgaxis2_bjets, *h_b_qgaxis2_gjets, *h_b_qgaxis2_pjets;
  TH1D *h_b_qgmult, *h_b_qgmult_ljets, *h_b_qgmult_cjets, *h_b_qgmult_bjets, *h_b_qgmult_gjets, *h_b_qgmult_pjets;

  TH1D *h_b_qglikelihoodjetetabin[JETSETA_BINS], *h_b_qglikelihoodjetetabin_ljets[JETSETA_BINS], *h_b_qglikelihoodjetetabin_cjets[JETSETA_BINS], *h_b_qglikelihoodjetetabin_bjets[JETSETA_BINS], *h_b_qglikelihoodjetetabin_gjets[JETSETA_BINS], *h_b_qglikelihoodjetetabin_pjets[JETSETA_BINS];
  TH1D *h_b_qgptdjetetabin[JETSETA_BINS], *h_b_qgptdjetetabin_ljets[JETSETA_BINS], *h_b_qgptdjetetabin_cjets[JETSETA_BINS], *h_b_qgptdjetetabin_bjets[JETSETA_BINS], *h_b_qgptdjetetabin_gjets[JETSETA_BINS], *h_b_qgptdjetetabin_pjets[JETSETA_BINS];
  TH1D *h_b_qgaxis2jetetabin[JETSETA_BINS], *h_b_qgaxis2jetetabin_ljets[JETSETA_BINS], *h_b_qgaxis2jetetabin_cjets[JETSETA_BINS], *h_b_qgaxis2jetetabin_bjets[JETSETA_BINS], *h_b_qgaxis2jetetabin_gjets[JETSETA_BINS], *h_b_qgaxis2jetetabin_pjets[JETSETA_BINS];
  TH1D *h_b_qgmultjetetabin[JETSETA_BINS], *h_b_qgmultjetetabin_ljets[JETSETA_BINS], *h_b_qgmultjetetabin_cjets[JETSETA_BINS], *h_b_qgmultjetetabin_bjets[JETSETA_BINS], *h_b_qgmultjetetabin_gjets[JETSETA_BINS], *h_b_qgmultjetetabin_pjets[JETSETA_BINS];
  
  TH1D *h_b_qglikelihoodjetptbin[JETSPT_BINS], *h_b_qglikelihoodjetptbin_ljets[JETSPT_BINS], *h_b_qglikelihoodjetptbin_cjets[JETSPT_BINS], *h_b_qglikelihoodjetptbin_bjets[JETSPT_BINS], *h_b_qglikelihoodjetptbin_gjets[JETSPT_BINS], *h_b_qglikelihoodjetptbin_pjets[JETSPT_BINS];
  TH1D *h_b_qgptdjetptbin[JETSPT_BINS], *h_b_qgptdjetptbin_ljets[JETSPT_BINS], *h_b_qgptdjetptbin_cjets[JETSPT_BINS], *h_b_qgptdjetptbin_bjets[JETSPT_BINS], *h_b_qgptdjetptbin_gjets[JETSPT_BINS], *h_b_qgptdjetptbin_pjets[JETSPT_BINS];
  TH1D *h_b_qgaxis2jetptbin[JETSPT_BINS], *h_b_qgaxis2jetptbin_ljets[JETSPT_BINS], *h_b_qgaxis2jetptbin_cjets[JETSPT_BINS], *h_b_qgaxis2jetptbin_bjets[JETSPT_BINS], *h_b_qgaxis2jetptbin_gjets[JETSPT_BINS], *h_b_qgaxis2jetptbin_pjets[JETSPT_BINS];
  TH1D *h_b_qgmultjetptbin[JETSPT_BINS], *h_b_qgmultjetptbin_ljets[JETSPT_BINS], *h_b_qgmultjetptbin_cjets[JETSPT_BINS], *h_b_qgmultjetptbin_bjets[JETSPT_BINS], *h_b_qgmultjetptbin_gjets[JETSPT_BINS], *h_b_qgmultjetptbin_pjets[JETSPT_BINS];

  TH1D *h_b_qglikelihoodjetetaptbin[JETSETA_BINS][JETSPT_BINS], *h_b_qglikelihoodjetetaptbin_ljets[JETSETA_BINS][JETSPT_BINS], *h_b_qglikelihoodjetetaptbin_cjets[JETSETA_BINS][JETSPT_BINS], *h_b_qglikelihoodjetetaptbin_bjets[JETSETA_BINS][JETSPT_BINS], *h_b_qglikelihoodjetetaptbin_gjets[JETSETA_BINS][JETSPT_BINS], *h_b_qglikelihoodjetetaptbin_pjets[JETSETA_BINS][JETSPT_BINS];
  TH1D *h_b_qgptdjetetaptbin[JETSETA_BINS][JETSPT_BINS], *h_b_qgptdjetetaptbin_ljets[JETSETA_BINS][JETSPT_BINS], *h_b_qgptdjetetaptbin_cjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgptdjetetaptbin_bjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgptdjetetaptbin_gjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgptdjetetaptbin_pjets[JETSETA_BINS][JETSPT_BINS];
  TH1D *h_b_qgaxis2jetetaptbin[JETSETA_BINS][JETSPT_BINS], *h_b_qgaxis2jetetaptbin_ljets[JETSETA_BINS][JETSPT_BINS], *h_b_qgaxis2jetetaptbin_cjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgaxis2jetetaptbin_bjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgaxis2jetetaptbin_gjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgaxis2jetetaptbin_pjets[JETSETA_BINS][JETSPT_BINS];
  TH1D *h_b_qgmultjetetaptbin[JETSETA_BINS][JETSPT_BINS], *h_b_qgmultjetetaptbin_ljets[JETSETA_BINS][JETSPT_BINS], *h_b_qgmultjetetaptbin_cjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgmultjetetaptbin_bjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgmultjetetaptbin_gjets[JETSETA_BINS][JETSPT_BINS], *h_b_qgmultjetetaptbin_pjets[JETSETA_BINS][JETSPT_BINS];

  TH2D *h_b_jetid_qglikelihood;
};
