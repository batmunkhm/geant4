// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmSeparator.hh,v 1.3 1999/12/15 14:54:06 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
//Separator class. Inherits from G4OpenGLXmVWidgetComponent

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#ifndef G4OPENGLXMSEPARATOR_HH
#define G4OPENGLXMSEPARATOR_HH

#include "G4OpenGLXmVWidgetComponent.hh"

class G4OpenGLXmSeparator : public G4OpenGLXmVWidgetComponent
{

public:
  G4OpenGLXmSeparator (unsigned char = XmSINGLE_LINE);           //constructor
  ~G4OpenGLXmSeparator ();                                       //destructor

  void AddYourselfTo (G4OpenGLXmVWidgetContainer*);

  Widget* GetPointerToParent ();
  Widget* GetPointerToWidget ();

private:
  unsigned char line_type;
  Widget line;
  Widget* parent;
};

#endif

#endif
