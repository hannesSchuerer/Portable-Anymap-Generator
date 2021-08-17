#include "Graymap.h"

#include <fstream>
#include <filesystem>
#include <iostream>

pnm::Graymap::Graymap()
	: PortableAnymap("P2", 0, 0, 255)
{
}

pnm::Graymap::Graymap(unsigned int width, unsigned int height, unsigned int maxVal)
	: PortableAnymap("P2", width, height, maxVal)
{
}

bool pnm::Graymap::saveGraymap(const std::string& path) const
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