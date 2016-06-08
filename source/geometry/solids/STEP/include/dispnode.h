

//



//
// $Id: dispnode.h,v 1.2 1999/05/21 20:20:39 japost Exp $
// GEANT4 tag $Name: geant4-01-01 $
//

#ifndef dispnode_h
#define dispnode_h

/*
* NIST STEP Editor Class Library
* cleditor/dispnode.h
* May 1995
* David Sauder
* K. C. Morris

* Development of this software was funded by the United States Government,
* and is not subject to copyright.
*/

/*  */ 

#ifdef __O3DB__
#include <OpenOODB.h>
#endif

/*#include <STEPattribute.h>*/
/*#include <STEPentity.h>*/
#include <sdai.h>

#include <gennode.h>
#include <gennodelist.h>
#include <editordefines.h>
//#include <mgrnode.h>
class MgrNode;

//////////////////////////////////////////////////////////////////////////////
// class DisplayNode
//////////////////////////////////////////////////////////////////////////////

class DisplayNode : public GenericNode
{
protected:
    friend class GenNodeList;
    friend class DisplayNodeList;

    MgrNode *mn;
    void *see;
    displayStateEnum displayState; // = { mappedWrite, mappedView, notMapped }

public:
    // this should probably only be used to create head nodes for dispnodelists
    DisplayNode()	{ displayState = noMapState; }
    DisplayNode(MgrNode *node)	{ mn = node; displayState = noMapState; }
    ~DisplayNode();

    void SEE(void *s)		{ see = s; }
    virtual void *SEE()		{ return see; };

    void mgrNode(MgrNode *node)	{ mn = node; }
    class MgrNode *mgrNode()		{ return mn; }

    displayStateEnum DisplayState() 	    { return displayState; }
    int DisplayListMember(displayStateEnum ds) { return (displayState == ds); }

    int ChangeState(displayStateEnum s);
    int ChangeList(DisplayNodeList *cmdList);

    void Remove();

protected:
};

//////////////////////////////////////////////////////////////////////////////
// class DisplayNode inline functions
// these functions don't rely on any inline functions (its own or
//	other classes) that aren't in this file except for Generic functions
//////////////////////////////////////////////////////////////////////////////

#endif
