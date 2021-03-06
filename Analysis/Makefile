IDIR       = .
ODIR       = obj
SDIR       = ../../SusyAnaTools/Tools
TTSDIR     = ../../src/TopTagger/TopTagger/src
TPSDIR     = ../../src/TopTagger/CfgParser/src

#CXX       = ~/.vim/bundle/ClangComplete/bin/cc_args.py g++
CXX        = g++

#CXXFLAGS  += -Iinc -std=c++0x -I${CMSSW_BASE}/src/
#CXXFLAGS  += -I. -std=c++0x -I$(CMSSW_BASE)/src/ -I$(LHAPDF_DATA_PATH)/../../include
#CXXFLAGS  += -I. -std=c++0x -I$(CMSSW_BASE)/src/ -I$(LHAPDF_DATA_PATH)/../../include -I$(CMSSW_RELEASE_BASE)/../../../external/fastjet/3.1.0-odfocd/include -I$(CMSSW_RELEASE_BASE)/src
CXXFLAGS  += -I. -std=c++0x -I$(CMSSW_BASE)/src/ -I$(LHAPDF_DATA_PATH)/../../include -I$(CMSSW_RELEASE_BASE)/src -I$(shell scram tool info fastjet | grep '^INCLUDE' | sed 's/INCLUDE=//')
## Optimization flag
CXXFLAGS += -g #-O3
## Enable the maximun warning
#CXXFLAGS += -Wall -Wextra -Weffc++ -g

## Include ROOT
CXXFLAGS  += $(shell root-config --cflags)

CXXDEPFLAGS = -MMD -MP

LD       = g++
LDFLAGS  =

LIBS         = $(shell root-config --glibs)
MT2LIB       = -L$(CMSSW_BASE)/lib/${SCRAM_ARCH}/ -lrecipeAUXOxbridgeMT2
TopTaggerLIB = -L$(CMSSW_BASE)/lib/${SCRAM_ARCH}/ -lTopTaggerTopTagger -lTopTaggerCfgParser
LHAPDFLIB    = -L$(LHAPDF_DATA_PATH)/../../lib -lLHAPDF

PROGRAMS = tupleTest TopTaggerQGD QGDNtupleValidation TopTaggerQGDPlots

LIBRARIES = TopTagger

all: mkobj sampPyWrap $(PROGRAMS)

mkobj:
	@mkdir -p obj

#code to compile shared library to link samples to python
sampPyWrap: $(ODIR)/samplesModule.so

$(ODIR)/samplesModule.so: $(ODIR)/samplesPyWrap.o $(ODIR)/samplesModulePyWrap.o
	$(CXX) -shared -o $@ $^

$(ODIR)/samplesPyWrap.o: $(SDIR)/samples.cc	$(SDIR)/samples.h
	$(CXX) --std=c++11 -c -fPIC -o $@ $<

$(ODIR)/samplesModulePyWrap.o: $(SDIR)/samplesModule.cc
	$(CXX) --std=c++11 -c -fPIC -o $@ $<

$(ODIR)/%.o : $(SDIR)/%.C
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -o $@ -c $<

$(ODIR)/%.o : $(SDIR)/%.cc
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -o $@ -c $<

$(ODIR)/%.o : $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -o $@ -c $<

$(ODIR)/%.o : $(IDIR)/%.C
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -o $@ -c $<

$(ODIR)/%.o : $(IDIR)/%.cc
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -o $@ -c $<

$(ODIR)/%.o : $(IDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -o $@ -c $<

$(ODIR)/%.o : $(TTSDIR)/%.cc
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -fPIC -o $@ -c $<

$(ODIR)/%.o : $(TTSDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -fPIC -o $@ -c $<

$(ODIR)/%.o : $(TPSDIR)/%.cc
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -fPIC -o $@ -c $<

$(ODIR)/%.o : $(TPSDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEPFLAGS) -fPIC -o $@ -c $<

tupleTest: $(ODIR)/NTupleReader.o $(ODIR)/SATException.o $(ODIR)/PDFUncertainty.o $(ODIR)/searchBins.o $(ODIR)/tupleReadTest.o
	$(LD) $^ $(LIBS) $(MT2LIB) $(LHAPDFLIB) -o $@

TopTaggerQGD: $(ODIR)/TopTaggerQGD.o $(ODIR)/NTupleReader.o $(ODIR)/SATException.o $(ODIR)/TriggerEff.o $(ODIR)/QCDReWeighting.o $(ODIR)/TTFactors.o $(ODIR)/BasicQGDHistgram.o $(ODIR)/EffHistgram.o $(ODIR)/MisTagHistgram.o
	$(LD) $^ $(LIBS) $(MT2LIB) $(TopTaggerLIB) -o $@

QGDNtupleValidation: $(ODIR)/QGDNtupleValidation.o $(ODIR)/NTupleReader.o $(ODIR)/SATException.o $(ODIR)/TriggerEff.o $(ODIR)/QCDReWeighting.o $(ODIR)/EffHistgram.o
	$(LD) $^ $(LIBS) $(MT2LIB) $(TopTaggerLIB) -o $@

TopTaggerQGDPlots: $(ODIR)/TopTaggerQGDPlots.o
	$(LD) $^ $(LIBS)  -o $@
clean:
	rm -f $(ODIR)/*.o $(ODIR)/*.d $(ODIR)/*.so $(PROGRAMS) core 

-include $(ODIR)/*.d
