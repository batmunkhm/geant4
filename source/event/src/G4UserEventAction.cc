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
// $Id: G4UserEventAction.cc,v 1.4 2001/07/11 09:58:54 gunter Exp $
// GEANT4 tag $Name: geant4-05-01 $
//

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"

void G4UserEventAction::BeginOfEventAction(const G4Event* anEvent)
{;}

void G4UserEventAction::EndOfEventAction(const G4Event* anEvent)
{;}

