import glob, os, sys

d_hadd_source = "/store/group/lpcsusyhad/hua/Skimmed_2015Nov15"
d_final_target = "/store/group/lpcsusyhad/hua/Skimmed_2015Nov15/TopTagger_ICHEP2016_v8_MET150_NJets_BJets_Filter"
MGM = "root://cmseos.fnal.gov/"

sample_tag_list_TopTaggerTrim = [
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_TTJets_Inc_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-400To600_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-400To600_ext_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-600To800_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-800To1200_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-1200To2500_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-1200To2500_ext1_stopFlatNtuples_",
#"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_ZJetsToNuNu_HT-2500ToInf_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT100to200_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT200to300_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT300to500_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT500to700_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT700to1000_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT1000to1500_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT1500to2000_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT2000toInf_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT200to300_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT300to500_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT500to700_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT700to1000_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT1000to1500_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT1500to2000_ext1_stopFlatNtuples_",
"TopTaggerTrimmed_Spring16_80X_Jul_2016_Ntp_v8p0_new_JEC_new_muonID_top_up_FINAL_QCD_HT2000toInf_ext1_stopFlatNtuples_",
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
  #os.system(cmd)
  cmd = 'rm ' + tag[:-1] + '.root '
  print(cmd)
  #os.system(cmd)
  #xrdcp root://cmseos.fnal.gov//store/user/jjesus/EOSFile.txt \? root://cmseos.fnal.gov//store/user/jjesus/EOSFile1.txt
  #cmd = 'xrdcp ' + MGM + d_hadd_source + '/' + tag[:-1] + '.root ' + MGM + d_final_target + '/' + tag[:-1] + '.root' 
  #print(cmd)
  #cmd = 'eosrm ' + d_hadd_source + '/' + tag[:-1] + '.root'
  #print(cmd)

