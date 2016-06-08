// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VPartonStringModel.cc,v 1.4.4.1.2.2 1999/12/09 17:37:01 gcosmo Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
//// ------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD group
//      ---------------- G4VPartonStringModel ----------------
//             by Gunter Folger, May 1998.
//      abstract class for all Parton String Models
// ------------------------------------------------------------

// Modified at 8-Oct-1998 by Maxim Komogorov. Method EnergyAndMomentumCorrector was added.


#include "G4VPartonStringModel.hh"
#include "G4ios.hh"
#include "G4ShortLivedConstructor.hh"


G4VPartonStringModel::G4VPartonStringModel()
{
//  Make shure Shotrylived partyicles are constructed.
	G4ShortLivedConstructor ShortLived;
	ShortLived.ConstructParticle();
}

G4VPartonStringModel::G4VPartonStringModel(const G4VPartonStringModel &right)
{
}


G4VPartonStringModel::~G4VPartonStringModel()
{
}


const G4VPartonStringModel & G4VPartonStringModel::operator=(const G4VPartonStringModel &right)
{
  G4Exception("G4VPartonStringModel::operator= meant to not be accessable");
  return *this;
}


int G4VPartonStringModel::operator==(const G4VPartonStringModel &right) const
{
 return 0;
}

int G4VPartonStringModel::operator!=(const G4VPartonStringModel &right) const
{
  return 1;
}

G4KineticTrackVector * G4VPartonStringModel::Scatter(const G4Nucleus &theNucleus, 
                                                const G4DynamicParticle &aPrimary)
{  
  G4ExcitedStringVector * strings = NULL;

  G4DynamicParticle thePrimary=aPrimary;
  
  G4LorentzRotation toZ;
  G4LorentzVector Ptmp=thePrimary.Get4Momentum();
  toZ.rotateZ(-1*Ptmp.phi());
  toZ.rotateY(-1*Ptmp.theta());
  thePrimary.Set4Momentum(toZ*Ptmp);
  G4LorentzRotation toLab(toZ.inverse());

  G4int attempts = 0, maxAttempts=20;
  while ( strings  == NULL )
  {
  	if (attempts++ > maxAttempts ) 
  	{
		G4Exception("G4VPartonStringModel::Scatter(): fails to generate strings");
  	}

	theThis->Init(theNucleus,thePrimary);
  	strings = GetStrings();
  }
  
//  G4cout << "Number of strings " << strings->entries() << G4endl << G4endl;

  G4KineticTrackVector * theResult = new G4KineticTrackVector;

  G4LorentzVector KTsum;
  G4bool NeedEnergyCorrector=false;
  
  for ( G4int astring=0; astring < strings->entries(); astring++)
  {
//    rotate string to lab frame, models have it aligned to z
  	strings->at(astring)->LorentzRotate(toLab);
  	
	KTsum+= strings->at(astring)->Get4Momentum();
        G4KineticTrackVector * generatedKineticTracks = NULL;

// 	G4cout << " strings["<<astring<<"] Momentum " << strings->at(astring)->Get4Momentum() << G4endl; 	
// 	G4cout << " strings["<<astring<<"] Mass     " << strings->at(astring)->Get4Momentum().mag() << G4endl;
//  	G4cout << " strings["<<astring<<"] Position " << strings->at(astring)->GetPosition() << G4endl;
// 	G4cout << "Parton Left  " << strings->at(astring)->GetLeftParton()->Get4Momentum() << G4endl;
// 	G4cout << " code " << strings->at(astring)->GetLeftParton()->GetPDGcode()<< G4endl;
// 	G4cout << "Parton Right  " << strings->at(astring)->GetRightParton()->Get4Momentum() << G4endl;
// 	G4cout << " code " << strings->at(astring)->GetRightParton()->GetPDGcode()<< G4endl;
  
	if ( strings->at(astring)->IsExcited() )
	{
  	     generatedKineticTracks=stringFragmentationModel->FragmentString(*strings->at(astring));
	} else {
	     generatedKineticTracks = new G4KineticTrackVector;
	     generatedKineticTracks->insert(strings->at(astring)->GetKineticTrack());
	}    

//	G4cout <<" number of generated tracks : " << generatedKineticTracks->entries() << G4endl;

	if (generatedKineticTracks == NULL) 
	{
		G4cout << "G4VPartonStringModel:No KineticTracks produced" << G4endl;
		continue;
	}
	
// 	if ( generatedKineticTracks->entries() == 1 ) 
// 	{
// 		G4cout << " Only one track created, mass " 
// 		       << generatedKineticTracks->at(0)->Get4Momentum().mag() << G4endl;
// 		       
// 		G4cout << " strings["<<astring<<"] Momentum " << strings->at(astring)->Get4Momentum() << G4endl;
// 		G4cout << " strings["<<astring<<"] Mass     " << strings->at(astring)->Get4Momentum().mag() << G4endl;
// 		
// 	}
	G4LorentzVector KTsum1;
	for ( G4int aTrack=0; aTrack<generatedKineticTracks->entries();aTrack++)
	{
		theResult->insert(generatedKineticTracks->at(aTrack));
		KTsum1+= (*generatedKineticTracks)[aTrack]->Get4Momentum();

// 		G4cout << " Momentum/ Mass " <<
// 		(*generatedKineticTracks)[aTrack]->Get4Momentum() << 
// 		" / " << (*generatedKineticTracks)[aTrack]->Get4Momentum().mag()
// 		<< G4endl;
// 		G4cout << " Position " <<
// 		(*generatedKineticTracks)[aTrack]->GetPosition() 
// 		<< G4endl;

	}
	
//	G4cout << " KTsum Momentum " << KTsum << G4endl;
//	G4cout << " KTsum  Mass     " << KTsum.mag() << G4endl;
	
	if  ( abs((KTsum1.e()-strings->at(astring)->Get4Momentum().e()) / KTsum1.e()) > perMillion ) 
	{
	   NeedEnergyCorrector=true;
	   
// 	   G4cout << " strings["<<astring<<"] Momentum " << strings->at(astring)->Get4Momentum() << G4endl;  
//  	   G4cout << " strings["<<astring<<"] Mass     " << strings->at(astring)->Get4Momentum().mag() << G4endl;
//  	   G4cout <<" number of generated tracks : " << generatedKineticTracks->entries() << G4endl;
// 	   for ( G4int bTrack=0; bTrack<generatedKineticTracks->entries();bTrack++)
// 	   {
// 	   	G4cout << " Particle : " << 
// 	   	   (*generatedKineticTracks)[bTrack]->GetDefinition()->GetParticleName()
// 	   	   << G4endl;
// 		G4cout << " Momentum " <<
// 		   (*generatedKineticTracks)[bTrack]->Get4Momentum()
// 		   << G4endl;
// 		G4cout << "  Mass " <<
// 		   (*generatedKineticTracks)[bTrack]->Get4Momentum().mag()
// 		   << G4endl;
// 	   }
// 		 
 	}
//      clean up
	delete generatedKineticTracks;
  }
  
  if ( NeedEnergyCorrector ) EnergyAndMomentumCorrector(theResult, KTsum);
  
  strings->clearAndDestroy();
  delete strings;
  
  return theResult;
}

