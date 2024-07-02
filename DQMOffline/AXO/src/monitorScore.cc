// ╔═╗┬ ┬┌┬┐┬ ┬┌─┐┬─┐┌─┐                              
// ╠═╣│ │ │ ├─┤│ │├┬┘└─┐                              
// ╩ ╩└─┘ ┴ ┴ ┴└─┘┴└─└─┘                              
// ╔═╗┬─┐┬┌─┐  ╔╦╗┌─┐┬─┐┌─┐┌┐┌┌─┐                     
// ║╣ ├┬┘││    ║║║│ │├┬┘├┤ ││││ │                     
// ╚═╝┴└─┴└─┘  ╩ ╩└─┘┴└─└─┘┘└┘└─┘                     
// ╦  ┬ ┬┬┌─┌─┐┌─┐  ╔═╗┌┐ ┌─┐┬  ┬┌┐┌┌─┐               
// ║  │ │├┴┐├─┤└─┐  ║╣ ├┴┐├┤ │  │││││ ┬               
// ╩═╝└─┘┴ ┴┴ ┴└─┘  ╚═╝└─┘└─┘┴─┘┴┘└┘└─┘               
// ╔╦╗┬┌─┐┌┬┐┌─┐┬─┐┬┌─┌─┐  ╔═╗┬ ┬┌─┐┬ ┬┌┬┐┬ ┬┬ ┬┬─┐┬ ┬
//  ║║│├─┘ │ ├─┤├┬┘├┴┐│ │  ║  ├─┤│ ││ │ ││├─┤│ │├┬┘└┬┘
// ═╩╝┴┴   ┴ ┴ ┴┴└─┴ ┴└─┘  ╚═╝┴ ┴└─┘└─┘─┴┘┴ ┴└─┘┴└─ ┴ 

#include "DQMOffline/AXO/interface/monitorScore.h"


monitorScore::monitorScore(const edm::ParameterSet& pSet) {
  // initialise parameters:
  parameters = pSet;
  theFolder = parameters.getParameter<string>("folder");
}
monitorScore::~monitorScore() {}

void monitorScore::bookHistograms(DQMStore::IBooker &iBooker, edm::Run const &, edm::EventSetup const &) {
  iBooker.setCurrentFolder(theFolder);
  h_score = iBooker.book1D("scoreHistogram", "Score Distribution", 100, 0, 100);
}

void monitorScore::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  edm::Handle<AXOL1TLScore> scoreHandle;
  iEvent.getByLabel("scoreProducer", scoreHandle);
  if (scoreHandle.isValid()) {
    h_score->Fill(scoreHandle->getAXOScore());
  }
}

// Necessary CMS framework macros
DEFINE_FWK_MODULE(monitorScore);