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
// $Id: G4SmoothTrajectory.hh,v 1.4 2002/11/05 16:15:50 jacek Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
//
//---------------------------------------------------------------
//
// G4SmoothTrajectory.hh
//
// class description:
//   This class represents the trajectory of a particle tracked.
//   It includes information of 
//     1) List of trajectory points which compose the trajectory,
//     2) static information of particle which generated the 
//        trajectory, 
//     3) trackID and parent particle ID of the trajectory,
//     4) Auxiliary points will be associated to G4SmoothTrajectoryPoint
//        to assist drawing smoothly curved trajectory.
//
// ---------------------------------------------------------------

class G4SmoothTrajectory;

#ifndef G4SmoothTrajectory_h
#define G4SmoothTrajectory_h 1

#include "G4VTrajectory.hh"
#include "G4Allocator.hh"
#include <stdlib.h>                 // Include from 'system'
#include "G4ios.hh"               // Include from 'system'
#include "g4std/vector"            // G4RWTValOrderedVector
#include "globals.hh"               // Include from 'global'
#include "G4ParticleDefinition.hh"  // Include from 'particle+matter'
#include "G4SmoothTrajectoryPoint.hh"     // Include from 'tracking'
#include "G4Track.hh"
#include "G4Step.hh"

class G4Polyline;                   // Forward declaration.

typedef G4std::vector<G4VTrajectoryPoint*>  TrajectoryPointContainer;
class G4SmoothTrajectory : public G4VTrajectory
{

//--------
public: // with description
//--------

// Constructor/Destrcutor

   G4SmoothTrajectory();

   G4SmoothTrajectory(const G4Track* aTrack);
   G4SmoothTrajectory(G4SmoothTrajectory &);
   virtual ~G4SmoothTrajectory();

// Operators
   inline void* operator new(size_t);
   inline void  operator delete(void*);
   inline int operator == (const G4SmoothTrajectory& right) const
   {return (this==&right);} 

// Get/Set functions 
   inline G4int GetTrackID() const
   { return fTrackID; }
   inline G4int GetParentID() const
   { return fParentID; }
   inline G4String GetParticleName() const
   { return ParticleName; }
   inline G4double GetCharge() const
   { return PDGCharge; }
   inline G4int GetPDGEncoding() const
   { return PDGEncoding; }
   inline G4ThreeVector GetInitialMomentum() const
   { return initialMomentum; }

// Other member functions
   virtual void ShowTrajectory(G4std::ostream& os=G4cout) const;
   virtual void DrawTrajectory(G4int i_mode=0) const;
   virtual void AppendStep(const G4Step* aStep);
   virtual int GetPointEntries() const { return positionRecord->size(); }
   virtual G4VTrajectoryPoint* GetPoint(G4int i) const 
   { return (*positionRecord)[i]; }
   virtual void MergeTrajectory(G4VTrajectory* secondTrajectory);

   G4ParticleDefinition* GetParticleDefinition();

 // Get method for HEPRep style attributes
   virtual const G4std::map<G4String,G4AttDef>* GetAttDefs() const;
   virtual G4std::vector<G4AttValue>* CreateAttValues() const;

//---------
   private:
//---------

  TrajectoryPointContainer* positionRecord;
  G4int                     fTrackID;
  G4int                     fParentID;
  G4int                     PDGEncoding;
  G4double                  PDGCharge;
  G4String                  ParticleName;
  G4ThreeVector             initialMomentum;

};

extern G4Allocator<G4SmoothTrajectory> aSmoothTrajectoryAllocator;

inline void* G4SmoothTrajectory::operator new(size_t)
{
  void* aTrajectory;
  aTrajectory = (void*)aSmoothTrajectoryAllocator.MallocSingle();
  return aTrajectory;
}

inline void G4SmoothTrajectory::operator delete(void* aTrajectory)
{
  aSmoothTrajectoryAllocator.FreeSingle((G4SmoothTrajectory*)aTrajectory);
}

#endif
