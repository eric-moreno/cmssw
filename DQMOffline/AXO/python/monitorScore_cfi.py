import FWCore.ParameterSet.Config as cms

from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer

AXOScore = DQMEDAnalyzer('monitorScore', 
                        folder = cms.string('MyMonitoringFolder')
                        )
#AXOScore = DQMEDAnalyzer()
