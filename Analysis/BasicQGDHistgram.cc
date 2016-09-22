#include "BasicQGDHistgram.h"

void BasicQGDHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
 
  h_b_ht = new TH1D("h_b_ht","",100,0,2000);
  h_b_jetid = new TH1D("h_b_jetid","",50,-25,25);
  
  h_b_jeteta = new TH1D("h_b_jeteta","",600,-6,6);
  h_b_jeteta_ljets = new TH1D("h_b_jeteta_ljets","",600,-6,6);
  h_b_jeteta_cjets = new TH1D("h_b_jeteta_cjets","",600,-6,6);
  h_b_jeteta_bjets = new TH1D("h_b_jeteta_bjets","",600,-6,6);
  h_b_jeteta_gjets = new TH1D("h_b_jeteta_gjets","",600,-6,6);
  h_b_jeteta_pjets = new TH1D("h_b_jeteta_pjets","",600,-6,6);

  h_b_jetpt = new TH1D("h_b_jetpt","",500,0,1000);
  h_b_jetpt_ljets = new TH1D("h_b_jetpt_ljets","",500,0,1000);
  h_b_jetpt_cjets = new TH1D("h_b_jetpt_cjets","",500,0,1000);
  h_b_jetpt_bjets = new TH1D("h_b_jetpt_bjets","",500,0,1000);
  h_b_jetpt_gjets = new TH1D("h_b_jetpt_gjets","",500,0,1000);
  h_b_jetpt_pjets = new TH1D("h_b_jetpt_pjets","",500,0,1000);

  h_b_qglikelihood = new TH1D("h_b_qglikelihood","",500,-3,2);
  h_b_qglikelihood_ljets = new TH1D("h_b_qglikelihood_ljets","",500,-3,2);
  h_b_qglikelihood_cjets = new TH1D("h_b_qglikelihood_cjets","",500,-3,2);
  h_b_qglikelihood_bjets = new TH1D("h_b_qglikelihood_bjets","",500,-3,2);
  h_b_qglikelihood_gjets = new TH1D("h_b_qglikelihood_gjets","",500,-3,2);
  h_b_qglikelihood_pjets = new TH1D("h_b_qglikelihood_pjets","",500,-3,2);
  
  h_b_qgptd = new TH1D("h_b_qgptd","",100,0,2);
  h_b_qgptd_ljets = new TH1D("h_b_qgptd_ljets","",200,0,2);
  h_b_qgptd_cjets = new TH1D("h_b_qgptd_cjets","",200,0,2);
  h_b_qgptd_bjets = new TH1D("h_b_qgptd_bjets","",200,0,2);
  h_b_qgptd_gjets = new TH1D("h_b_qgptd_gjets","",200,0,2);
  h_b_qgptd_pjets = new TH1D("h_b_qgptd_pjets","",200,0,2);

  h_b_qgaxis2 = new TH1D("h_b_qgaxis2","",50,0,1);
  h_b_qgaxis2_ljets = new TH1D("h_b_qgaxis2_ljets","",200,0,1);
  h_b_qgaxis2_cjets = new TH1D("h_b_qgaxis2_cjets","",200,0,1);
  h_b_qgaxis2_bjets = new TH1D("h_b_qgaxis2_bjets","",200,0,1);
  h_b_qgaxis2_gjets = new TH1D("h_b_qgaxis2_gjets","",200,0,1);
  h_b_qgaxis2_pjets = new TH1D("h_b_qgaxis2_pjets","",200,0,1);

  h_b_qgmult = new TH1D("h_b_qgmult","",50,0,50);
  h_b_qgmult_ljets = new TH1D("h_b_qgmult_ljets","",50,0,50);
  h_b_qgmult_cjets = new TH1D("h_b_qgmult_cjets","",50,0,50);
  h_b_qgmult_bjets = new TH1D("h_b_qgmult_bjets","",50,0,50);
  h_b_qgmult_gjets = new TH1D("h_b_qgmult_gjets","",50,0,50);
  h_b_qgmult_pjets = new TH1D("h_b_qgmult_pjets","",50,0,50);

  for( Int_t i = 0 ; i < JETSETA_BINS ; i++ )
  {
    h_b_qglikelihoodjetetabin[i] = new TH1D( ("h_b_qglikelihoodjetetabin" + std::to_string(i)).c_str(),"",500,-3,2);
    h_b_qgptdjetetabin[i] = new TH1D( ("h_b_qgptdjetetabin" + std::to_string(i)).c_str(),"",200,0,2);
    h_b_qgaxis2jetetabin[i] = new TH1D( ("h_b_qgaxis2jetetabin" + std::to_string(i)).c_str(),"",200,0,1);
    h_b_qgmultjetetabin[i] = new TH1D( ("h_b_qgmultjetetabin" + std::to_string(i)).c_str(),"",50,0,50); 
  }
  for( Int_t i = 0 ; i < JETSPT_BINS ; i++ )
  {
    h_b_qglikelihoodjetptbin[i] = new TH1D( ("h_b_qglikelihoodjetptbin" + std::to_string(i)).c_str(),"",500,-3,2);
    h_b_qgptdjetptbin[i] = new TH1D( ("h_b_qgptdjetptbin" + std::to_string(i)).c_str(),"",200,0,2);
    h_b_qgaxis2jetptbin[i] = new TH1D( ("h_b_qgaxis2jetptbin" + std::to_string(i)).c_str(),"",200,0,1);
    h_b_qgmultjetptbin[i] = new TH1D( ("h_b_qgmultjetptbin" + std::to_string(i)).c_str(),"",50,0,50);
  }
  for( Int_t i = 0 ; i < JETSETA_BINS ; i++ )
  {
    for( Int_t j = 0 ; j < JETSPT_BINS ; j++ )
    {
      h_b_qglikelihoodjetetaptbin[i][j] = new TH1D( ("h_b_qglikelihoodjetetaptbin" + std::to_string(i) + std::to_string(j)).c_str(),"",500,-3,2);
      h_b_qgptdjetetaptbin[i][j] = new TH1D( ("h_b_qgptdjetetaptbin" + std::to_string(i) + std::to_string(j)).c_str(),"",200,0,2);
      h_b_qgaxis2jetetaptbin[i][j] = new TH1D( ("h_b_qgaxis2jetetaptbin" + std::to_string(i) + std::to_string(j)).c_str(),"",200,0,1);
      h_b_qgmultjetetaptbin[i][j] = new TH1D( ("h_b_qgmultjetetaptbin" + std::to_string(i) + std::to_string(j)).c_str(),"",50,0,50);
    }
  }


  h_b_jetid_qglikelihood = new TH2D("h_b_jetid_qglikelihood","",50,-25,25,50,-3,2);
 
  return ;
}
