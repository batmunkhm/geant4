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
// $Id: G4TouchableHistoryHandle.hh,v 1.4 2002/07/23 08:50:36 gcosmo Exp $
// GEANT4 tag $Name: geant4-05-01 $
// 
// Class G4TouchableHistoryHandle
//
// Class description:
//
// A type providing reference counting mechanism for a G4TouchableHistory
// object.
// The basic rule for the use of this type is that this handle must always
// be exchanged by reference never dinamically allocated (i.e. never
// instantiated using 'new').
//
// For more details see G4ReferenceCountedHandle.

// Author: Radovan Chytracek (Radovan.Chytracek@cern.ch), March 2001
// ----------------------------------------------------------------------

#ifndef _G4TOUCHABLEHISTORYHANDLE_H_
#define _G4TOUCHABLEHISTORYHANDLE_H_ 1

#include "G4TouchableHistory.hh"
#include "G4ReferenceCountedHandle.hh"

typedef G4ReferenceCountedHandle<G4TouchableHistory> G4TouchableHistoryHandle;

#endif // _G4TOUCHABLEHISTORYHANDLE_H_
