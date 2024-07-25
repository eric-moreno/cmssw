import FWCore.ParameterSet.Config as cms
from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer

AXOScore = DQMEDAnalyzer('monitorScore', 
                         folder = cms.string('AXO'),
                         scoreProducer = cms.untracked.InputTag('axoScoreProducer:AXOScore')
                        )