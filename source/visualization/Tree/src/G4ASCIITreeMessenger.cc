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
// $Id: G4ASCIITreeMessenger.cc,v 1.5 2001/07/11 10:09:07 gunter Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
// 
// John Allison  5th April 2001
// A scene handler to dump geometry hierarchy.
// Based on a provisional G4ASCIITreeGraphicsScene (was in modeling).

#include "G4ASCIITreeMessenger.hh"

#include "G4ASCIITree.hh"
#include "G4UIcommand.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAnInteger.hh"

G4ASCIITreeMessenger::G4ASCIITreeMessenger
(G4ASCIITree* ASCIITree):
  fpASCIITree(ASCIITree) {
  G4bool omitable, currentAsDefault;
  fpDirectory = new G4UIdirectory ("/vis/ASCIITree/");
  fpDirectory -> SetGuidance ("Commands for ASCIITree control.");
  fpCommandVerbose = new G4UIcmdWithAnInteger ("/vis/ASCIITree/verbose", this);
  fpCommandVerbose -> SetGuidance ("/vis/ASCIITree/verbose [<verbosity>]");
  fpCommandVerbose -> SetGuidance
    ("0 (default) mimimum - 10 maximum printing.");
  fpCommandVerbose -> SetParameterName ("verbosity",
					omitable = true,
					currentAsDefault = true);
}

G4ASCIITreeMessenger::~G4ASCIITreeMessenger() {
  delete fpCommandVerbose;
  delete fpDirectory;
}

G4String G4ASCIITreeMessenger::GetCurrentValue
(G4UIcommand* command) {
  return "0";
}

void G4ASCIITreeMessenger::SetNewValue
(G4UIcommand* command, G4String newValue) {
  fpASCIITree->SetVerbosity
    (fpCommandVerbose->GetNewIntValue(newValue));
  G4cout << "G4ASCIITree verbosity now "
	 << fpASCIITree->GetVerbosity()
	 << G4endl;  
}
