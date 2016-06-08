// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4DMmessenger.cc,v 1.1.10.1 1999/12/07 20:52:58 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// ---------------------------------------------------------------------

#include "G4DMmessenger.hh"
#include "G4DigiManager.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"

G4DMmessenger::G4DMmessenger(G4DigiManager* DigiManager):fDMan(DigiManager)
{
  digiDir = new G4UIdirectory("/digi/");
  digiDir->SetGuidance("DigitizerModule");

  listCmd = new G4UIcmdWithoutParameter("/digi/List",this);
  listCmd->SetGuidance("List names of digitizer modules.");

  digiCmd = new G4UIcmdWithAString("/digi/Digitize",this);
  digiCmd->SetGuidance("Invoke Digitize method of a digitizer module");
  digiCmd->SetParameterName("moduleName",false);

  verboseCmd = new G4UIcmdWithAnInteger("/digi/Verbose",this);
  verboseCmd->SetGuidance("Set the Verbose level.");
  verboseCmd->SetParameterName("level",false);
}

G4DMmessenger::~G4DMmessenger()
{
  delete listCmd;
  delete digiCmd;
  delete verboseCmd;
  delete digiDir;
}

void G4DMmessenger::SetNewValue(G4UIcommand * command,G4String newVal)
{
  if( command==listCmd )
  { fDMan->List(); }
  if( command==digiCmd )
  { fDMan->Digitize(newVal); }
  if( command==verboseCmd )
  { fDMan->SetVerboseLevel(verboseCmd->GetNewIntValue(newVal)); }
  return;
}


