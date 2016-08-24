import glob, os, sys

d_hadd_source = "/store/group/lpcsusyhad/hua/Skimmed_2015Nov15"
d_final_target = "/store/group/lpcsusyhad/hua/Skimmed_2015Nov15/TopTagger_ICHEP2016_v8"
MGM = "root://cmseos.fnal.gov/"

sample_tag_list_TopTaggerTrim = [
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_TTJets_Inc_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-400To600_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-400To600_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-600To800_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-800To1200_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-1200To2500_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-1200To2500_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-2500ToInf_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_TTJets_SingleLeptFromT_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_TTJets_SingleLeptFromT_ext1_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_TTJets_SingleLeptFromTbar_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_TTJets_SingleLeptFromTbar_ext1_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_TTJets_DiLept_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_TTJets_DiLept_ext1_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-400To600_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-400To600_ext1_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-600To800_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-800To1200_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-800To1200_ext1_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-1200To2500_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-1200To2500_ext1_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_WJetsToLNu_HT-2500ToInf_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_ST_tW_top_5f_inclusiveDecays_stopFlatNtuples_",
#"DeepTrimmd_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_ST_tW_antitop_5f_inclusiveDecays_stopFlatNtuples_",
                           ]

#example of sample tag: SSTrimmed_SMS-T2tt_mStop-850_mLSP-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_stopFlatNtuples_, always end with "_"
sample_tag = sys.argv[1]

sample_tag_list = []

if(sample_tag == 'TopTagger') :
  sample_tag_list = sample_tag_list_TopTaggerTrim
else:
  print "wrong run type!"

for tag in sample_tag_list :
  #hadd
  cmd = 'hadd ' + tag[:-1] + '.root `xrdfsls -u ' + d_hadd_source + ' | grep \'' + tag + '\'`'
  print(cmd)
  #os.system(cmd)
  cmd = 'xrdcp ' + tag[:-1] + '.root ' + MGM + d_final_target
  print(cmd)

  #xrdcp root://cmseos.fnal.gov//store/user/jjesus/EOSFile.txt \? root://cmseos.fnal.gov//store/user/jjesus/EOSFile1.txt
  #cmd = 'xrdcp ' + MGM + d_hadd_source + '/' + tag[:-1] + '.root ' + MGM + d_final_target + '/' + tag[:-1] + '.root' 
  #print(cmd)
  #cmd = 'eosrm ' + d_hadd_source + '/' + tag[:-1] + '.root'
  #print(cmd)

