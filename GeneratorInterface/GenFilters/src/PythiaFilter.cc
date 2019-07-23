
#include "GeneratorInterface/GenFilters/interface/PythiaFilter.h"
#include "GeneratorInterface/GenFilters/interface/MCFilterZboostHelper.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include <iostream>

using namespace edm;
using namespace std;

PythiaFilter::PythiaFilter(const edm::ParameterSet& iConfig)
    : token_(consumes<edm::HepMCProduct>(
          edm::InputTag(iConfig.getUntrackedParameter("moduleLabel", std::string("generator")), "unsmeared"))),
      particleID(iConfig.getUntrackedParameter("ParticleID", 0)),
      minpcut(iConfig.getUntrackedParameter("MinP", 0.)),
      maxpcut(iConfig.getUntrackedParameter("MaxP", 10000.)),
      minptcut(iConfig.getUntrackedParameter("MinPt", 0.)),
      maxptcut(iConfig.getUntrackedParameter("MaxPt", 10000.)),
      minetacut(iConfig.getUntrackedParameter("MinEta", -10.)),
      maxetacut(iConfig.getUntrackedParameter("MaxEta", 10.)),
      minrapcut(iConfig.getUntrackedParameter("MinRapidity", -20.)),
      maxrapcut(iConfig.getUntrackedParameter("MaxRapidity", 20.)),
      minphicut(iConfig.getUntrackedParameter("MinPhi", -3.5)),
      maxphicut(iConfig.getUntrackedParameter("MaxPhi", 3.5)),
      status(iConfig.getUntrackedParameter("Status", 0)),
      motherID(iConfig.getUntrackedParameter("MotherID", 0)),
      processID(iConfig.getUntrackedParameter("ProcessID", 0)),
      betaBoost(iConfig.getUntrackedParameter("BetaBoost", 0.)), 
      ndaughters(iConfig.getUntrackedParameter("NumberDaughters", 0))   
      
{
	vector<int> defdauID; 
	defdauID.push_back(0);
	dauIDs = iConfig.getUntrackedParameter<vector<int>>("DaughterIDs", defdauID);
}

PythiaFilter::~PythiaFilter() {
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}

//
// member functions
//

// ------------ method called to produce the data  ------------
bool PythiaFilter::filter(edm::StreamID, edm::Event& iEvent, const edm::EventSetup& iSetup) const {
  using namespace edm;
  bool accepted = false;
  Handle<HepMCProduct> evt;
  iEvent.getByToken(token_, evt);

  const HepMC::GenEvent* myGenEvent = evt->GetEvent();

  if (processID == 0 || processID == myGenEvent->signal_process_id()) {
    for (HepMC::GenEvent::particle_const_iterator p = myGenEvent->particles_begin(); p != myGenEvent->particles_end();
         ++p) {
      HepMC::FourVector mom = MCFilterZboostHelper::zboost((*p)->momentum(), betaBoost);
      double rapidity = 0.5 * log((mom.e() + mom.pz()) / (mom.e() - mom.pz()));
			
      if (abs((*p)->pdg_id()) == particleID && mom.rho() > minpcut && mom.rho() < maxpcut &&
          (*p)->momentum().perp() > minptcut && (*p)->momentum().perp() < maxptcut && mom.eta() > minetacut &&
          mom.eta() < maxetacut && rapidity > minrapcut && rapidity < maxrapcut && (*p)->momentum().phi() > minphicut &&
          (*p)->momentum().phi() < maxphicut) {
        if (status == 0 && motherID == 0) {
          accepted = true;
        }
        if (status != 0 && motherID == 0) {
          if ((*p)->status() == status)
            accepted = true;
        }

        HepMC::GenParticle* mother = (*((*p)->production_vertex()->particles_in_const_begin()));

        if (status == 0 && motherID != 0) {
          if (abs(mother->pdg_id()) == abs(motherID)) {
            accepted = true;
          }
        }
        if (status != 0 && motherID != 0) {
          if ((*p)->status() == status && abs(mother->pdg_id()) == abs(motherID)) {
            accepted = true;
          }
        }

        /*
	   if (status == 0 && motherID != 0){    
	   if (abs(((*p)->mother())->pdg_id()) == abs(motherID)) {
	   accepted = true;
	   }
	   }
	   if (status != 0 && motherID != 0){
           
	   if ((*p)->status() == status && abs(((*p)->mother())->pdg_id()) == abs(motherID)){   
	   accepted = true;
	   
	   }
	   }
	 */
      }
    }

  } else {
    accepted = true;
  }

	if (processID == 0 || processID == myGenEvent->signal_process_id()) {
    for (HepMC::GenEvent::particle_const_iterator p = myGenEvent->particles_begin(); p != myGenEvent->particles_end();
       ++p) {
			if ((*p)->pdg_id() != particleID)
				continue;
			int ndauac = 0;
			int ndau = 0;
			if ((*p)->end_vertex()) {
				for (HepMC::GenVertex::particle_iterator des = (*p)->end_vertex()->particles_begin(HepMC::children);
						 des != (*p)->end_vertex()->particles_end(HepMC::children);
						 ++des) {
					++ndau; 
					for (unsigned int i = 0; i < dauIDs.size(); ++i) {
						if ((*des)->pdg_id() != dauIDs[i])
							accepted = false;
					}
					for (unsigned int i = 0; i < dauIDs.size(); ++i) {
						if ((*des)->pdg_id() = dauIDs[i])
							accepted = true;
					}
				}
			}
		}
	}

  if (accepted) {
    return true;
  } else {
    return false;
  }
}
