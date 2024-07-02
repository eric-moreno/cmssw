#ifndef monitorScore_H
#define monitorScore_H

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

#include <memory>
#include <fstream>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/DQMEDAnalyzer.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "DataFormats/L1TGlobal/interface/AXOL1TLScore.h"

class monitorScore : public DQMEDAnalyzer {
private:
  MonitorElement* h_score; // Histogram for score distribution
  sdt::string theFolder; // Folder for the histograms
  

protected:
  void bookHistograms(DQMStore::IBooker &iBooker, edm::Run const &, edm::EventSetup const &) override {
    iBooker.setCurrentFolder("Your/Path/Here");
    h_score = iBooker.book1D("scoreHistogram", "Score Distribution", 100, 0, 100);
  }

  void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) override {
    edm::Handle<AXOL1TLScore> scoreHandle;
    iEvent.getByLabel("scoreProducer", scoreHandle);
    if (scoreHandle.isValid()) {
      h_score->Fill(scoreHandle->getScore());
    }
  }
};

// Necessary CMS framework macros
DEFINE_FWK_MODULE(monitorScore);
