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
// $Id: G4ParticleChange.hh,v 1.9 2001/11/21 14:05:57 kurasige Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
// 
// ------------------------------------------------------------
//	GEANT 4 class header file 
//
// 
// ------------------------------------------------------------
//   Implemented for the new scheme                 23 Mar. 1998  H.Kurahige
//
// Class Description
//  This class is a concrete class for ParticleChange which
//  has all functionality in old scheme.
//-
//  This class contains the results after invocation of a physics process.
//  This includes final states of parent particle (momentum, energy,
//  etc) and secondary particles generated by the interaction.
//  The tracking assumes that all the values of energy and
//  momentum are in global reference system, therefore all the
//  needed Lorentz transformations must have been already Done
//  when filling the data-members of this class.
//-
//  ---------------------------------------------------------------
//  IMPORTANT NOTE: Although the name of the class and methods are
//   "Change", what it stores (and returns in get) are the "FINAL" 
//   values of the Position, Momentum, etc.
// 
//  ------------------------------------------------------------
//  modify AddSecondary methods for "GoodForTracking" flag 
//                                                 8 June 1998 H.Kurashige
//   Add Track weight                              12 Nov. 1998  H.Kurashige
//   Add Get/SetMomentumDirectionChange             6 Feb. 1999 H.Kurashige 
//   Add get/SetDynamicMass                        5 Oct. 1999 H.Kurashige
//   Add get/SetDynamicCharge                       5 Oct. 1999 H.Kurashige
// -------------------------------------------------------------
 
#ifndef G4ParticleChange_h
#define G4ParticleChange_h 1

#include "globals.hh"
#include "G4ios.hh"
#include "G4ThreeVector.hh"
#include "G4ThreeVector.hh"
class G4DynamicParticle;
#include "G4VParticleChange.hh"

class G4ParticleChange: public G4VParticleChange
{ 
  public:
    // default constructor
    G4ParticleChange();
//    G4ParticleChange(G4bool useEB);

    // destructor
    virtual ~G4ParticleChange();

  protected:
    // hide copy constructor and assignment operaor as protected
    G4ParticleChange(const G4ParticleChange &right);
    G4ParticleChange & operator=(const G4ParticleChange &right);

  public:
    // equal/unequal operator
    G4bool operator==(const G4ParticleChange &right) const;
    G4bool operator!=(const G4ParticleChange &right) const;

  public: // with description
    // ----------------------------------------------------
    // --- the following methods are for updating G4Step -----   
    // Return the pointer to the G4Step after updating the Step information
    // by using final state information of the track given by a physics
    // process    
    virtual G4Step* UpdateStepForAlongStep(G4Step* Step);
    // A physics process gives the final state of the particle 
    // relative to the initial state at the beginning of the Step,
    // i.e., based on information of G4Track (or equivalently 
    // the PreStepPoint)
    // In this method, the differences (delta) between these two states 
    // are calculated, and are accumulated in PostStepPoint.
    // Take note that the return type of GetMomentumChange is a
    // pointer to G4ParticleMometum. Also it is a normalized 
    // momentum vector.
    virtual G4Step* UpdateStepForAtRest(G4Step* Step);
    virtual G4Step* UpdateStepForPostStep(G4Step* Step);
    // A physics process gives the final state of the particle 
    // based on information of G4Track (or equivalently the PreStepPoint)
 
    virtual void Initialize(const G4Track&);
    // Initialize all propoerties by using G4Track information

  protected: // with description
    G4Step* UpdateStepInfo(G4Step* Step);
    //  Update the G4Step specific attributes 
    //  (i.e. SteppingControl, LocalEnergyDeposit, and TrueStepLength)

  public:     // with description
    
    // ----------------------------------------------------
    //--- methods to keep information of the final state--
    //  IMPORTANT NOTE: Although the name of the class and methods are
    //   "Change", what it stores (and returns in get) are the "FINAL" 
    //   values of the Position, Momentum, etc.

    const G4ThreeVector* GetMomentumDirectionChange() const;
    void SetMomentumDirectionChange(G4double Px, G4double Py, G4double Pz);
    void SetMomentumDirectionChange(const G4ThreeVector& Pfinal);
    const G4ThreeVector* GetMomentumChange() const;
    void SetMomentumChange(G4double Px, G4double Py, G4double Pz);
    void SetMomentumChange(const G4ThreeVector& Pfinal);
    // Get/Set theMomentumDirectionChange vector: it is the final momentum direction.

