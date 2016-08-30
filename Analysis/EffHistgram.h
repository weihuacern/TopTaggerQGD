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
  TH1D *h_b_qgptd, *h_b_qgptd_qjets, *h_b_qgptd_gjets, *h_b_qgptd_pjets;
  TH1D *h_b_qgaxis2, *h_b_qgaxis2_qjets, *h_b_qgaxis2_gjets, *h_b_qgaxis2_pjets;
  TH1D *h_b_qgmult, *h_b_qgmult_qjets, *h_b_qgmult_gjets, *h_b_qgmult_pjets;

  TH2D *h_b_jetid_qglikelihood;

  TH1D *h_gen_top_pt;
  TH1D *h_reco_top_pt;

  TH1D *h_denominator_gentoppt;
  TH1D *h_numerator_normal_gentoppt;
  TH1D *h_numerator_mctruth_gentoppt;
  TH1D *h_numerator_qgd_gentoppt;

  TH1D *h_denominator_met, *h_denominator_njets30, *h_denominator_njets50, *h_denominator_ht, *h_denominator_mht, *h_denominator_nbotjets;
  TH1D *h_numerator_normal_met, *h_numerator_normal_njets30, *h_numerator_normal_njets50, *h_numerator_normal_ht, *h_numerator_normal_mht, *h_numerator_normal_nbotjets;
  TH1D *h_numerator_mctruth_met, *h_numerator_mctruth_njets30, *h_numerator_mctruth_njets50, *h_numerator_mctruth_ht, *h_numerator_mctruth_mht, *h_numerator_mctruth_nbotjets;
  TH1D *h_numerator_qgd_met, *h_numerator_qgd_njets30, *h_numerator_qgd_njets50, *h_numerator_qgd_ht, *h_numerator_qgd_mht, *h_numerator_qgd_nbotjets;
};
