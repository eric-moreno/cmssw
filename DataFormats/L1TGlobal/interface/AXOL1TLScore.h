#ifndef DataFormats_L1TGlobal_AXOL1TLScore_h
#define DataFormats_L1TGlobal_AXOL1TLScore_h

/**
* \class AXOL1TLScore
*
*
* Description: L1 micro Global Trigger - Extra NN score emulation information for AXOL1TL.
* 
*
* \author: Melissa Quinnan - UC San Diego
*
*
*/

// system include files
#include <vector>
#include <iostream>
#include <iomanip>

// user include files
#include "FWCore/Utilities/interface/typedefs.h"
#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"
#include "DataFormats/L1Trigger/interface/L1TObjComparison.h"

// forward declarations

// namespace l1t {
class AXOL1TLScore;
typedef BXVector<AXOL1TLScore> AXOL1TLScoreBxCollection;
  
typedef l1t::ObjectRef<AXOL1TLScore> AXOL1TLScoreRef;
typedef l1t::ObjectRefBxCollection<AXOL1TLScore> AXOL1TLScoreRefBxCollection;
// typedef l1t::ObjectRefPair<AXOL1TLScore> AXOL1TLScoreRefPair;
// typedef l1t::ObjectRefPairBxCollection<AXOL1TLScore> AXOL1TLScoreRefPairBxCollection; //not sure if pair part is needed
  
// class interface
class AXOL1TLScore {
public:

  //later add string for what model you are using per score?
  //add bx? 
  
  /// constructors
  AXOL1TLScore(); //empty constructor
		      
  AXOL1TLScore(int bxNr, int bxInEvent);
  
  /// destructor
  virtual ~AXOL1TLScore();
  
  ///set/get axo score and other simple members
  void setAXOScore(float score) {axoscore_ = score;}
  void setbxInEventNr(int bxNr) { m_bxInEvent = bxNr; }
  void setL1FirmwareUUID(int fuuid) { m_bxNr = fuuid; }
  
  inline float const& getAXOScore() const { return axoscore_; }
  inline const int getbxInEventNr() const { return m_bxInEvent; }
  inline const int getL1FirmwareUUID() const { return m_bxNr; }

  void reset();
  
private:
  
    
  //axo score value
  float axoscore_;

  /// bunch cross number of the actual bx -> L1FirmwareUUID
  int m_bxNr;

  /// bunch cross in the GT event record (E,F,0,1,2)
  int m_bxInEvent;

  //store version or type of network?
  // std::string nnversion; 
  
};
//} l1t namespace
#endif /*DataFormats_L1TGlobal_AXOL1TLScore_h*/
