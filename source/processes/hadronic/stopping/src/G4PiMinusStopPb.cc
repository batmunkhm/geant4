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
// $Id: G4PiMinusStopPb.cc,v 1.8 2002/12/12 19:18:38 gunter Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
// -------------------------------------------------------------------
//      GEANT 4 class file --- Copyright CERN 1998
//      CERN Geneva Switzerland
//
//
//      File name:     G4PiMinusStopPb
//
//      Author:        Maria Grazia Pia (pia@genova.infn.it)
// 
//      Creation date: 8 May 1998
//
//      Modifications: 
// -------------------------------------------------------------------

#include "G4ios.hh"

#include "G4PiMinusStopPb.hh"

#include "g4std/vector"

#include "globals.hh"
#include "Randomize.hh"
#include "G4Proton.hh"
#include "G4Neutron.hh"
#include "G4ParticleTypes.hh"
#include "G4ReactionKinematics.hh"
#include "G4DynamicParticleVector.hh"
#include "G4LorentzVector.hh"
#include "G4NucleiPropertiesTable.hh"
#include "G4PiMinusStopMaterial.hh"
#include "G4DistributionGenerator.hh"

// np/pp production ratio
// Experimental values: 
// R(np/pp) (E. Gadioli et al., Phys Rev C36 (1987) 741) 
G4double G4PiMinusStopPb::npRatio = 6;
 
// Average numbers of final nucleons detected, for N-pair absorption
// (R. Madey  et al., Phys Rev C25 (1982) 3050
G4double G4PiMinusStopPb::nFinalNucleons = 1.67;

// Kinetic energy (MeV) distributions measured for coincident nucleon 
// emission
// (R. Madey  et al., Phys Rev C25 (1982) 3050

G4int G4PiMinusStopPb::eKinEntries = 10;

G4double G4PiMinusStopPb::eKinData[10] = { 0.24, 0.5, 1.03, 1.28,
                                     1.44, 
				     1.28, 1.03, 0.82, 0.50, 0.22};

G4double G4PiMinusStopPb::eKin[11] = { 5.2, 15., 27., 41.5,
                                  49.6,
				  57.7, 79.3, 94.4, 114., 125., 140.};


// Opening angle distributions measured for coincident nucleon emission
// (P.Heusi et al., Nucl. Phys. A407 (1983) 429

G4int G4PiMinusStopPb::angleEntries = 7;

G4double G4PiMinusStopPb::angleData[7] = 
{ 1.43, 1.67, 2.62, 4.29, 7.62, 11.90, 14.76 };

G4double G4PiMinusStopPb::angle[8] = { 1.308997, 1.570796, 1.832596, 2.094395, 
				  2.356194, 2.617994, 2.967060, 3.1415927 };



// Constructor

G4PiMinusStopPb::G4PiMinusStopPb()
  
{
  // Cluster size: nucleon pair, alpha, triton etc.
  // First implementation: interaction with nucleon pair only
  _clusterSize = 2;

  // R ratio
  theR = 1. / (1. + npRatio);

  _definitions = new G4std::vector<G4ParticleDefinition*>();
  _momenta = new G4std::vector<G4LorentzVector*>();

  G4std::vector<double> eKinVector;
  G4std::vector<double> eKinDataVector;
  int i;
  for (i=0; i<eKinEntries; i++)
    {
      eKinVector.push_back(eKin[i]);
      eKinDataVector.push_back(eKinData[i]);
    }
  eKinVector.push_back(eKin[eKinEntries]);
  _distributionE = new G4DistributionGenerator(eKinVector,eKinDataVector);

  G4std::vector<double> angleVector;
  G4std::vector<double> angleDataVector;
  for (i=0; i<angleEntries; i++)
    {
      angleVector.push_back(angle[i]);
      angleDataVector.push_back(angleData[i]);
    }
  angleVector.push_back(angle[angleEntries]);
  _distributionAngle = new G4DistributionGenerator(angleVector,angleDataVector);
}


// Destructor

G4PiMinusStopPb::~G4PiMinusStopPb()
{}

G4double G4PiMinusStopPb::FinalNucleons()
{
  return nFinalNucleons;
}

