// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4NURBSbox.cc,v 1.3 1999/12/15 14:50:35 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// 
// Olivier Crumeyrolle  12 September 1996

// Box builder implementation (KidBox)
// OC 060996

#include "G4NURBSbox.hh"

	G4NURBSbox::G4NURBSbox(G4double DX, G4double DY, G4double DZ)
		:
		G4NURBS	(
			2, 2,	// linear along U and V
			4, 5	// line with two 90 degrees folds along U
				// rectangle along V (3 folds)
			)
				// let's it Generate regular knots vector
				// (note we are calling the second constructor)
		{
		t_indCtrlPt i = 0;


		CP(mpCtrlPts[i++], DX, DY, DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY, DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY,-DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY,-DZ, 1 ); 

		CP(mpCtrlPts[i++], DX, DY, DZ, 1 ); 
		CP(mpCtrlPts[i++],-DX, DY, DZ, 1 ); 
		CP(mpCtrlPts[i++],-DX, DY,-DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY,-DZ, 1 ); 

		CP(mpCtrlPts[i++], DX,-DY, DZ, 1 ); 
		CP(mpCtrlPts[i++],-DX,-DY, DZ, 1 ); 
		CP(mpCtrlPts[i++],-DX,-DY,-DZ, 1 ); 
		CP(mpCtrlPts[i++], DX,-DY,-DZ, 1 ); 

		CP(mpCtrlPts[i++], DX,-DY, DZ, 1 ); 
		CP(mpCtrlPts[i++], DX,-DY, DZ, 1 ); 
		CP(mpCtrlPts[i++], DX,-DY,-DZ, 1 ); 
		CP(mpCtrlPts[i++], DX,-DY,-DZ, 1 ); 

		CP(mpCtrlPts[i++], DX, DY, DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY, DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY,-DZ, 1 ); 
		CP(mpCtrlPts[i++], DX, DY,-DZ, 1 ); 

		


		
		}

G4Visible & G4NURBSbox::operator = (const G4Visible &right) {
  return G4Visible::operator = (right);
}

G4VVisPrim & G4NURBSbox::operator = (const G4VVisPrim &right) {
  return G4VVisPrim::operator = (right);
}

const char*	G4NURBSbox::Whoami() const
		{
		return "Box (as a folded piece)";
		}





