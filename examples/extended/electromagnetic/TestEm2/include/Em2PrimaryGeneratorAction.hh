// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em2PrimaryGeneratorAction.hh,v 1.2 1999/12/15 14:48:59 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em2PrimaryGeneratorAction_h
#define Em2PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4Event;
class Em2DetectorConstruction;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em2PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    Em2PrimaryGeneratorAction(Em2DetectorConstruction*);    
   ~Em2PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event*);
    G4ParticleGun* GetParticleGun() {return particleGun;};
    
  private:
    G4ParticleGun*              particleGun;
    Em2DetectorConstruction*    Em2Detector; 
};

#endif


