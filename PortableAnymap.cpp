#include "PortableAnymap.h"

pnm::PortableAnymap::PortableAnymap()
	:mFiletype("P1"),
	mWidth(10),
	mHeight(10),
	mMaxVal(1),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 0)),
	mMapArrayRGB(mWidth, std::vector<RGB>(mHeight, {0, 0, 0}))
{
}

pnm::PortableAnymap::PortableAnymap(std::string filetype, unsigned int width, unsigned int height, unsigned int maxVal)
	:mFiletype(filetype),
	mWidth(width),
	mHeight(height),
	mMaxVal(maxVal),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 0)),
	mMapArrayRGB(mWidth, std::vector<RGB>(mHeight, { 0, 0, 0 }))
{
}

pnm::PortableAnymap::~PortableAnymap()
{
}

unsigned int pnm::PortableAnymap::getWidth() const
{
	return mWidth;
}

unsigned int pnm::PortableAnymap::getHeight() const
{
	return mHeight;
}

std::string pnm::PortableAnymap::createHeader() const
{
	std::string header = "";
	header += mFiletype + '\n';
	header += std::to_string(mWidth) + " " + std::to_string(mHeight) + '\n';
	header += std::to_string(mMaxVal) + '\n';

	return header;
}