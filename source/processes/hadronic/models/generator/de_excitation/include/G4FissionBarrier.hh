// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4FissionBarrier.hh,v 1.1.10.1 1999/12/07 20:51:33 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Oct 1998)

#ifndef G4FissionBarrier_h
#define G4FissionBarrier_h 1

#include "G4VFissionBarrier.hh"
#include "globals.hh"

class G4FissionBarrier : public G4VFissionBarrier
{
public:
  G4FissionBarrier() {};
  ~G4FissionBarrier() {};

private:
  G4FissionBarrier(const G4FissionBarrier & right);

  const G4FissionBarrier & operator=(const G4FissionBarrier & right);
  G4bool operator==(const G4FissionBarrier & right) const;
  G4bool operator!=(const G4FissionBarrier & right) const;
  
public:
  G4double FissionBarrier(const G4int A, const G4int Z);


private:

  G4double BarashenkovFissionBarrier(const G4int A, const G4int Z);
  

};

#endif
