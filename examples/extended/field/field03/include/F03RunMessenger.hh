//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//

//
// $Id: F03RunMessenger.hh,v 1.3 2001/10/15 17:20:49 gcosmo Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef F03RunMessenger_h
#define F03RunMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class F03RunAction;
class G4UIdirectory;
class G4UIcmdWithAnInteger;
class G4UIcmdWithAString;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class F03RunMessenger : public G4UImessenger
{
  public:

   F03RunMessenger(F03RunAction* );
  ~F03RunMessenger();

   void SetNewValue(G4UIcommand* ,G4String );

  private:

   F03RunAction*              runAction;
   
   G4UIdirectory*             RndmDir;
   G4UIcmdWithAnInteger*      RndmSaveCmd;    
   G4UIcmdWithAString*        RndmReadCmd;    
 
};

#endif
