// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VGlobalFastSimulationManager.cc,v 1.2 1999/12/15 14:50:42 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
// Abstract interface for GEANT4 Global Fast Simulation Manager.
// P. Mora de Freitas & M. Verderi 14/April/1999.

#include "G4VGlobalFastSimulationManager.hh"

G4VGlobalFastSimulationManager* 
G4VGlobalFastSimulationManager::fpConcreteInstance = 0;
