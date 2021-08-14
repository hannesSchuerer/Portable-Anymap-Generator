#include "PortableAnymap.h"

pnm::PortableAnymap::PortableAnymap()
	:mFiletype(Filetype::UNKNOWN_PIXMAP),
	mWidth(0),
	mHeight(0),
	mMaxVal(0),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 0))
{
}

pnm::PortableAnymap::PortableAnymap(Filetype filetype, unsigned int width, unsigned int height, unsigned int maxVal)
	:mFiletype(filetype),
	mWidth(width),
	mHeight(height),
	mMaxVal(maxVal),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 0))
{
}