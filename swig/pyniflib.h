#ifndef _PYNIFLIB_H_
#define _PYNIFLIB_H_

#include "../include/niflib.h"
#include "../include/obj/NiObject.h"
#include "../include/obj/NiNode.h"

namespace Niflib {

using namespace std;

Niflib::NiNodeRef CreateNiNode() { return Niflib::NiNodeRef(new Niflib::NiNode); }

};

#endif
