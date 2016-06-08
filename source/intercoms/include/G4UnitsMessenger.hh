// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4UnitsMessenger.hh,v 1.3 1999/12/15 14:50:40 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// class description
//
// This class is the messenger of the class which maintain the table of Units.
// (located in global/management/include/G4UnitsTable.hh)
// Its contains the commands to interact with the table of Units 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef G4UnitsMessenger_h
#define G4UnitsMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class G4UIdirectory;
class G4UIcmdWithoutParameter;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class G4UnitsMessenger: public G4UImessenger
{
  public:
    G4UnitsMessenger();
   ~G4UnitsMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:    
    G4UIdirectory*             UnitsTableDir;
    G4UIcmdWithoutParameter*   ListCmd;
};

#endif

