// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4LEKaonZeroSInelastic.hh,v 1.1.10.1 1999/12/07 20:52:17 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
 // Hadronic Process: Low Energy KaonZeroS Inelastic Process
 // J.L. Chuma, TRIUMF, 12-Feb-1997
 // Last modified: 27-Mar-1997
 
#ifndef G4LEKaonZeroSInelastic_h
#define G4LEKaonZeroSInelastic_h 1
 
#include "G4InelasticInteraction.hh"
 
 class G4LEKaonZeroSInelastic : public G4InelasticInteraction
 {
 public:
    
    G4LEKaonZeroSInelastic() : G4InelasticInteraction()
    {
      SetMinEnergy( 0.0 );
      SetMaxEnergy( 25.*GeV );
    }
    
    ~G4LEKaonZeroSInelastic()
    { }
    
    G4VParticleChange *ApplyYourself( const G4Track &aTrack,
                                      G4Nucleus &targetNucleus );
    
 private:
    
    void Cascade(                               // derived from CASK0
      G4FastVector<G4ReactionProduct,128> &vec,
      G4int &vecLen,
      const G4DynamicParticle *originalIncident,
      G4ReactionProduct &currentParticle,
      G4ReactionProduct &targetParticle,
      G4bool &incidentHasChanged, 
      G4bool &targetHasChanged,
      G4bool &quasiElastic );
    
 };
 
#endif
 
