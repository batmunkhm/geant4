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
// $Id: G4GeometryMessenger.cc,v 1.10 2003/03/17 13:46:25 gcosmo Exp $
// GEANT4 tag $Name: geant4-05-01 $
//
// --------------------------------------------------------------------
// GEANT 4 class source file
//
// G4GeometryMessenger
//
// Author: G.Cosmo, CERN.
//
// ********************************************************************

#include "g4std/iomanip"
#include "G4GeometryMessenger.hh"

#include "G4TransportationManager.hh"
#include "G4GeometryManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Navigator.hh"

#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWith3Vector.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

#include "G4GeomTestStreamLogger.hh"
#include "G4GeomTestVolume.hh"

//
// Constructor
//
G4GeometryMessenger::G4GeometryMessenger(G4TransportationManager* tman)
  : x(0,0,0), p(0,0,1), newtol(false), tol(1E-4*mm),
    tmanager(tman), tlogger(0), tvolume(0)
{
  geodir = new G4UIdirectory( "/geometry/" );
  geodir->SetGuidance( "Geometry control commands." );

  //
  // Geometry navigator commands
  //
  navdir = new G4UIdirectory( "/geometry/navigator/" );
  navdir->SetGuidance( "Geometry navigator control setup." );

  resCmd = new G4UIcmdWithoutParameter( "/geometry/navigator/reset", this );
  resCmd->SetGuidance( "Reset navigator and navigation history." );
  resCmd->SetGuidance( "NOTE: must be called only after kernel has been" );
  resCmd->SetGuidance( "      initialized once through the run manager!" );
  resCmd->AvailableForStates(G4State_Idle);

  verbCmd = new G4UIcmdWithAnInteger( "/geometry/navigator/verbose", this );
  verbCmd->SetGuidance( "Set run-time verbosity for the navigator." );
  verbCmd->SetGuidance(" 0 : Silent (default)");
  verbCmd->SetGuidance(" 1 : Display positioning and relative states");
  verbCmd->SetGuidance(" 2 : Display step/safety info on point location");
  verbCmd->SetGuidance(" 3 : Display state at -every- step!");
  verbCmd->SetGuidance(" 4 : Maximum verbosity (very detailed!)");
  verbCmd->SetGuidance( "NOTE: this command has effect -only- if Geant4 has" );
  verbCmd->SetGuidance( "      been installed with the G4VERBOSE flag set!" );
  verbCmd->SetParameterName("level",true);
  verbCmd->SetDefaultValue(0);
  verbCmd->SetRange("level >=0 && level <=4");

  //
  // Geometry verification test commands
  //
  testdir = new G4UIdirectory( "/geometry/test/" );
  testdir->SetGuidance( "Geometry verification control setup." );
  testdir->SetGuidance( "Helps in detecting possible overlapping regions." );

  tolCmd = new G4UIcmdWithADoubleAndUnit( "/geometry/test/tolerance",this );
  tolCmd->SetGuidance( "Set error tolerance value." );
  tolCmd->SetGuidance( "Default: 1E-4*mm." );
  tolCmd->SetParameterName( "Tolerance", true, true );
  tolCmd->SetDefaultUnit( "mm" );
  tolCmd->SetUnitCategory( "Length" );

  posCmd = new G4UIcmdWith3VectorAndUnit( "/geometry/test/position", this );
  posCmd->SetGuidance( "Set starting position." );
  posCmd->SetParameterName( "X", "Y", "Z", true, true );
  posCmd->SetDefaultUnit( "cm" );

  dirCmd = new G4UIcmdWith3VectorAndUnit( "/geometry/test/direction", this );
  dirCmd->SetGuidance( "Set momentum direction." );
  dirCmd->SetGuidance( "Direction needs not to be a unit vector." );
  dirCmd->SetParameterName( "Px", "Py", "Pz", true, true );
  dirCmd->SetRange( "Px != 0 || Py != 0 || Pz != 0" );

  linCmd = new G4UIcmdWithoutParameter( "/geometry/test/line_test", this );
  linCmd->SetGuidance( "Performs test along a single specified direction/position." );
  linCmd->SetGuidance( "Use position and direction commands to change default." );
  linCmd->SetGuidance( "Default: position(0,0,0), direction(0,0,1)." );
  linCmd->AvailableForStates(G4State_Idle);

  grdCmd = new G4UIcmdWithoutParameter( "/geometry/test/grid_test", this );
  grdCmd->SetGuidance( "Start running the default grid test." );
  grdCmd->SetGuidance( "A grid of lines parallel to a cartesian axis is used;" );
  grdCmd->SetGuidance( "Only direct daughters of the mother volumes are checked." );
  grdCmd->AvailableForStates(G4State_Idle);

  recCmd = new G4UIcmdWithoutParameter( "/geometry/test/recursive_test", this );
  recCmd->SetGuidance( "Start running the recursive grid test." );
  recCmd->SetGuidance( "A grid of lines along a cartesian axis is recursively" );
  recCmd->SetGuidance( "to all daughters and daughters of daughters, etc." );
  recCmd->SetGuidance( "WARNING: it may take a very long time, depending on geometry complexity !");
  recCmd->AvailableForStates(G4State_Idle);

  cylCmd = new G4UIcmdWithoutParameter( "/geometry/test/cylinder_test", this );
  cylCmd->SetGuidance( "Start running the cylinder test." );
  cylCmd->SetGuidance( "A set of lines in a cylindrical pattern of gradually" );
  cylCmd->SetGuidance( "increasing mesh size." );
  cylCmd->AvailableForStates(G4State_Idle);

  runCmd = new G4UIcmdWithoutParameter( "/geometry/test/run", this );
  runCmd->SetGuidance( "Start running the default grid test." );
  runCmd->SetGuidance( "Same as the grid_test command." );
  runCmd->AvailableForStates(G4State_Idle);
}

