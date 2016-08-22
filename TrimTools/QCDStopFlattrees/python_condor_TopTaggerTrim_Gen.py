import sys
import glob, os

def PrintCondorHeaderLine():
  print("universe = vanilla")
  print("request_disk   = 50 GB")
  print("request_memory = 1.5 GB")
  print("executable = $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/goTopTaggerTrim.sh")
  print("should_transfer_files = YES")
  print("#when_to_transfer_output = ON_EXIT")
  print ""

def PrintTransferFileLine(directory, sampletype, isfirst, islast):
  if(isfirst):
    sys.stdout.write('transfer_input_files = $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/TopTaggerTrim, $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/NTuple_TopTaggerTrim.py, $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/goTopTaggerTrim.sh, ')
  for dirname, dirnames, filenames in os.walk(directory):
    for filename in filenames:
      if ( sampletype in filename ):
        sys.stdout.write('$ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/QCDStopFlattrees/QGDStudyFile/' + filename + ', ')
      else:
        continue
  if(islast):
    print ""
    print ""

def PrintCondorLogLine():
  print ("Output = $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/QCDStopFlattrees/res/Trim_$(Process).stdout")
  print ("Error = $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/QCDStopFlattrees/res/Trim_$(Process).stderr")
  print ("Log = $ENV(CMSSW_BASE)/src/TopTaggerQGD/TrimTools/QCDStopFlattrees/res/Trim_$(Process).log")
  print ("notify_user = hua.wei@cern.ch")
  print ""

def PrintCondorSubmitLine(directory, sampletype):
  print("#### "+ sampletype +" ####")
  print ""
  for dirname, dirnames, filenames in os.walk(directory):
    for filename in filenames:
      if ( sampletype in filename ):
        print ("arguments = $ENV(CMSSW_BASE) " + filename)
        print ("Queue")
        print ""
      else:
        continue

#d = "/uscms_data/d3/hwei/stop/QCD/CMSSW_8_0_12/src/TopTaggerQGD/TrimTools/QCDStopFlattrees/QGDStudyFile"
d = "/uscms_data/d3/hwei/stop/TopTagger/CMSSW_8_0_12/src/TopTaggerQGD/TrimTools/QCDStopFlattrees/QGDStudyFile"
runtype = sys.argv[1]
print ("#The valid run types for TopTaggerTrim are TopTagger! While the current run type is : " + runtype)

if(runtype == "TopTagger"):
  PrintCondorHeaderLine()
  print("##transfer file list for " + runtype + " samples")
  PrintTransferFileLine(d, "TTJets_", True, False)
  PrintTransferFileLine(d, "ZJetsToNuNu_HT-", False, True)
  PrintCondorLogLine()
  PrintCondorSubmitLine(d, "TTJets_")
  PrintCondorSubmitLine(d, "ZJetsToNuNu_HT-")
else:
  print ("#Invalid run type for TopTaggerTrim! What the fuck is going on ??!!")
