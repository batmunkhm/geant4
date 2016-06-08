// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em5PhysicsListMessenger.hh,v 1.2 1999/12/15 14:49:08 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em5PhysicsListMessenger_h
#define Em5PhysicsListMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class Em5PhysicsList;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em5PhysicsListMessenger: public G4UImessenger
{
  public:
  
    Em5PhysicsListMessenger(Em5PhysicsList*);
   ~Em5PhysicsListMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
  
    Em5PhysicsList*            Em5List;

    G4UIcmdWithADoubleAndUnit* cutGCmd;
    G4UIcmdWithADoubleAndUnit* cutECmd;
    G4UIcmdWithADoubleAndUnit* cutPCmd;
    G4UIcmdWithADoubleAndUnit* rCmd;
    G4UIcmdWithADoubleAndUnit* eCmd;
    G4UIcmdWithADoubleAndUnit* setMaxStepCmd;     
};

#endif

