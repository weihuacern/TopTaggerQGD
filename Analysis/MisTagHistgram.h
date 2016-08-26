#include <iostream>

#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"

class MisTagHistgram
{
 public:
  void BookHistgram(const char *);
  TFile *oFile;
  //plot for mistag rate plotting
  TH1D *h_denominator_met, *h_denominator_njets30, *h_denominator_njets50, *h_denominator_mt2, *h_denominator_ht, *h_denominator_mht, *h_denominator_ntopjets, *h_denominator_nbjets;
  TH1D *h_numerator_normal_met, *h_numerator_normal_njets30, *h_numerator_normal_njets50, *h_numerator_normal_mt2, *h_numerator_normal_ht, *h_numerator_normal_mht, *h_numerator_normal_ntopjets, *h_numerator_normal_nbjets;
  TH1D *h_numerator_mctruth_met, *h_numerator_mctruth_njets30, *h_numerator_mctruth_njets50, *h_numerator_mctruth_mt2, *h_numerator_mctruth_ht, *h_numerator_mctruth_mht, *h_numerator_mctruth_ntopjets, *h_numerator_mctruth_nbjets;
  TH1D *h_numerator_qgd_met, *h_numerator_qgd_njets30, *h_numerator_qgd_njets50, *h_numerator_qgd_mt2, *h_numerator_qgd_ht, *h_numerator_qgd_mht, *h_numerator_qgd_ntopjets, *h_numerator_qgd_nbjets;
};
