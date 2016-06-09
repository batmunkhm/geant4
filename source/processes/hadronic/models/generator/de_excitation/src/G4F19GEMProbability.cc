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
// $Id: G4F19GEMProbability.cc,v 1.1 2002/06/06 18:00:50 larazb Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Nov 1999)
//


#include "G4F19GEMProbability.hh"

G4F19GEMProbability::G4F19GEMProbability() :
  G4GEMProbability(19,9,1.0/2.0) // A,Z,Spin
{

  ExcitEnergies.push_back(109.893*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(0.580e-3*picosecond);

  ExcitEnergies.push_back(197.147*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(89.30e-3*picosecond);

  ExcitEnergies.push_back(1345.72*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(3.3*picosecond);

  ExcitEnergies.push_back(1458.5*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(54.0e-3*picosecond);

  ExcitEnergies.push_back(1554.1*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(3.0e-3*picosecond);

  ExcitEnergies.push_back(2779.8*keV);
  ExcitSpins.push_back(9.0/2.0);
  ExcitLifetimes.push_back(181.0e-3*picosecond);

  ExcitEnergies.push_back(3907.1*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(14.0e-3*picosecond);

  ExcitEnergies.push_back(3998.5*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(16.0e-3*picosecond);

  ExcitEnergies.push_back(4032.5*keV);
  ExcitSpins.push_back(9.0/2.0);
  ExcitLifetimes.push_back(51.0e-3*picosecond);

  ExcitEnergies.push_back(4555.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(14.0e-3*picosecond);

  ExcitEnergies.push_back(4557.5*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(14.0e-3*picosecond);

  ExcitEnergies.push_back(4648.0*keV);
  ExcitSpins.push_back(13.0/2.0);
  ExcitLifetimes.push_back(1.5*picosecond);

  ExcitEnergies.push_back(4683.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(10.7e-3*picosecond);

  ExcitEnergies.push_back(5340.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(10.0e-3*picosecond);

  ExcitEnergies.push_back(5464.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(13.0e-3*picosecond);

  ExcitEnergies.push_back(6076.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.2*keV));

  ExcitEnergies.push_back(6093.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.0*keV));

  ExcitEnergies.push_back(6250.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(8.0*keV));

  ExcitEnergies.push_back(6290.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.4*keV));

  ExcitEnergies.push_back(6332.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.4*keV));

  ExcitEnergies.push_back(6430.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(280.0*keV));

  ExcitEnergies.push_back(6525.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.0*keV));

  ExcitEnergies.push_back(6553.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.6*keV));

  ExcitEnergies.push_back(6788.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.4*keV));

  ExcitEnergies.push_back(6838.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.2*keV));

  ExcitEnergies.push_back(6890.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(28.0*keV));

  ExcitEnergies.push_back(6926.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.4*keV));

  ExcitEnergies.push_back(6990.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(51.0*keV));

  ExcitEnergies.push_back(7110.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(32.0*keV));

  ExcitEnergies.push_back(7120.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(8.0*keV));

  ExcitEnergies.push_back(7364.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(63.0*keV));

  ExcitEnergies.push_back(7702.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(24.0*keV));

  ExcitEnergies.push_back(8014.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(6.0*keV));

  ExcitEnergies.push_back(8086.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(6.0*keV));

  ExcitEnergies.push_back(8136.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.0*keV));

  ExcitEnergies.push_back(8195.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(8.0*keV));

  ExcitEnergies.push_back(8590.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.0*keV));

  ExcitEnergies.push_back(8637.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(95.0*keV));

  ExcitEnergies.push_back(8795.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(45.0*keV));

  ExcitEnergies.push_back(8928.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.6*keV));

  ExcitEnergies.push_back(9098.4*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(20.0e-3*keV));

  ExcitEnergies.push_back(9166.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.8*keV));

  ExcitEnergies.push_back(9321.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.9*keV));

  ExcitEnergies.push_back(9527.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(29.0*keV));

  ExcitEnergies.push_back(9578.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(26.0*keV));

  ExcitEnergies.push_back(9668.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.8*keV));

  ExcitEnergies.push_back(9819.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.29*keV));

  ExcitEnergies.push_back(9888.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(31.0*keV));

  ExcitEnergies.push_back(10136.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.7*keV));

  ExcitEnergies.push_back(10161.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(31.0*keV));

  ExcitEnergies.push_back(10231.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.3*keV));

  ExcitEnergies.push_back(10253.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(23.0*keV));

  ExcitEnergies.push_back(10306.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(9.2*keV));

  ExcitEnergies.push_back(10496.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(6.2*keV));

  ExcitEnergies.push_back(10554.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(7.6*keV));

  ExcitEnergies.push_back(10580.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(22.0*keV));

  ExcitEnergies.push_back(10613.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.8*keV));

  ExcitEnergies.push_back(10763.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.4*keV));

  ExcitEnergies.push_back(10858.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(25.0*keV));

  ExcitEnergies.push_back(10972.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(11.0*keV));

  ExcitEnergies.push_back(11070.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(31.0*keV));

  ExcitEnergies.push_back(11199.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(43.0*keV));

}


G4F19GEMProbability::G4F19GEMProbability(const G4F19GEMProbability &right)
{
  G4Exception("G4F19GEMProbability::copy_constructor meant to not be accessable");
}




const G4F19GEMProbability & G4F19GEMProbability::
operator=(const G4F19GEMProbability &right)
{
  G4Exception("G4F19GEMProbability::operator= meant to not be accessable");
  return *this;
}


G4bool G4F19GEMProbability::operator==(const G4F19GEMProbability &right) const
{
  return false;
}

G4bool G4F19GEMProbability::operator!=(const G4F19GEMProbability &right) const
{
  return true;
}



