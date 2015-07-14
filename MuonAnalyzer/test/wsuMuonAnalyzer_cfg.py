import FWCore.ParameterSet.Config as cms

process = cms.Process("MuonAnalysis")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        # Input file
        'file:///afs/cern.ch/user/p/pthapa/work/CMSSW_7_4_1/src/4.22_RunCosmics2011A+RunCosmics2011A+RECOCOSD+ALCACOSD+SKIMCOSD+HARVESTDC/step2.root'
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
    fileName = cms.string('CosmicMuonAnalysis_2012D_struct.root')
)
process.p = cms.Path(
    process.analysis1Leg
    +process.analysisLHC
    +process.analysisSplit
    +process.analysisMuons
    +process.analysisT0Corr
    +process.analysisBHECOnly
    +process.analysisNoRPC
    )
