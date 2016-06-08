// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VVisCommand.hh,v 1.6 1999/12/16 17:19:15 johna Exp $
// GEANT4 tag $Name: geant4-01-01 $

// Base class for visualization commands - John Allison  9th August 1998
// It is really a messenger - we have one command per messenger.

#ifndef G4VVISCOMMAND_HH
#define G4VVISCOMMAND_HH

#include "G4UImessenger.hh"
#include "g4std/vector"

class G4VisManager;
class G4UIcommand;
class G4UIcmdWithAString;

class G4VVisCommand: public G4UImessenger {
public:
  // Uses compiler defaults for copy constructor and assignment.
  G4VVisCommand ();
  virtual ~G4VVisCommand ();
  static void SetVisManager (G4VisManager*);
protected:
  static G4VisManager* fpVisManager;
  static  G4std::vector<G4UIcommand*> sceneNameCommands;
  typedef G4std::vector<G4UIcommand*>::iterator sceneNameCommandsIterator; 
  static  G4std::vector<G4UIcommand*> sceneHandlerNameCommands;
  typedef G4std::vector<G4UIcommand*>::iterator
    sceneHandlerNameCommandsIterator;
  static  G4std::vector<G4UIcommand*> viewerNameCommands;
  typedef G4std::vector<G4UIcommand*>::iterator viewerNameCommandsIterator; 
};

#include "G4VVisCommand.icc"

#endif
