// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VBaryon.cc,v 1.2 1999/12/15 14:51:00 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// 
// --------------------------------------------------------------
//      GEANT 4 class implementation file 
//
//      For information related to this code contact:
//      CERN, CN Division, ASD Group
//      History: first implementation, based on object model of
//      2nd December 1995, G.Cosmo
// --------------------------------------------------------------

#include "G4VBaryon.hh"

const G4VBaryon & G4VBaryon::operator=(const G4VBaryon &right)
{
  if (this != &right) {
  } return right;
}
