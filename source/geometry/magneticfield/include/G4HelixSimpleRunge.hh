// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4HelixSimpleRunge.hh,v 1.2 1999/12/15 14:49:47 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
//
// W. Wander <wwc@mit.edu> 03/12/98

#ifndef G4HELIXSIMPLERUNGE_HH
#define G4HELIXSIMPLERUNGE_HH
#include "G4MagHelicalStepper.hh"

class G4HelixSimpleRunge: public G4MagHelicalStepper
{

  public:
  G4HelixSimpleRunge(G4Mag_EqRhs *EqRhs): G4MagHelicalStepper(EqRhs){};
  ~G4HelixSimpleRunge(){};
  
  void  DumbStepper(  const G4double y[],
		      const G4double dydx[],
		      const G4double h,
		      G4double yout[]);
  
  G4int     IntegratorOrder() { return 2; };
};

#endif /* G4HELIXSIMPLERUNGE_HH */
