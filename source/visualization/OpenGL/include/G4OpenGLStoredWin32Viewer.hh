// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLStoredWin32Viewer.hh,v 1.2 1999/12/15 14:54:04 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// 
// Class G4OpenGLStoredWin32Viewer : a class derived from
//   G4OpenGLWin32Viewer and G4OpenGLStoredViewer.

#ifdef G4VIS_BUILD_OPENGLWIN32_DRIVER

#ifndef G4OPENGLSTOREDWIN32VIEWER_HH
#define G4OPENGLSTOREDWIN32VIEWER_HH

#include "G4VViewer.hh"
#include "G4OpenGLStoredViewer.hh"
#include "G4OpenGLWin32Viewer.hh"

class G4OpenGLStoredSceneHandler;

class G4OpenGLStoredWin32Viewer:
public G4OpenGLWin32Viewer, public G4OpenGLStoredViewer{
  
public:
  G4OpenGLStoredWin32Viewer (G4OpenGLStoredSceneHandler& scene);
  void DrawView ();
};

#endif

#endif

