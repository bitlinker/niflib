/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIPIXELDATA_H_
#define _NIPIXELDATA_H_

#include "NiObject.h"
// Include structures
#include "../Ref.h"
#include "../gen/MipMap.h"
#include "../gen/ByteArray.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPalette;

//#include "../gen/obj_defines.h"

class NiPixelData;
typedef Ref<NiPixelData> NiPixelDataRef;

/*!
 * NiPixelData - A texture.
 */

class NiPixelData : public NI_PIXEL_DATA_PARENT {
public:
	NIFLIB_API NiPixelData();
	NIFLIB_API ~NiPixelData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the height of the texture image stored in this object.
	 * \return The height of the texture image stored in this object.
	 * \sa NiPixelData::GetWidth, NiPixelData::GetPixelFormat
	 */
	NIFLIB_API int GetHeight() const;

	/*!
	 * Retrieves the width of the texture image stored in this object.
	 * \return The width of the texture image stored in this object.
	 * \sa NiPixelData::GetHeight, NiPixelData::GetPixelFormat
	 */
	NIFLIB_API int GetWidth() const;

    /*!
	 * Retrieves the pixel format of the texture image stored in this object.
	 * \return The pixel format of the texture image stored in this object.
	 * \sa NiPixelData::GetWidth, NiPixelData::GetHeight
	 */
	NIFLIB_API PixelFormat GetPixelFormat() const;

    /*!
	 * Deletes all image data and sets a new size and format in preparation for new data to be provided.
	 * \param new_width The width of the new texture image.
	 * \param new_height The height of the new texture image.
	 * \param px_fmt The pixel format of the new texture image.
	 * \sa NiPixelData::GetWidth, NiPixelData::GetHeight
	 */
	NIFLIB_API void Reset( int new_width, int new_height, PixelFormat px_fmt );
	
	/*!
	 * Retrieves the the pixels of the texture image stored in this object.  This function does not work on palettized textures.
	 * \return A vector containing the colors of each pixel in the texture image stored in this object, one row after another starting from the bottom of the image.  The width of the image must be used to interpret them correctly.
	 * \sa NiPixelData::SetColors, NiPixelData::GetWidth
	 */
	NIFLIB_API vector<Color4> GetColors() const;

	/*!
	 * Sets the the pixels of the texture image stored in this object and optionally generates mipmaps.  This function does not work for palettized textures.
	 * \param new_pixels A vector containing the colors of each new pixel to be set in the texture image stored in this object, one row after another starting from the botom of the image.
	 * \param generate_mipmaps If true, mipmaps will be generated for the new image and stored in the file.
	 * \sa NiPixelData::GetColors, NiPixelData::GetWidth
	 */
	NIFLIB_API void SetColors( const vector<Color4> & new_pixels, bool generate_mipmaps );

protected:
	NI_PIXEL_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
