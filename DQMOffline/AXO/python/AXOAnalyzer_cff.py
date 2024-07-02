import FWCore.ParameterSet.Config as cms

from DQMOffline.AXO.monitorScore_cfi import *

AXOMonitor = cms.sequence(AXOScore)
