#include "Graymap.h"

pnm::Graymap::Graymap()
	: PortableAnymap("P2", 0, 0, 255)
{
}

pnm::Graymap::Graymap(unsigned int width, unsigned int height, unsigned int maxVal)
	: PortableAnymap("P2", width, height, maxVal)
{
}

void pnm::Graymap::fillGraymap(const unsigned int value)
{
	for (size_t i = 0; i != mMapArray.size(); ++i)
		for (size_t j = 0; j != mMapArray[i].size(); ++j)
			mMapArray[i][j] = value;
}

void pnm::Graymap::setPixel(const unsigned int x, const unsigned int y, const unsigned int value)
{
	mMapArray[x][y] = value;
}