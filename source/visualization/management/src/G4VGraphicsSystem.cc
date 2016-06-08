// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VGraphicsSystem.cc,v 1.5 1999/12/15 14:54:25 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
// John Allison  27th March 1996
// Abstract interface class for graphics systems.

#include "G4VGraphicsSystem.hh"

#include "G4VisManager.hh"

G4VGraphicsSystem::~G4VGraphicsSystem () {}

G4VGraphicsSystem::G4VGraphicsSystem (const G4String& name,
				      Functionality f):
  fName (name),
  fNickname (""),
  fDescription (""),
  fFunctionality (f) {}

G4VGraphicsSystem::G4VGraphicsSystem (const G4String& name,
				      const G4String& nickname,
				      Functionality f):
  fName (name),
  fNickname (nickname),
  fDescription (""),
  fFunctionality (f) {}

G4VGraphicsSystem::G4VGraphicsSystem (const G4String& name,
				      const G4String& nickname,
				      const G4String& description,
				      Functionality f):
  fName (name),
  fNickname (nickname),
  fDescription (description),
  fFunctionality (f) {}

G4std::ostream& operator << (G4std::ostream& os, const G4VGraphicsSystem& gs) {
  G4VisManager* pVMan = G4VisManager::GetInstance ();
  const G4SceneHandlerList& scenes = pVMan -> GetAvailableSceneHandlers ();
  os << "Graphics System: " << gs.GetName ();
  if (gs.GetNickname () != "") {
    os << ", nickname: " << gs.GetNickname ();
  }
  if (gs.GetDescription () != "") {
    os << "\n  Description: " << gs.GetDescription ();
  }
  os << "\n  Functionality: " << gs.GetFunctionality ();
  if (pVMan -> GetVerboseLevel () > 1) {
    G4int nScenes = scenes.entries ();
    if (nScenes) {
      G4int nScenesOfThisSystem = 0;
      for (int i = 0; i < nScenes; i++) {
	if (scenes [i] -> GetGraphicsSystem () == &gs) {
	  nScenesOfThisSystem++;
	}
      }
      if (nScenesOfThisSystem) {
	os << "\n  Its scenes are: ";
	for (int i = 0; i < nScenes; i++) {
	  if (scenes [i] -> GetGraphicsSystem () == &gs) {
	    os << "\n  " << *(scenes [i]);
	  }
	}
      }
      else {
	os << "\n  It has no scenes at present.";
      }
    }
    else {
      os << "\n  There are no scenes instantiated at present.";
    }
  }
  return os;
}
