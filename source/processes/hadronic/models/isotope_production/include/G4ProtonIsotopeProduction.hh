#ifndef G4ProtonIsotopeProduction_h
#define G4ProtonIsotopeProduction_h

#include "globals.hh"
#include "G4VIsotopeProduction.hh"
#include "G4ElementIsoCrossSections.hh"
#include "G4ProtonIsoIsoCrossSections.hh"
#include "Randomize.hh"

// Class Description
// Isotopeproduction model for proton induced production below 100 MeV.
// To be used in your physics list in case you need this physics.
// In this case you want to register an object of this class with 
// the corresponding process instance.
// Class Description - End

class G4ProtonIsotopeProduction : public G4VIsotopeProduction
{
  public:
  
  G4ProtonIsotopeProduction();
  ~G4ProtonIsotopeProduction();

  G4IsoResult * GetIsotope(const G4Track & aTrack, const G4Nucleus & aNucleus);

  private:
    
  G4ElementIsoCrossSections<G4ProtonIsoIsoCrossSections> ** theData;
  G4int numberOfElements;
};

#endif
