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
// $Id: G4Li6GEMProbability.cc,v 1.1 2002/06/06 18:02:05 larazb Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Nov 1999)
//


#include "G4Li6GEMProbability.hh"

G4Li6GEMProbability::G4Li6GEMProbability() :
  G4GEMProbability(6,3,1.0) // A,Z,Spin
{
  ExcitEnergies.push_back(2186.0*keV);
  ExcitSpins.push_back(3.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(24.0*keV));
  
  ExcitEnergies.push_back(3562.88*keV);
  ExcitSpins.push_back(0.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(8.2*eV));

  ExcitEnergies.push_back(4310.0*keV);
  ExcitSpins.push_back(2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.7*MeV));

  ExcitEnergies.push_back(5366.0*keV);
  ExcitSpins.push_back(2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(540.0*keV));

  ExcitEnergies.push_back(5.65E+3*keV);
  ExcitSpins.push_back(1.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.5*MeV));

  ExcitEnergies.push_back(15800.0*keV);
  ExcitSpins.push_back(3.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(17.8*MeV));

  ExcitEnergies.push_back(23.0E+3*keV);
  ExcitSpins.push_back(4.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(12.0*MeV));

  ExcitEnergies.push_back(25.0E+3*keV);
  ExcitSpins.push_back(4.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.0*MeV));
  
  SetExcitationEnergiesPtr(&ExcitEnergies);
  SetExcitationSpinsPtr(&ExcitSpins);
  SetExcitationLifetimesPtr(&ExcitLifetimes);
}


G4Li6GEMProbability::G4Li6GEMProbability(const G4Li6GEMProbability &right)
{
  G4Exception("G4Li6GEMProbability::copy_constructor meant to not be accessable");
}




const G4Li6GEMProbability & G4Li6GEMProbability::
operator=(const G4Li6GEMProbability &right)
{
  G4Exception("G4Li6GEMProbability::operator= meant to not be accessable");
  return *this;
}


G4bool G4Li6GEMProbability::operator==(const G4Li6GEMProbability &right) const
{
  return false;
}

G4bool G4Li6GEMProbability::operator!=(const G4Li6GEMProbability &right) const
{
  return true;
}



