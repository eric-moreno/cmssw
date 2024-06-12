
import FWCore.ParameterSet.Config as cms

L1AXOTreeProducer = cms.EDAnalyzer("L1AXOTreeProducer",
                                   axoscoreToken    = cms.untracked.InputTag("L1TGlobalProducer") ##need to add token for score
)

def L1AXOScoreEmu(process):
    process.L1AXOTreeProducer = L1AXOTreeProducer.clone()
    process.L1AXOScoreEmu = cms.Path(process.L1AXOTreeProducer)
    process.schedule.append(process.L1AXOScoreEmu)
    return process
