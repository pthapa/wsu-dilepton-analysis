

from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'cosmicMuon2015D_RECOData_analysis'
config.General.workArea = 'crab_cosmic_Muon'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'wsuMuonAnalyzer_cfg.py'

config.Data.inputDataset = '/Cosmics/Commissioning2015-PromptReco-v1/RECO' # difficulty to use DAS
config.Data.inputDBS = 'global'# default value
config.Data.splitting = 'FileBased'# there are other options such as Filebased and EventAwareLumiBased
config.Data.unitsPerJob = 50 # How many events do you want to include in each job ?
#config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions12/8TeV/Prompt/Cert_190456-208686_8TeV_PromptReco_Collisions12_JSON.txt' # Filters according to runRange
#config.Data.runRange = '193093-193999' # 
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())# do not know
config.Data.publication = False
config.Data.publishDataName = 'CRAB3_cosmicMuon2015_Data_analysis'
#config.Options.skipEvent = cms.untracked.vstring('ProductNotFoond')

config.Site.storageSite = 'T3_US_FNALLPC'
