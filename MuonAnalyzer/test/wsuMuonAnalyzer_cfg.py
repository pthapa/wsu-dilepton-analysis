import FWCore.ParameterSet.Config as cms

process = cms.Process("MuonAnalysis")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 25000

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        # Input file
        #'file:///afs/cern.ch/user/p/pthapa/work/CMSSW_7_4_1/src/4.22_RunCosmics2011A+RunCosmics2011A+RECOCOSD+ALCACOSD+SKIMCOSD+HARVESTDC/step2.root'

       # These following files are has good number of events
       # '/store/data/Run2015B/Cosmics/AOD/PromptReco-v1/000/250/974/00000/947B4ABB-B025-E511-BCD3-02163E0120B0.root',
       # '/store/data/Run2015B/Cosmics/AOD/PromptReco-v1/000/250/974/00000/E8D894BF-B025-E511-B64E-02163E011AA5.root',
       # '/store/data/Run2015B/Cosmics/AOD/PromptReco-v1/000/251/033/00000/C651EC45-2B26-E511-ACAD-02163E013674.root',
       # '/store/data/Run2015B/Cosmics/AOD/PromptReco-v1/000/251/035/00000/38A4B55B-3226-E511-B301-02163E014770.root',
       # '/store/data/Run2015B/Cosmics/AOD/PromptReco-v1/000/251/035/00000/4CC8305D-3226-E511-9D4C-02163E013992.root',

        ###8006
        "/store/data/Commissioning2015/Cosmics/AOD/PromptReco-v1/000/232/956/00000/F6F5A9CD-ADA8-E411-AEE5-02163E0123FB.root",
        "/store/data/Commissioning2015/Cosmics/AOD/PromptReco-v1/000/238/081/00000/1021BECA-13CE-E411-99F7-02163E01297F.root",
        "/store/data/Commissioning2015/Cosmics/AOD/PromptReco-v1/000/237/566/00000/CE89D9A3-A7C9-E411-A254-02163E012464.root",# Error number 8006
        
        ###8023
       # "/store/data/Commissioning2015/Cosmics/AOD/PromptReco-v1/000/246/679/00000/1A7B280E-D40A-E511-9899-02163E013982.root",
       # "/store/data/Commissioning2015/Cosmics/AOD/PromptReco-v1/000/234/029/00000/684908FA-3DB4-E411-9C39-02163E012B7B.root",
       # "/store/data/Commissioning2015/Cosmics/AOD/PromptReco-v1/000/236/545/00000/B03E8EB5-14C3-E411-BC17-02163E012078.root",# Error number 8023

    )
)


process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)

from WSUDiLeptons.MuonAnalyzer.wsuMuonAnalyzer_cfi import muonAnalysis


process.analysis1Leg = muonAnalysis.clone(
    muonSrc = cms.InputTag("muons1Leg")
    )
process.analysisLHC = muonAnalysis.clone(
    muonSrc = cms.InputTag("lhcSTAMuons")
)
process.analysisSplit = muonAnalysis.clone(
    muonSrc = cms.InputTag("splitMuons")
)
process.analysisMuons = muonAnalysis.clone(
    muonSrc = cms.InputTag("muons")
)
process.analysisT0Corr = muonAnalysis.clone(
    muonSrc = cms.InputTag("muonsWitht0Correction")
)
process.analysisBHECOnly = muonAnalysis.clone(
    muonSrc = cms.InputTag("muonsBeamHaloEndCapsOnly")
)
process.analysisNoRPC = muonAnalysis.clone(
    muonSrc = cms.InputTag("muonsNoRPC")
)


process.TFileService = cms.Service("TFileService",
# outputfile
    fileName = cms.string('CosmicMuonAnalysis_Run2015B_struct.root')
)
process.p = cms.Path(
  process.analysisMuons
    # process.analysis1Leg
    # +process.analysisLHC
    # +process.analysisSplit
   
    # +process.analysisT0Corr
    # +process.analysisBHECOnly
    # +process.analysisNoRPC
    )
