// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmConvenienceRoutines.hh,v 1.3 1999/12/15 14:54:05 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
//

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#ifndef G4OPENGLXMCONVENIENCEROUTINES_HH
#define G4OPENGLXMCONVENIENCEROUTINES_HH

#include "G4OpenGLXmViewer.hh"

// Methods contained in G4OpenGLXmConvenienceRoutines:
//
// 1) Add_four_arrow_buttons
// 2) Add_radio_box
// 3) Add_set_field
// 4) Add_slider_box
// 5) get_float_value_callback
//
// Description of methods in G4OpenGLXmConvenienceRoutines:
//
// 1) Add_four_arrow_buttons (G4OpenGLXmViewer* pView,
//			      XtCallbackProc* arrow_callbacks,
//			      Widget* parent_widget)
//
//    Adds a form widget containing four arrows (up, down, left, right)
//    to the row column parent_widget which is passed in the arguments 
//    List. The XtCallbackProc* is an array containing four callback
//    proceedures to be registered with the up, down, left and right arrow
//    widgets respectively.
//
// 2) Add_radio_box (char* label_string,
//                  Widget* parent_widget, 
//      	    XtCallbackProc radio_box_callback, 
//	            G4int num_buttons, 
//	            G4int default_button, 
//	            char* radio_box_name, 
//	            char** button_names, 
//	            G4OpenGLXmViewer* pView);
//
//    Adds a row column widget containing num_buttons toggle buttons, to the
//    row column parent_widget passed in the arguments List. label_string is
//    the title that gets written above the radio buttons, and radio_box_name
//    is used by the compiler, to give the radio_box a name to refer to, e.g.
//    for resource setting, or error information. default_button is the button
//    which appears `clicked' when the radio_box first appears. The first char*
//    object in the button_names array, gets written next to the first button, 
//    the second next to the second, etc. radio_box_callback is the 
//    XtCallbackProc callback proceedure, which is registered with all of the 
//    buttons. XmNuserData is set to the index (0, 1,.., (num_buttons -1)) of 
//    the calling button so that radio_box_callback can tell which button was
//    clicked, and what to do as a consequence.
//
// 3) Add_set_field (char* widget, 
//                   char* widget_text, 
//                   Widget* row_col_box, 
//		     Widget* wid, 
//		     G4float* val, 
//		     G4OpenGLXmViewer* pView);
//
//    Adds a text field widget to the row_col_box supplied in the arguments
//    List. widget goes towards giving the widgets created within Add_set_field
//    names for reference (e.g. to set resources) and widget_text gets printed
//    above the text field box. val is the variable into which a number typed
//    into the text field widget, will get placed. Add_set_field uses the 
//    get_float_value also in this file.
//
// 4) Add_slider_box (char* label_string,
//		      G4int num_sliders,
//		      char** slider_names,
//		      G4OpenGLXmViewer* pView,
//		      G4float* min_array,
//		      G4float* max_array,
//		      G4float* value_array,
//		      G4bool* show,
//		      short* decimals,
//		      unsigned char* orientation,
//		      unsigned char* direction,
//		      XtCallbackProc* slider_box_callbacks,
//		      Widget* parent_widget);
//
//    Adds a row column widget containing num_sliders scale widgets, to the
//    row column widget specified by parent_widget. Each of the arrays, 
//    slider_names, min_array, max_array, value_array, show, decimals, 
//    orientation, direction and slider_box_callbacks contains num_sliders
//    elements, and govern the properties of each scale widget placed within
//    the slider box individually. The relevance of most of the arrays is self
//    explanatory. 
//    - value_array contains the initial value for each scale widget. 
//    - show determines whether or not the current numerical value represented 
//    by the position of the slider bar on the scale widget is displayed. 
//    - decimals indicates the Power of ten, by which to divide the current 
//    scale widget value, before displaying it (if show is set) above the 
//    slider bar. Scale widgets can only have integer values, but the use 
//    of decimals and show can give the appearance of the scale widget having
//    a floating point value. 
//    - The XtCallbackProc specified in slider_box_callbacks is registered for
//    both XmNvalueChanged and XmNdrag events generated by the scale widget.
//
// 5) get_float_value_callback (Widget w, 
//			       XtPointer clientData, 
//			       XtPointer callData);
//
//    This XtCallbackProc reads a character string from a text field widget, 
//    and converts it to a floating point number.

void Add_four_arrow_buttons (G4OpenGLXmViewer* pView,
			     XtCallbackProc* arrow_callbacks,
			     Widget* parent_widget);

void Add_radio_box (char* label_string,
		    Widget* parent_widget, 
		    XtCallbackProc radio_box_callback, 
		    G4int num_buttons, 
		    G4int default_button, 
		    char* radio_box_name, 
		    char** button_names, 
		    G4OpenGLXmViewer* pView);
		    
void Add_set_field (char* widget, 
		    char* widget_text, 
		    Widget* row_col_box, 
		    Widget* wid, 
		    G4float* val, 
		    G4OpenGLXmViewer* pView);

void Add_slider_box (char* label_string,
		     G4int num_sliders,
		     char** slider_names,
		     G4OpenGLXmViewer* pView,
		     G4float* min_array,
		     G4float* max_array,
		     G4float* value_array,
		     G4bool* show,
		     short* decimals,
		     unsigned char* orientation,
		     unsigned char* direction,
		     XtCallbackProc* slider_box_callbacks,
		     Widget* parent_widget);
		    
void get_float_value_callback (Widget w, 
			       XtPointer clientData, 
			       XtPointer callData);

#endif

#endif
