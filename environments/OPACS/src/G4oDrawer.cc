// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4oDrawer.cc,v 1.3.2.1.2.1 1999/12/07 20:46:52 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
/*
  From geant4/visualization/management/src/G4VisManager.cc.
*/
#include <stddef.h>

// GB : put this include before the GL ones. 
// It avoid a clash with STL includes on Linux.
#include "g4rw/tvhdict.h"

#include <G4oDrawer.hh>

/*G4*/
#include <G4Polyline.hh>
#include <G4VisAttributes.hh>

/*Go*/
#include <Go.h>

G4oDrawer* G4oDrawer::fpInstance = 0;
ONode      G4oDrawer::node       = NULL;
OColormap  G4oDrawer::colormap   = NULL;

/***************************************************************************/
G4oDrawer* G4oDrawer::GetInstance (
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
  if (!fpInstance) 
    {
      fpInstance         = new G4oDrawer;
      fpConcreteInstance = fpInstance;
    }
  return fpInstance;
}
/***************************************************************************/
G4oDrawer::G4oDrawer (
)
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
G4oDrawer::~G4oDrawer (
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::SetWorldVolume (
 G4VPhysicalVolume* world
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::EventBegins (
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::EventEnded  (
 G4Event * pEvent
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4Polyline& line
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
  SetColour  (line.GetVisAttributes()->GetColour());

  G4int      nPoints = line.entries (); 
  if(nPoints<=0) return;
  OPointList points  = OPointListCreate (nPoints);
  for (G4int iPoint = 0; iPoint < nPoints; iPoint++) 
    {
      OPointListSetIthEntry (points,iPoint,
			     (double)line(iPoint).x(), 
			     (double)line(iPoint).y(),
			     (double)line(iPoint).z());
  }
  if(nPoints==1)
    GoAddMarkersToNode (node,points);
  else
    GoAddLinesToNode   (node,points);
  OPointListDelete (points);
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4Text& text
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4Circle& circle
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4Square& Square
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4Polymarker& polymarker
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4Polyhedron& polyhedron
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4NURBS& nurbs
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4VSolid& solid
,const G4VisAttributes& attribs
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4LogicalVolume& logicalVol
,const G4VisAttributes& attribs
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::Draw (
 const G4VPhysicalVolume& physicalVol
,const G4VisAttributes& attribs
,const G4Transform3D& objectTransform
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}
/***************************************************************************/
void G4oDrawer::SetNode (
 ONode a_node
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
 node = a_node;
}
/***************************************************************************/
void G4oDrawer::SetColour (
 const G4Colour& a_colour
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
  if(colormap==NULL) colormap = OColormapGetIdentifier("ocolormap_X");
  int index = OColormapGetRGB_Index(colormap,a_colour.GetRed (), a_colour.GetGreen (), a_colour.GetBlue ());
  OContextSetColorIndex (OContextGetStaticInstance(),index);
}
/***************************************************************************/
void G4oDrawer::GeometryHasChanged (
) 
/***************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
{
}

