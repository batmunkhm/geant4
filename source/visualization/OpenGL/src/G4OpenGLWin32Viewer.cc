// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLWin32Viewer.cc,v 1.2 1999/12/15 14:54:09 gunter Exp $
// GEANT4 tag $Name: geant4-03-00 $
//
// 
// G4OpenGLWin32Viewer : Class to provide WindowsNT specific
//                     functionality for OpenGL in GEANT4

#ifdef G4VIS_BUILD_OPENGLWIN32_DRIVER

#include "G4OpenGLWin32Viewer.hh"

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include "G4ios.hh"
#include <assert.h>
#include <unistd.h>

#include "G4VisExtent.hh"
#include "G4LogicalVolume.hh"
#include "G4VSolid.hh"
#include "G4Point3D.hh"
#include "G4Normal3D.hh"

void G4OpenGLWin32Viewer::FinishView () {

  //Wait for GL commands to exit before going on...
  //Swap buffers if double buffered...
  //Flush GL commands...

}

void G4OpenGLWin32Viewer::GetWin32Connection () {
// get a connection.
}

void G4OpenGLWin32Viewer::CreateGLWin32Context () {
// create a GL context
// set attributes of window now the GL context has been created

}

void G4OpenGLWin32Viewer::CreateMainWindow () {
  
// create a window
// connect the context to a window

}

G4OpenGLWin32Viewer::G4OpenGLWin32Viewer (G4OpenGLSceneHandler& scene):
G4VViewer (scene, -1),
G4OpenGLViewer (scene)
{
  GetWin32Connection ();
  if (fViewId < 0) return;
  
  // Try for a visual suitable for OpenGLImmediate..
  // first try for a single buffered RGB window
  // next try for a double buffered RGB, but Draw to top buffer


  // Now try for a visual suitable for OpenGLStored...
  // Try for a double buffered RGB window
  
}

G4OpenGLWin32Viewer::~G4OpenGLWin32Viewer () {
  if (fViewId >= 0) {
    //Close a window from here
    //destroy GL context
    //make NULL context current
    //destroy the Win32 window
  }
}

#endif
