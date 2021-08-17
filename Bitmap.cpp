#include "Bitmap.h"

#include <fstream>
#include <filesystem>
#include <iostream>

// The maxvalue of the Bitmap is always 1

pnm::Bitmap::Bitmap()
	: PortableAnymap("P1", 0, 0, 1),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 0))
{
}

pnm::Bitmap::Bitmap(unsigned int width, unsigned int height)
	: PortableAnymap("P1", width, height, 1),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 1))
{
}

bool pnm::Bitmap::saveBitmap(const std::string& path) const
{
	if (std::filesystem::path p(path); std::filesystem::exists(p))
	{
		// If the Anymap file exists, it will be removed and newly constructed
		std::filesystem::remove(p);
	}

	std::ofstream portableAnymapFile(path, std::ios_base::out);

	if (!portableAnymapFile.is_open())
	{
		std::cout << "Can't open file: " << path << std::endl;
		return false;
	}

	portableAnymapFile << createHeader();

	for (size_t i = 0; i != mMapArray.size(); ++i)
	{
		for (size_t j = 0; j != mMapArray[i].size(); ++j)
		{
			portableAnymapFile << mMapArray[i][j] << " ";
		}
		portableAnymapFile << '\n';
	}

	portableAnymapFile.close();
	return true;
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