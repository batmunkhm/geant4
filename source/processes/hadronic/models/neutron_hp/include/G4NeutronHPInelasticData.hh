// This code implementation is the intellectual property of
// neutron_hp -- header file
// J.P. Wellisch, Nov-1996
// A prototype of the low energy neutron transport model.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4NeutronHPInelasticData.hh,v 1.2 1999/07/02 09:59:14 johna Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
#ifndef G4NeutronHPInelasticData_h
#define G4NeutronHPInelasticData_h 1

#include "G4VCrossSectionDataSet.hh"
#include "G4DynamicParticle.hh"
#include "G4Element.hh"
#include "G4ParticleDefinition.hh"
#include "G4PhysicsTable.hh"

class G4NeutronHPInelasticData : public G4VCrossSectionDataSet
{
   public:
   
   G4NeutronHPInelasticData();
   
   ~G4NeutronHPInelasticData();
   
   G4bool IsApplicable(const G4DynamicParticle*, const G4Element*);

   G4double GetCrossSection(const G4DynamicParticle*, const G4Element*);

   void BuildPhysicsTable(const G4ParticleDefinition&);

   void DumpPhysicsTable(const G4ParticleDefinition&);
   
   private:
   
   G4PhysicsTable * theCrossSections;
};

#endif
