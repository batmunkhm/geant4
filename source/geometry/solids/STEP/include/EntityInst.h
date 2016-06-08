

//



//
// $Id: EntityInst.h,v 1.2 1999/05/21 20:20:28 japost Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
#ifndef ENTITYINST_H
#define	ENTITYINST_H 1

// This entity is the supertype of all entities whose instances may be 
// queried or manipulated through the SDAI (i.e., application schema 
// entities, SDAI session schema entities, and SDAI dictionary schema 
// entities).

typedef class EntityInstance* EntityInstanceH;

class EntityInstance  {

//friend class SdaiInstance;
//friend class AppInstance;

public:
EntityInstance() {}
//EntityInstance(const EntityInstance&);

virtual ~EntityInstance() {}

public:

//const ModelH FindEntityInstanceModel() const;

//virtual Boolean IsInstanceOf(const String& typeName) const; 

//virtual Boolean IsKindOf(const String& typeName) const;

//virtual Boolean IsSDAIKindOf(const String& typeName) const;

//Logical IsSame(const EntityInstanceH& entInst) const;

//virtual Logical IsEqual(const EntityInstanceH& entInst);

#ifdef SDAI_CPP_LATE_BINDING
PrimitiveH GetAttr(const AttrH& attDef);
PrimitiveH GetAttr(const String& attName);  
#endif

//static const SDAIAGGRH(Set, EntityInstanceH)
//GetEntityExtents(const ModelH& model);

//static SDAIAGGRH(Set, EntityInstanceH) GetEntityExtents(ModelH& model);

#ifdef SDAI_CPP_LATE_BINDING
virtual const EntityTypeSetH GetInstanceType() const;
#endif

#ifdef SDAI_CPP_LATE_BINDING
virtual Boolean IsInstanceOf(const EntityTypeSetH& typeSet)
const; 
#endif

#ifdef SDAI_CPP_LATE_BINDING
virtual Boolean IsKindOf(const EntityTypeSetH& typeSet) const;
#endif

#ifdef SDAI_CPP_LATE_BINDING
virtual Boolean IsSDAIKindOf(const EntityTypeSetH& typeSet)
const;
#endif

#ifdef SDAI_CPP_LATE_BINDING
virtual Boolean TestAttr(const AttrH& attDef) ;       
virtual Boolean TestAttr(const name& attName) const;       
#endif

//String GetInstanceTypeName() const;

};

#endif
