// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4MuonDecayChannel.hh,v 1.2.4.1 1999/12/07 20:49:51 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
//
// ------------------------------------------------------------
//      GEANT 4 class header file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD group
//      History: first implementation, based on object model of
//      30 May 1997 H.Kurashige
// ------------------------------------------------------------
#ifndef G4MuonDecayChannel_h
#define G4MuonDecayChannel_h 1

#include "G4ios.hh"
#include "globals.hh"
#include "G4VDecayChannel.hh"

class G4MuonDecayChannel :public G4VDecayChannel
{
  public:  // With Description
    //Constructors 
      G4MuonDecayChannel(const G4String& theParentName,
			 G4double        theBR);
    //  Destructor
      virtual ~G4MuonDecayChannel();

  public:  // With Description
     virtual G4DecayProducts *DecayIt(G4double);     
  
};  


#endif
