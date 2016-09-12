#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>

#include "TFile.h"
#include "TList.h"
#include "TString.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TStyle.h"

#include "TopTaggerQGDPlots.h"

int main(int argc, char* argv[])
{

  if (argc < 1)
  {
    std::cerr <<"Please give at least 1 argument " << "TargetDirName" << std::endl;
    std::cerr <<" Valid configurations are " << std::endl;
    std::cerr <<" ./TopTaggerQGDPlots TopTaggerQGD20160830" << std::endl;
    return -1;
  }

  std::string DirName = argv[1];

  TopTaggerQGDPlots myTopTaggerQGDPlots;
  myTopTaggerQGDPlots.Initialization(DirName);
  //myTopTaggerQGDPlots.PrintPlotsName();
  //initialize the closure plots parameter we want to investigate
  /*
  std::vector<Plotting_Parameter> myPlotting_Paramete = 
  { 
    //QCD closure plots
    {"_b_qglikelihood_", "QGLikelihood",0   , 1   },
    {"_b_qgptd_"       , "QGPtD"       ,0   , 1.1 }, 
    {"_b_qgaxis2_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmult_"      , "QGMult"      ,0   , 50  },  
  };

  std::vector<Plotting_Parameter>::iterator iter_p;
  for( iter_p = myPlotting_Paramete.begin() ; iter_p != myPlotting_Paramete.end() ; iter_p ++)
  {
    myTopTaggerQGDPlots.JetsComparePlots(
                                         (*iter_p).hist_tag,
                                         (*iter_p).XTitle,
                                         (*iter_p).min,
                                         (*iter_p).max 
                                        );
  }
  */
  /*
  myTopTaggerQGDPlots.EffPlots("_gentoppt", "GenTop Pt[GeV]"       , 0  , 1000);
  myTopTaggerQGDPlots.EffPlots("_met"     , "MET[GeV]"             , 150, 1000);
  myTopTaggerQGDPlots.EffPlots("_njets30" , "Number of 30 GeV jets", 4  , 17);
  myTopTaggerQGDPlots.EffPlots("_njets50" , "Number of 50 GeV jets", 2  , 15);
  myTopTaggerQGDPlots.EffPlots("_ht"      , "HT[GeV]"              , 500, 3000);
  myTopTaggerQGDPlots.EffPlots("_mht"     , "MHT[GeV]"             , 0  , 1000);
  myTopTaggerQGDPlots.EffPlots("_nbotjets", "Number of B Jets"     , 1  , 8);
	*/
  myTopTaggerQGDPlots.MisTagRatePlots("_met"     , "MET[GeV]"             , 150, 1000);
  myTopTaggerQGDPlots.MisTagRatePlots("_njets30" , "Number of 30 GeV jets", 4  , 17);
  myTopTaggerQGDPlots.MisTagRatePlots("_njets50" , "Number of 50 GeV jets", 2  , 15);
  myTopTaggerQGDPlots.MisTagRatePlots("_ht"      , "HT[GeV]"              , 500, 3000);
  myTopTaggerQGDPlots.MisTagRatePlots("_mht"     , "MHT[GeV]"             , 0  , 1000);
  myTopTaggerQGDPlots.MisTagRatePlots("_nbotjets", "Number of B Jets"     , 1  , 8);
  return 0;
}

