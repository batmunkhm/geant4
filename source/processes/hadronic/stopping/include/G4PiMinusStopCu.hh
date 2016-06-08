// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4PiMinusStopCu.hh,v 1.1.8.1.2.1 1999/12/07 20:52:34 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// -------------------------------------------------------------------
//      GEANT 4 class file --- Copyright CERN 1998
//      CERN Geneva Switzerland
//
//      For information related to this code contact:
//      CERN, IT Division, ASD group
//
//      File name:     G4PiMinusStopCu.hh 
//
//      Author:        Maria Grazia Pia (pia@genova.infn.it)
// 
//      Creation date: 18 May 1998
//
//      Modifications: 
// -------------------------------------------------------------------

#ifndef G4PIMINUSSTOPCU_HH
#define G4PIMINUSSTOPCU_HH 

#include "g4rw/tpordvec.h"
#include "g4rw/tvordvec.h"
#include "g4rw/cstring.h"

#include "G4PiMinusStopMaterial.hh"
#include "globals.hh"
#include "G4LorentzVector.hh"

class G4PiMinusStopCu : public G4PiMinusStopMaterial
{  

private:

  // Hide assignment operator as private 
  G4PiMinusStopCu& operator=(const G4PiMinusStopCu &right);

  // Copy constructor
  G4PiMinusStopCu(const G4PiMinusStopCu& );

public:

  // Constructor
  G4PiMinusStopCu();

  // Destructor
  virtual ~G4PiMinusStopCu();

  // Definitions of absorption products
  //  virtual G4RWTValOrderedVector<G4String>* DefinitionVector();

  // 4-vectors of absorption products
  //  virtual G4RWTPtrOrderedVector<G4LorentzVector>* P4Vector();

  // Number of final nucleons, out of generated absorption products
  virtual G4double FinalNucleons();


private:

  static G4int eKinEntries;
  static G4int angleEntries;

  static G4double npRatio;
 
  static G4double nFinalNucleons;

  static G4double eMaxTot;

  static G4double eKinData[10];
  static G4double eKin[11];

  static G4double angleData[7];
  static G4double angle[8];

  G4double _clusterSize;

};

#endif


