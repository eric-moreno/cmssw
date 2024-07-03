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

#ifndef monitorScore_H
#define monitorScore_H

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
#include "DataFormats/Common/interface/Handle.h"

class monitorScore : public DQMEDAnalyzer {
public:
  monitorScore(const edm::ParameterSet &pset);
  ~monitorScore() override;

private:
  MonitorElement* h_score; // Histogram for score distribution
  std::string theFolder; // Folder for the histograms
  edm::ParameterSet parameters;

protected:
  void bookHistograms(DQMStore::IBooker &iBooker, edm::Run const &, edm::EventSetup const &) override;
  void analyze(const edm::Event &event, const edm::EventSetup &eventSetup) override;

};
#endif