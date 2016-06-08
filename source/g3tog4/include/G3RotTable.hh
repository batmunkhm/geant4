// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G3RotTable.hh,v 1.10 1999/12/09 01:27:46 lockman Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// by I.Hrivnacova, 27 Sep 99

#ifndef G3ROTTABLEH_HH
#define G3ROTTABLEH_HH 1

#include "G3RotTableEntry.hh"

#include "globals.hh"

#include "g4rw/tpordvec.h"

class G4Material;

typedef G4RWTPtrOrderedVector<G3RotTableEntry>  G3RotMatrixVector;

class G3RotTable
{
  public:
    G3RotTable();
    virtual ~G3RotTable();
    
    // methods
    // keep the same names of methods as in G4 g3tog4
    // G3toG4RotationMatrix type changed to G4RotationMatrix)
    //
    G4RotationMatrix* Get(G4int id) const;
    void Put(G4int id, G4RotationMatrix* matrix);
    void Clear();

  private:
    G3RotMatrixVector*  fRotVector;
};

extern G3RotTable G3Rot;

#endif