//*********************************************************************************************** 
// This method was implemented by Maxim Komogorov
// Maxim.Komogorov@cern.ch
// This method was implemented by Maxim Komogorov
// Maxim.Komogorov@cern.ch

G4bool G4VPartonStringModel::EnergyAndMomentumCorrector(G4KineticTrackVector* Output, G4LorentzVector& TotalCollisionMom)   
    {
    const int    nAttemptScale = 500;
    const double ErrLimit = 1.E-5;
    if (Output->isEmpty())
       return TRUE;
    G4LorentzVector SumMom;
    G4double        SumMass = 0;     
    G4double        TotalCollisionMass = TotalCollisionMom.m(); 
    // Calculate sum hadron 4-momenta and summing hadron mass
    G4int cHadron;
    for(cHadron = 0; cHadron < Output->length(); cHadron++)
        {
        SumMom  += Output->at(cHadron)->Get4Momentum();
        SumMass += Output->at(cHadron)->GetDefinition()->GetPDGMass();
        }
    if (SumMass > TotalCollisionMass) return FALSE;
    SumMass = SumMom.m2();
    if (SumMass < 0) return FALSE;
    SumMass = sqrt(SumMass);

     // Compute c.m.s. hadron velocity and boost KTV to hadron c.m.s.
    G4ThreeVector Beta = -SumMom.boostVector();
    Output->Boost(Beta);

    // Scale total c.m.s. hadron energy (hadron system mass).
    // It should be equal interaction mass
    G4double Scale = 1;
    for(G4int cAttempt = 0; cAttempt < nAttemptScale; cAttempt++)
        {
        G4double Sum = 0;
        for(cHadron = 0; cHadron < Output->length(); cHadron++)
            {
            G4LorentzVector HadronMom = Output->at(cHadron)->Get4Momentum();
            HadronMom.setVect(Scale*HadronMom.vect());
            G4double E = sqrt(HadronMom.vect().mag2() + sqr(Output->at(cHadron)->GetDefinition()->GetPDGMass()));
            HadronMom.setE(E);
            Output->at(cHadron)->Set4Momentum(HadronMom);
            Sum += E;
            }   
        Scale = TotalCollisionMass/Sum;    
        if (Scale - 1 <= ErrLimit) goto LTRUE;
        }
    
    G4cout << "G4VPartonStringModel::EnergyAndMomentumCorrector"<<G4endl;
    G4cout << "   Increase number of attempts or increase ERRLIMIT"<<G4endl;
 
 LTRUE:   
    // Compute c.m.s. interaction velocity and KTV back boost   
    Beta = TotalCollisionMom.boostVector(); 
    Output->Boost(Beta);
    return TRUE;
    }

//*********************************************************************************************** 


