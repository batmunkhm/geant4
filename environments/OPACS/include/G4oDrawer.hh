// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4oDrawer.hh,v 1.2.6.1 1999/12/07 20:46:51 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
/* +---------------------- Copyright notice -------------------------------+ */
/* | Copyright (C) 1995, Guy Barrand, LAL Orsay, (barrand@lal.in2p3.fr)    | */
/* |   Permission to use, copy, modify, and distribute this software       | */
/* |   and its documentation for any purpose and without fee is hereby     | */
/* |   granted, provided that the above copyright notice appear in all     | */
/* |   copies and that both that copyright notice and this permission      | */
/* |   notice appear in supporting documentation.  This software is        | */
/* |   provided "as is" without express or implied warranty.               | */
/* +---------------------- Copyright notice -------------------------------+ */

#ifndef G4ODRAWER_HH
#define G4ODRAWER_HH

#include <G4VVisManager.hh>

#include <ONode.h>
#include <OColormap.h>

class G4Event;
class G4Polyline;
class G4Text;
class G4Circle;
class G4Square;
class G4Polymarker;
class G4Polyhedron;
class G4NURBS;
class G4VSolid;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4VisAttributes;
class G4Colour;

class G4oDrawer: public G4VVisManager {

public:

  static G4oDrawer* GetInstance ();  // Access to private constructor.
  ~G4oDrawer ();

  void              SetWorldVolume           (G4VPhysicalVolume* world);

  void Draw (const G4Polyline&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4Text&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4Circle&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4Square&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4Polymarker&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4Polyhedron&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4NURBS&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  // Now Follow functions for drawing a GEANT4 geometry object.  Note
  // that the 2nd argument overrides any visualization attributes that
  // are associated with the object itself.

  void Draw (const G4VSolid&, const G4VisAttributes&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4LogicalVolume&, const G4VisAttributes&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void Draw (const G4VPhysicalVolume&, const G4VisAttributes&,
    const G4Transform3D& objectTransformation = G4Transform3D::Identity);

  void GeometryHasChanged ();

  //////////////////////////////////////////////////////////////////////
  // Timing messages.

  void EventBegins ();
  // All stacks are clear and event processing is about to start.

  void EventEnded  (G4Event* pEvent);
  // Event processing has ended and event-persistent data is available.

  void SetNode (ONode);

private:

  G4oDrawer ();                         // Private constructor.
  static G4oDrawer* fpInstance;         // Pointer to single instance.
  static ONode      node;
  static OColormap  colormap;
  void              SetColour         (const G4Colour&);
};


#endif




