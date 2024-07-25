#include "DQMOffline/AXO/interface/monitorScore.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DataFormats/L1TGlobal/interface/AXOL1TLScore.h"

#include <string>
#include <TMath.h>

using namespace std;
using namespace edm;

monitorScore::monitorScore(const edm::ParameterSet& pSet)
  : theFolder(pSet.getParameter<std::string>("folder")),
    parameters(pSet),
    scoreToken_(consumes<AXOL1TLScoreBxCollection>(pSet.getUntrackedParameter<edm::InputTag>("scoreProducer")))
{
}

monitorScore::~monitorScore() {
  customEndJob();
}

void monitorScore::bookHistograms(DQMStore::IBooker &iBooker, edm::Run const &, edm::EventSetup const &) {
  iBooker.setCurrentFolder(theFolder);
  h_score = iBooker.book1D("scoreHistogram", "Score Distribution", 100, 0, 1000);
}

void monitorScore::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  edm::Handle<AXOL1TLScoreBxCollection> scoreHandle;
  iEvent.getByToken(scoreToken_, scoreHandle);

  if (scoreHandle.isValid()) {
    for (const auto& score : *scoreHandle) {
      float scoreValue = score.getAXOScore();
      h_score->Fill(scoreValue);
    }
  } else {
    edm::LogWarning("monitorScore") << "Score handle invalid.";
  }
}

void monitorScore::customEndJob() {
  if (h_score) {
    TH1F* hist = h_score->getTH1F();
    if (hist) {
      for (int i = 1; i <= hist->GetNbinsX(); ++i) {
        edm::LogInfo("monitorScore") << "Bin " << i << ": " << hist->GetBinContent(i);
      }
    }
  }
}

DEFINE_FWK_MODULE(monitorScore);