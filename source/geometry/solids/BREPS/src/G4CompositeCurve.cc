// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4CompositeCurve.cc,v 1.8 2000/11/20 17:54:39 gcosmo Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// ----------------------------------------------------------------------
// GEANT 4 class source file
//
// G4CircularCurve.cc
//
// ----------------------------------------------------------------------

#include "G4CompositeCurve.hh"
#include "G4Line.hh"


G4CompositeCurve::G4CompositeCurve(){}

G4CompositeCurve::G4CompositeCurve(const G4Point3DVector& vertices)
{
  G4CurveVector cv;
  for (size_t i=0; i<vertices.length(); i++) 
  {
    G4Point3D p1= vertices[i];
    G4Point3D p2= vertices[(i+1) % vertices.length()];
    
    G4Line* l= new G4Line;
    l->Init(p1, p2-p1);
    l->SetBounds(p1, p2);
    cv.insert(l);
  }
  
  Init(cv);
}

G4CompositeCurve::~G4CompositeCurve()
{
  segments.clearAndDestroy();
}

G4String G4CompositeCurve::GetEntityType() const 
{
  return G4String("G4CompositeCurve");
}

G4Curve* G4CompositeCurve::Project(const G4Transform3D& tr)
{
  G4CurveVector newSegments;
  
  for (size_t i=0; i<segments.entries(); i++) 
  {
    G4Curve* c= segments[i]->Project(tr);
    if (c==0) 
    {
      newSegments.clearAndDestroy();
      return 0;
    }

    newSegments.insert(c);
  }
  
  G4CompositeCurve* r= new G4CompositeCurve;
  r->Init(newSegments);
  return r;
}

/////////////////////////////////////////////////////////////////////////////

G4double G4CompositeCurve::GetPMax() const
{
  G4Exception("G4CompositeCurve::GetPMax");
  return 0;
}

G4Point3D G4CompositeCurve::GetPoint(G4double param) const
{
  G4Exception("G4CompositeCurve::GetPoint");
  // Fake return value
  return G4Point3D();
}

G4double G4CompositeCurve::GetPPoint(const G4Point3D& pt) const
{
  G4Exception("G4CompositeCurve::GetPPoint");
  return 0;
}

////////////////////////////////////////////////////////////////////////////

/*
void G4CompositeCurve::IntersectRay2D(const G4Ray& ray,
				      G4CurveRayIntersection& is)
{
  is.Reset();
 
  for (G4int i=0; i<segments.entries(); i++) 
  {
    G4Curve& c= *(segments(i));
    G4CurveRayIntersection isTmp(c, ray);
    c.IntersectRay2D(ray, isTmp);
    if (isTmp.GetDistance() < is.GetDistance()) 
      is= isTmp;  
  }
  
  lastIntersection= is;
}
*/

G4int G4CompositeCurve::IntersectRay2D(const G4Ray& ray)
{
  G4int nbinter = 0;
  G4int temp = 0;
 
  for (size_t i=0; i<segments.entries(); i++) 
  {
    G4Curve& c= *(segments(i));
    temp = c.IntersectRay2D(ray);

    // test if the point is on the composite curve
    if( temp == 999 )
       return 999;
     else
       nbinter+= temp; 
  }
 
  return nbinter;
}

G4bool G4CompositeCurve::Tangent(G4CurvePoint& cp, G4Vector3D& v)
{
  if (lastIntersection.GetDistance() == kInfinity) 
    return false;
  
  return lastIntersection.GetCurve().Tangent(lastIntersection, v);
  // should be true 
  // cp is ignored for the moment
}


void G4CompositeCurve::InitBounded()
{
  const G4BoundingBox3D* b= segments[0]->BBox();
  bBox.Init(b->GetBoxMin(), b->GetBoxMax());
  
  for (size_t i=1; i<segments.entries(); i++) 
  {
    b= segments[i]->BBox();
    bBox.Extend(b->GetBoxMin());
    bBox.Extend(b->GetBoxMax());
  }
  
  // init for efficient parameter <-> 3D point conversions
}
