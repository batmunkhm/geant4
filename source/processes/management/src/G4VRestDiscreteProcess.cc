// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VRestDiscreteProcess.cc,v 1.1.10.1 1999/12/07 20:52:51 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
// --------------------------------------------------------------
//	GEANT 4 class implementation file 
//
//	For information related to this code contact:
//	CERN, CN Division, ASD Group
//	History: first implementation, based on object model of
//	2nd December 1995, G.Cosmo
// --------------------------------------------------------------
//   New Physics scheme           8 Jan. 1997  H.Kurahige
// ------------------------------------------------------------

#include "G4VRestDiscreteProcess.hh"
G4VRestDiscreteProcess::G4VRestDiscreteProcess()
                   :G4VProcess("No Name Discrete Process") 
{
  G4Exception("G4VRestDiscreteProcess:: default constructor is called");
}

G4VRestDiscreteProcess::G4VRestDiscreteProcess(const G4String& aName , G4ProcessType aType)
                  : G4VProcess(aName, aType)
{
}

G4VRestDiscreteProcess::~G4VRestDiscreteProcess()
{
}

G4VRestDiscreteProcess::G4VRestDiscreteProcess(G4VRestDiscreteProcess& right)
                  : G4VProcess(right)
{
}











