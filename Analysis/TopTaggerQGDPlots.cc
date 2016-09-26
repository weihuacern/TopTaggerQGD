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
  std::vector<Plotting_Parameter> myPlotting_Paramete = 
  { 
    //QGD checking plots
    {"_b_jeteta_"      , "Jet Eta"     ,-6.0, 6.0 }, 
    {"_b_jetpt_"       , "Jet Pt"      ,0   , 400 }, 
    {"_b_qglikelihood_", "QGLikelihood",0   , 1   },
    {"_b_qgptd_"       , "QGPtD"       ,0   , 1.1 }, 
    {"_b_qgaxis2_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmult_"      , "QGMult"      ,0   , 50  },  

    {"_b_qglikelihoodjetetabin0_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetetabin0_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetetabin0_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetetabin0_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetetabin1_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetetabin1_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetetabin1_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetetabin1_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetetabin2_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetetabin2_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetetabin2_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetetabin2_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetetabin3_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetetabin3_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetetabin3_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetetabin3_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetetabin4_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetetabin4_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetetabin4_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetetabin4_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetetabin5_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetetabin5_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetetabin5_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetetabin5_"      , "QGMult"      ,0   , 50  },

    {"_b_qglikelihoodjetptbin0_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetptbin0_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetptbin0_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetptbin0_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetptbin1_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetptbin1_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetptbin1_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetptbin1_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetptbin2_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetptbin2_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetptbin2_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetptbin2_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetptbin3_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetptbin3_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetptbin3_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetptbin3_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetptbin4_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetptbin4_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetptbin4_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetptbin4_"      , "QGMult"      ,0   , 50  },
    {"_b_qglikelihoodjetptbin5_", "QGLikelihood",0   , 1   },
    {"_b_qgptdjetptbin5_"       , "QGPtD"       ,0   , 1.1 },
    {"_b_qgaxis2jetptbin5_"     , "QGAxis2"     ,0   , 0.2 },
    {"_b_qgmultjetptbin5_"      , "QGMult"      ,0   , 50  },
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
  /*
  myTopTaggerQGDPlots.EffPlots("_gentoppt", "GenTop Pt[GeV]"       , 0  , 1000);
  myTopTaggerQGDPlots.EffPlots("_met"     , "MET[GeV]"             , 150, 1000);
  myTopTaggerQGDPlots.EffPlots("_njets30" , "Number of 30 GeV jets", 4  , 17);
  myTopTaggerQGDPlots.EffPlots("_njets50" , "Number of 50 GeV jets", 2  , 15);
  myTopTaggerQGDPlots.EffPlots("_ht"      , "HT[GeV]"              , 500, 3000);
  myTopTaggerQGDPlots.EffPlots("_mht"     , "MHT[GeV]"             , 0  , 1000);
  myTopTaggerQGDPlots.EffPlots("_nbotjets", "Number of B Jets"     , 1  , 8);
  myTopTaggerQGDPlots.MisTagRatePlots("_met"     , "MET[GeV]"             , 150, 1000);
  myTopTaggerQGDPlots.MisTagRatePlots("_njets30" , "Number of 30 GeV jets", 4  , 17);
  myTopTaggerQGDPlots.MisTagRatePlots("_njets50" , "Number of 50 GeV jets", 2  , 15);
  myTopTaggerQGDPlots.MisTagRatePlots("_ht"      , "HT[GeV]"              , 500, 3000);
  myTopTaggerQGDPlots.MisTagRatePlots("_mht"     , "MHT[GeV]"             , 0  , 1000);
  myTopTaggerQGDPlots.MisTagRatePlots("_nbotjets", "Number of B Jets"     , 1  , 8);
  */
  return 0;
}

