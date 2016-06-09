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
// $Id: G4SigmaPlusInelasticProcess.hh,v 1.6 2002/12/12 19:18:35 gunter Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
 // G4 Process: SigmaPlus Inelastic Process
 // J.L. Chuma, TRIUMF, 05-Nov-1996
 // Last modified: 03-Apr-1997

// Class Description
// Process for SigmaPlus Inelastic scattering; 
// to be used in your physics list in case you need this physics.
// Class Description - End

#ifndef G4SigmaPlusInelasticProcess_h
#define G4SigmaPlusInelasticProcess_h 1
 
//#include "G4HadronicInelasticProcess.hh"
#include "G4HadronInelasticProcess.hh"
 
// class G4SigmaPlusInelasticProcess : public G4HadronicInelasticProcess
 class G4SigmaPlusInelasticProcess : public G4HadronInelasticProcess
 {
 public:
    
    G4SigmaPlusInelasticProcess(
     const G4String& processName = "SigmaPlusInelastic" ) :
      //      G4HadronicInelasticProcess( processName, G4SigmaPlus::SigmaPlus() )
      G4HadronInelasticProcess( processName, G4SigmaPlus::SigmaPlus() )
    { }
    
    ~G4SigmaPlusInelasticProcess()
    { }
 };
 
#endif
