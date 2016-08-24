#include "TFile.h"
#include "TH1D.h"

class EffHistgram
{
 public:
  void BookHistgram(const char *);
  TFile *oFile;
  //closure plots on different variables and search bins
  TH1D *h_gen_top_pt;
  TH1D *h_reco_top_pt;
};
