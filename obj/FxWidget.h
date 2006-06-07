/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _FXWIDGET_H_
#define _FXWIDGET_H_

#include "NiNode.h"

#include "../gen/obj_defines.h"

class FxWidget;
typedef Ref<FxWidget> FxWidgetRef;

/*!
 * FxWidget - Firaxis-specific UI widgets?
 */

class NIFLIB_API FxWidget : public FX_WIDGET_PARENT {
public:
	FxWidget();
	~FxWidget();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	FX_WIDGET_MEMBERS
};

#endif
