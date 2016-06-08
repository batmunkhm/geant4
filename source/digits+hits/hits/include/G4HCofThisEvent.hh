// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4HCofThisEvent.hh,v 1.2.2.1.2.1 1999/12/07 20:47:47 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//

#ifndef G4HCofThisEvent_h
#define G4HCofThisEvent_h 1

#include "globals.hh"
#include "G4Allocator.hh"
#include "G4VHitsCollection.hh"
#include "g4rw/tpordvec.h"

// class description:
//
//  This is a class which stores hits collections generated at one event.
// This class is exclusively constructed by G4SDManager when the first
// hits collection of an event is passed to the manager, and this class
// object is deleted by G4RunManager when a G4Event class object is deleted.
//  Almost all public methods must be used by Geant4 kernel classes and
// the user should not invoke them. The user can use two const methods,
// GetHC() and GetNumberOfCollections() for accessing to the stored hits
// collection(s).

class G4HCofThisEvent 
{
  public:
      G4HCofThisEvent();
      G4HCofThisEvent(G4int cap);
      ~G4HCofThisEvent();
      inline void *operator new(size_t);
      inline void operator delete(void* anHCoTE);

      void AddHitsCollection(G4int HCID,G4VHitsCollection * aHC);

  private:
      G4RWTPtrOrderedVector<G4VHitsCollection> * HC;

  public: // with description
      inline G4VHitsCollection* GetHC(G4int i)
      { return (*HC)[i]; }
      //  Returns a pointer to a hits collection. Null will be returned
      // if the particular collection is not stored at the current event.
      // The integer argument is ID number which is assigned by G4SDManager
      // and the number can be obtained by G4SDManager::GetHitsCollectionID()
      // method.
      inline G4int GetNumberOfCollections()
      {
        G4int n = 0;
        for(int i=0;i<HC->entries();i++)
        {
          if((*HC)[i]) n++;
        }
        return n;
      }
      //  Returns the number of hits collections which are stored in this class
      // object.
  public:
      inline G4int GetCapacity()
      {
        return HC->entries();
      }
};

extern G4Allocator<G4HCofThisEvent> anHCoTHAllocator;

inline void* G4HCofThisEvent::operator new(size_t)
{
  void* anHCoTH;
  anHCoTH = (void*)anHCoTHAllocator.MallocSingle();
  return anHCoTH;
}

inline void G4HCofThisEvent::operator delete(void* anHCoTH)
{
  anHCoTHAllocator.FreeSingle((G4HCofThisEvent*)anHCoTH);
}


#endif

