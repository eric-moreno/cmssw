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

#include "DataFormats/L1TGlobal/interface/AXOL1TLScore.h"
