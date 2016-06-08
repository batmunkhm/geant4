// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4KineticTrackVector.hh,v 1.3 1999/12/15 14:52:50 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $

// Modified at 8-Oct-1998 by Maxim Komogorov. Methods BoostBeam,Boost,Shift
// were added.

#ifndef G4KineticTrackVector_h
#define G4KineticTrackVector_h 1

#include "globals.hh"
#include "G4KineticTrack.hh"
#include "g4rw/tpordvec.h"

class G4KineticTrackVector : public G4RWTPtrOrderedVector<G4KineticTrack>
    {
public:
  G4KineticTrackVector();

public:
    void BoostBeam(G4ThreeVector& BeamMom);
    void Boost(G4ThreeVector& Velocity);
    void Shift(G4ThreeVector& Pos);
    };

#endif

