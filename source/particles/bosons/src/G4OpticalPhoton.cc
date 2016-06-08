// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpticalPhoton.cc,v 1.3 2000/02/27 06:27:12 kurasige Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// 
// ----------------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD Group
//      History: first implementation, based on object model of
//      4th April 1996, G.Cosmo 
//      by             H.Kurashige,17 Oct. 1996
// **********************************************************************
//  Changed name intto "opticalphoton" Hisaya Kurashige, 08 Jan 1998
// ----------------------------------------------------------------------

#include "g4std/fstream"
#include "g4std/iomanip"

#include "G4OpticalPhoton.hh"

// ######################################################################
// ###                         OPTICAL PHOTON                         ###
// ######################################################################

G4OpticalPhoton::G4OpticalPhoton(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable )
 : G4VBoson( aName,mass,width,charge,iSpin,iParity,
             iConjugation,iIsospin,iIsospin3,gParity,pType,
             lepton,baryon,encoding,stable,lifetime,decaytable )
{
   SetParticleSubType("photon");
   // Anti-particle of OpticalPhoton is OpticalPhoton itself
   SetAntiPDGEncoding(encoding);
}


// ......................................................................
// ...                 static member definitions                      ...
// ......................................................................
//     
//    Arguments for constructor are as follows
//               name             mass          width         charge
//             2*spin           parity  C-conjugation
//          2*Isospin       2*Isospin3       G-parity
//               type    lepton number  baryon number   PDG encoding
//             stable         lifetime    decay table 
//   !! PDG encoding is set to 0 because G4OpticalPhoton is not 
//   !! gamma which has PDG code of 22
G4OpticalPhoton G4OpticalPhoton::theOpticalPhoton(
      "opticalphoton",         0.0*MeV,       0.0*MeV,         0.0,
                    2,              -1,            -1,
                    0,               0,             0,
      "opticalphoton",               0,             0,         0,
                 true,             0.0,          NULL
);
// initialization for static cut values
G4double   G4OpticalPhoton::theOpticalPhotonLengthCut = -1.0;
G4double*  G4OpticalPhoton::theOpticalPhotonKineticEnergyCuts = NULL;

G4OpticalPhoton* G4OpticalPhoton::OpticalPhotonDefinition()
					{return &theOpticalPhoton;}

// **********************************************************************
// **************************** SetCuts *********************************
// **********************************************************************
//  In this version Input Cut Value is meaning less
//  theKineticEnergyCuts for all materials are set to Zero.
void G4OpticalPhoton::SetCuts(G4double aCut)
{
  theCutInMaxInteractionLength = aCut;

  const G4MaterialTable* materialTable = G4Material::GetMaterialTable();
  // Create the vector of cuts in energy
  // corresponding to the stopping range cut
  if(theKineticEnergyCuts) delete theKineticEnergyCuts;
  theKineticEnergyCuts = new G4double [materialTable->length()];

  // Build range vector for every material, convert cut into energy-cut,
  // fill theKineticEnergyCuts and delete the range vector
  for (G4int J=0; J<materialTable->length(); J++)
  {
    G4Material* aMaterial = (*materialTable)[J];
    theKineticEnergyCuts[J] = 0.0;
  }
  theOpticalPhotonLengthCut = theCutInMaxInteractionLength;  
  theOpticalPhotonKineticEnergyCuts = theKineticEnergyCuts;
  // Rebuild the physics tables for every process for this particle type
  
}
