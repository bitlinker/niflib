/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NITRISHAPE_H_
#define _NITRISHAPE_H_

#include "NiTriBasedGeom.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiTriShape;
typedef Ref<NiTriShape> NiTriShapeRef;

/*!
 * NiTriShape - A shape node that refers to singular triangle data.
 */

class NiTriShape : public NI_TRI_SHAPE_PARENT {
public:
	NIFLIB_API NiTriShape();
	NIFLIB_API ~NiTriShape();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	NI_TRI_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
