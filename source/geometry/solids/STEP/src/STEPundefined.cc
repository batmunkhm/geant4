

//



//
// $Id: STEPundefined.cc,v 1.3 1999/12/15 14:50:17 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//

/*
* NIST STEP Core Class Library
* clstepcore/STEPundefined.cc
* May 1995
* KC Morris
* David Sauder

* Development of this software was funded by the United States Government,
* and is not subject to copyright.
*/

/*  */

#include <stdio.h> // to get the BUFSIZ #define
#include <STEPundefined.h>
#include <STEPattribute.h>


/******************************************************************
 **    helping functions for reading unknown types		**/



Severity 
SCLundefined::StrToVal(const char *s, ErrorDescriptor *err)
{
    val = s;
    return SEVERITY_NULL;
}

Severity 
SCLundefined::StrToVal(G4std::istream &in, ErrorDescriptor *err)
{
    return STEPread(in, err);
}

Severity 
SCLundefined::STEPread(const char *s, ErrorDescriptor *err)
{
    G4std::istrstream in((char *) s);
    return STEPread(in, err);
}

Severity 
SCLundefined::STEPread(G4std::istream &in, ErrorDescriptor *err)
{
    char c = '\0';
    G4std::strstream ss;
    SCLstring str;

    int terminal = 0;

    in >> G4std::ws; // skip white space
    in >> c;
    if(c == '$')
    {
	val = "";
	CheckRemainingInput(in, err, "aggregate item", ",)");
    }
    else
	in.putback(c);

    while (!terminal)  
    {
	in.get(c);
	switch (c)  
	{
	  case '(':
	    in.putback(c);

	    PushPastImbedAggr(in, str, err);
	    ss << str.chars();
	    break;

	  case '\'':
	    in.putback(c);

	    PushPastString(in, str, err);
	    ss << str.chars();
	    break;

	  case ',':	
	    terminal = 1; // it's a STEPattribute separator
	    in.putback (c);
	    c = '\0';
	    break;

	  case ')':
	    in.putback (c);
	    terminal = 1; // found a valid delimiter
	    break;

	  case '\0':
	  case EOF:
	    terminal = 1; // found a valid delimiter
	    break;

	  default:
	    ss.put(c);
	    break;
	}

	if (!in.good ()) {
	    terminal =1;
	    c = '\0';  
	}
//	  if (!in.readable ()) terminal =1;
    }	  

    ss << G4std::ends;
    val = ss.str();

    err->GreaterSeverity(SEVERITY_NULL);
    return SEVERITY_NULL;
}

const char *
SCLundefined::asStr(SCLstring & s) const
{
    s = val.chars();
    return s.chars();
}

const char *
SCLundefined::STEPwrite(SCLstring &s)
{
    if(val.rep())
    {
	s = val.chars();
    }
    else 
	s = "$";
    return s.chars();
}

void 
SCLundefined::	STEPwrite (G4std::ostream& out)
{
    if(val.rep())
	out << val.chars();
    else 
	out << "$";
}

SCLundefined& 
SCLundefined::operator= (const SCLundefined& x)  
{
    SCLstring tmp;
    val = x.asStr(tmp);
    return *this;
}

SCLundefined& 
SCLundefined::operator= (const char * str)
{
    if (!str)
	val.set_null();
    else
	val = str;
    return *this;
}

SCLundefined::SCLundefined ()  
{
}

SCLundefined::~SCLundefined ()  
{
}

int
SCLundefined::set_null ()  
{
    val = "";
    return 1;
}

int
SCLundefined::is_null ()  
{
    return (!strcmp (val.chars(), ""));
    
}


/*
int
SCLundefined::STEPread(G4std::istream& in )  
{
    char c ='\0';
    char buf [BUFSIZ];
    int i =0;
    int open_paren =0;
    int terminal = 0;
    
    while (!terminal)  
      {
	  in >> c;
	  switch (c)  
	    {
	      case '(':
		++open_paren;
		break;
	      case ')':
		if (open_paren)  {
		      --open_paren;
		      break; 
		  }
		// otherwise treat it like a comma
	      case ',':
		if (!open_paren)  {
		    terminal =1;
		    in.putback (c);
		    c = '\0';
		}
		
		break;
	      case '\0':
		terminal =1;
		break;
		
	    }		

	  if (!in)
	  {
	      terminal =1;
	      c = '\0';  
	  }
	  if (i < BUFSIZ) buf [i] = c;

	  // BUG:  read up to BUFSIZ -1 number of characters
	  // if more characters, NULL Terminate and ignore the rest of input 
	  if ((++i == BUFSIZ) && !terminal)  {
	      G4cerr << "WARNING:  information lost -- value of undefined type is too long\n";
	      buf [i] = '\0';
	  }

      }	  
    if (i < BUFSIZ) buf [i+1] = '\0';
    val = buf;
    return i;
}
*/
