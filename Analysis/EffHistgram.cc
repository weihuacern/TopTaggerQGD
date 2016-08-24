#include "EffHistgram.h"

void EffHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
  h_gen_top_pt  = new TH1D("h_gen_top_pt" ,"",0,10000,10000);
  h_reco_top_pt = new TH1D("h_reco_top_pt","",0,10000,10000);

  return ;
}
