# AllHadronicSUSY
# Quark Gluon Discriminator in TopTagger Study

1.Set CMS Environment:

```
setenv SCRAM_ARCH slc6_amd64_gcc491(export SCRAM_ARCH = slc6_amd64_gcc491)
cmsrel CMSSW_8_0_12
cd CMSSW_8_0_12/src/
cmsenv
```

2.Download source code from github and compile plugins:

```
git cms-init
git cms-merge-topic -u cms-met:CMSSW_8_0_X-METFilterUpdate
git clone -b TestMiniAOD git@github.com:susy2015/recipeAUX.git
git clone git@github.com:susy2015/SusyAnaTools.git
git clone https://github.com/susy2015/QCD.git
scram b -j 10
```