//
// Destructor
//
G4GeometryMessenger::~G4GeometryMessenger()
{
  delete linCmd;
  delete posCmd;
  delete dirCmd;
  delete grdCmd;
  delete recCmd;
  delete cylCmd;
  delete runCmd;
  delete resCmd;
  delete verbCmd;
  delete tolCmd;
  delete geodir;
  delete navdir;
  delete testdir;
  delete tvolume;
  delete tlogger;
}

//
// Init
//
void
G4GeometryMessenger::Init()
{
  // Clean old allocated loggers...
  //
  if (tlogger) delete tlogger;
  if (tvolume) delete tvolume;

  // Create a logger to send errors/output to cout
  //
  tlogger = new G4GeomTestStreamLogger(G4std::cout);

  // Get the world volume
  //
  G4VPhysicalVolume* world =
    tmanager->GetNavigatorForTracking()->GetWorldVolume();

  // Test the actual detector...
  //
  tvolume = new G4GeomTestVolume(world, tlogger);
}

//
// SetNewValue
//
void
G4GeometryMessenger::SetNewValue( G4UIcommand* command, G4String newValues )
{
  if (command == resCmd) {
    ResetNavigator();
  }
  else if (command == verbCmd) {
    SetVerbosity(newValues);
  }
  else if (command == posCmd) {
    x = posCmd->GetNew3VectorValue( newValues );
  }
  else if (command == dirCmd) {
    p = dirCmd->GetNew3VectorValue( newValues );
    if (p.mag() < DBL_MIN) {
      G4cerr << "Please specify non-zero momentum" << G4endl;
      p = G4ThreeVector(0,0,1);
    }
  }
  else if (command == tolCmd) {
    tol = tolCmd->GetNewDoubleValue( newValues );
    newtol = true;
  }
  else if (command == linCmd) {
    Init();
    LineTest();
  }
  else if ((command == grdCmd) || (command == runCmd)){
    Init();
    GridTest();
  }
  else if (command == recCmd) {
    Init();
    RecursiveGridTest();
  }
  else if (command == cylCmd) {
    Init();
    CylinderTest();
  }
}

//
// GetCurrentValue
//
G4String
G4GeometryMessenger::GetCurrentValue(G4UIcommand* command )
{
  G4String cv = "";
  if (command == posCmd) {
    cv = posCmd->ConvertToString( x, "cm" );
  }
  else if (command == tolCmd) {
    cv = tolCmd->ConvertToString( tol, "mm" );
  }
  else if (command == dirCmd) {
    cv = dirCmd->ConvertToString( p, "GeV" );
  }
  return cv;
}

//
// CheckGeometry
//
void
G4GeometryMessenger::CheckGeometry()
{
  // Verify that the geometry is closed
  //
  G4GeometryManager* geomManager = G4GeometryManager::GetInstance();
  if (!geomManager->IsGeometryClosed()) {
    geomManager->CloseGeometry(true);
  }	
}

//
// ResetNavigator
//
void
G4GeometryMessenger::ResetNavigator()
{
  // Close geometry if necessary
  //
  CheckGeometry();

  // Reset navigator's state
  //
  G4ThreeVector pt(0,0,0);
  tmanager->GetNavigatorForTracking()->LocateGlobalPointAndSetup(pt,0,false);
}

//
// Set navigator verbosity
//
void
G4GeometryMessenger::SetVerbosity(G4String input)
{
  G4int level = verbCmd->GetNewIntValue(input);
  G4Navigator* navigator = tmanager->GetNavigatorForTracking();
  navigator->SetVerboseLevel(level);
}

//
// LineTest
//
void
G4GeometryMessenger::LineTest()
{
  // Close geometry if necessary
  //
  CheckGeometry();

  // Verify if error tolerance has changed
  //
  if (newtol) tvolume->SetTolerance(tol);

  // Make test on single line supplied by user
  //
  tvolume->TestOneLine( x, p );

  // Print out any errors, if found
  //
  tvolume->ReportErrors();
}

//
// GridTest
//
void
G4GeometryMessenger::GridTest()
{
  // Close geometry if necessary
  //
  CheckGeometry();

  // Verify if error tolerance has changed
  //
  if (newtol) tvolume->SetTolerance(tol);

  // Apply default set of trajectories in a 3D grid pattern
  //
  tvolume->TestCartGridXYZ();
  
  // Print out any errors, if found
  //
  tvolume->ReportErrors();
}

//
// RecursiveGridTest
//
void
G4GeometryMessenger::RecursiveGridTest()
{
  // Close geometry if necessary
  //
  CheckGeometry();

  // Verify if error tolerance has changed
  //
  if (newtol) tvolume->SetTolerance(tol);

  // Apply default set of trajectories in a 3D grid pattern recursively
  //
  tvolume->TestRecursiveCartGrid();
  
  // Print out any errors, if found
  //
  tvolume->ReportErrors();
}

//
// CylinderTest
//
void
G4GeometryMessenger::CylinderTest()
{
  // Close geometry if necessary
  //
  CheckGeometry();

  // Verify if error tolerance has changed
  //
  if (newtol) tvolume->SetTolerance(tol);

  // Apply default set of lines in a cylindrical pattern of gradually
  // increasing mesh size of trajectories in a 3D grid pattern recursively
  //
  tvolume->TestCylinder();
  
  // Print out any errors, if found
  //
  tvolume->ReportErrors();
}