    const G4ThreeVector* GetPolarizationChange() const;
    void SetPolarizationChange(G4double Px, G4double Py, G4double Pz);
    void SetPolarizationChange(const G4ThreeVector& finalPoralization);
    // Get/Set thePolarizationChange vector.

    G4double GetEnergyChange() const;
    void SetEnergyChange(G4double theEnergyChange);
    // Get/Set the final kinetic energy of the current particle.

    G4double GetProperTimeChange() const;
    void SetProperTimeChange(G4double t);
    //  Get/Set theProperTimeChange vector

    const G4ThreeVector* GetPositionChange() const;
    void SetPositionChange(G4double x, G4double y, G4double z);
    void SetPositionChange(const G4ThreeVector& finalPosition);
    //  Get/Set the final position of the current particle.

    G4double GetTimeChange() const;
    void SetTimeChange(G4double t);
    //  Get/Set theTimeChange vector.
 
    G4double GetMassChange() const;
    void SetMassChange(G4double mass);
    //   Get/Set theMassChange 

    G4double GetChargeChange() const;
    void SetChargeChange(G4double mass);
    //   Get/Set theChargeChange 
  
    G4double GetWeightChange() const;
    void SetWeightChange(G4double w);
    //   Get/Set theWeightChange 

    //  -- Utility functions --
    G4ThreeVector GetGlobalPosition(const G4ThreeVector& displacement) const;
    //  Convert the position displacement to the global position.

    G4double GetGlobalTime(G4double timeDelay) const;
    //  Convert the time delay to the global time.

    G4ThreeVector CalcMomentum(G4double           energy,
			       G4ThreeVector direction,
			       G4double           mass      ) const;
    //  Calculate momentum by using Energy, Momentum Direction, and Mass 
    // ----------------------------------------------------


    // ----------------------------------------------------
    // --- methods for adding secondaries
    void AddSecondary(G4Track* aSecondary);
    //  Add a secondary particle to theListOfSecondaries.

    void AddSecondary(G4DynamicParticle* aSecondary,
		      G4bool             IsGoodForTracking = false );
    //  Add a secondary particle to theListOfSecondaries.
    //  position and time are same as thePositionChange and theTimeChange 

    void AddSecondary(G4DynamicParticle* aSecondary, 
		      G4ThreeVector      position,
		      G4bool             IsGoodForTracking = false   );
    //  Add a secondary particle to theListOfSecondaries.
    //  global time are same as theTimeChange and theTimeChange 

    void AddSecondary(G4DynamicParticle* aSecondary, 
		      G4double           time,
		      G4bool             IsGoodForTracking = false );
    //  Add a secondary particle to theListOfSecondaries.
    //  position and are same as thePositionChange  
    // ----------------------------------------------------

  public:
    virtual void DumpInfo() const;

  protected:
    G4ThreeVector theMomentumDirectionChange;
    //  It is the vector containing the final momentum direction
    //  after the invoked process. The application of the change
    //  of the momentum direction of the particle is not Done here.
    //  The responsibility to apply the change is up the entity
    //  which invoked the process.

    G4ThreeVector thePolarizationChange;
    //  The changed (final) polarization of a given track
    
    G4double theEnergyChange;
    //  The final kinetic energy of the current track
    
    G4ThreeVector thePositionChange;
    //  The changed (final) position of a given track
    
    G4double theTimeChange;
    //  The changed (final) global time of a given track
    
    G4double theProperTimeChange;
    //  The changed (final) proper time of a given track
    
    G4double theWeightChange;
    //  The Changed (final) weight of a given track

    G4double theMassChange;
    //  The Changed (final) mass of a given track

    G4double theChargeChange;
    //  The Changed (final) charge of a given track
  
    const G4Track* theCurrentTrack;
    
  public:
  // these methods is used for switch on/off EB in all ParticleChange objects
  // static void SwOnAllEB();
  //  static void SwOffAllEB();

  private:
  //  static G4bool fUseEBForAll;

  public:
    // for Debug 
    virtual G4bool CheckIt(const G4Track&);
};

#include "G4ParticleChange.icc"

#endif
















