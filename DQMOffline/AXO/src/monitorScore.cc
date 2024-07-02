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
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DQMServices/Core/interface/DQMStore.h"

#include <string>
#include <TMath.h>
using namespace std;
using namespace edm;

