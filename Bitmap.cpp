#include "Bitmap.h"

// The maxvalue of the Bitmap is always 1

pnm::Bitmap::Bitmap()
	: PortableAnymap("P1", 0, 0, 1)
{
}

pnm::Bitmap::Bitmap(unsigned int width, unsigned int height)
	: PortableAnymap("P1", width, height, 1)
{
}

void pnm::Bitmap::fillBitmap(const unsigned int value)
{
	for (size_t i = 0; i != mMapArray.size(); ++i)
		for (size_t j = 0; j != mMapArray[i].size(); ++j)
			mMapArray[i][j] = value;
}

void pnm::Bitmap::setPixel(const unsigned int x, const unsigned int y, const unsigned int value)
{
	mMapArray[x][y] = value;
}