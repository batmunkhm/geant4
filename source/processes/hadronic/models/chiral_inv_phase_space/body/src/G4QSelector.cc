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
// $Id: G4QSelector.cc,v 1.15 2002/12/12 19:14:35 gunter Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
//      ---------------- G4QSelector ----------------
//             by Mikhail Kossov, Sept 1999.
//      class for decay Selection for Hadrons generated by CHIPS Model
// -------------------------------------------------------------------
#include "G4QSelector.hh"

G4QSelector::G4QSelector(){}

G4QSelector::G4QSelector(G4QHadronVector hadronVec) : theHadrons(hadronVec){}

G4bool G4QSelector::SelectPDGSet(G4QPDGCodeVector thePDGCodes)
{
  G4int  ind;
  G4int  tNH = theHadrons.size();
  G4int* yes = new int[tNH];
  //for (ind=0; ind<tNH; ind++)
  for (ind=tNH-1; ind>=0; ind--) // A Loop to fill
  {
    ////////G4int c=theHadrons[ind]->GetPDGCode(); // PDGCode
  }

  delete yes;
  return false;
}

G4QSelector::~G4QSelector() {}
