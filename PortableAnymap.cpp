#include "PortableAnymap.h"

#include <fstream>
#include <filesystem>
#include <iostream>

pnm::PortableAnymap::PortableAnymap()
	:mFiletype("P1"),
	mWidth(10),
	mHeight(10),
	mMaxVal(1),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 1))
{
}

pnm::PortableAnymap::PortableAnymap(std::string filetype, unsigned int width, unsigned int height, unsigned int maxVal)
	:mFiletype(filetype),
	mWidth(width),
	mHeight(height),
	mMaxVal(maxVal),
	mMapArray(mWidth, std::vector<unsigned int>(mHeight, 0))
{
}

bool pnm::PortableAnymap::saveAnymap(const std::string& path) const
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

void pnm::PortableAnymap::fillAnymap(const unsigned int value)
{
	for (size_t i = 0; i != mMapArray.size(); ++i)
		for (size_t j = 0; j != mMapArray[i].size(); ++j)
			mMapArray[i][j] = value;
}

void pnm::PortableAnymap::setPixel(const unsigned int x, const unsigned int y, const unsigned int value)
{
	mMapArray[x][y] = value;
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