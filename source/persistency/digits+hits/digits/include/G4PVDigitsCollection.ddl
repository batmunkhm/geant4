// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4PVDigitsCollection.ddl,v 1.6 2000/12/15 08:04:13 morita Exp $
// GEANT4 tag $Name: geant4-03-00 $
//

// Class Description:
//   This is a persistent version of container class which stores
// the associations to the digits of one sensitive detector.
// User should inherit his/her own persistent digits collection
// from this class to store user derived digits.
//   At the end of each event, user sensitive detector should
// create a new collection with a detector name and a collection
// name.  Comparison operator and GetName(), GetSDName() are
// provided.
//

#ifndef G4PVDigitsCollection_h
#define G4PVDigitsCollection_h 1

#include "G4Pglobals.hh"
#include "G4PersistentTypes.hh"
#include "G4PersistentSchema.hh"

#include "HepODBMS/odbms/HepODBMS.h"

class G4PVDigitsCollection 
 : public HepPersObj
{
  public: // with description
      G4PVDigitsCollection(G4String detName,G4String colNam);
      // Constructor.
      ~G4PVDigitsCollection();
      // Destructor.
      int operator==(const G4PVDigitsCollection &right) const;
      // Comparison with detName and colNam.

  protected:
      // Persistent Collection name
      G4PString pcollectionName;
      G4PString pDMname;

  public: // with description
      inline G4String GetName()
      { return (G4String) pcollectionName; }
      // returns the collection name.
      inline G4String GetDMname()
      { return (G4String) pDMname; }
      // returns the detector name.

};

#endif

