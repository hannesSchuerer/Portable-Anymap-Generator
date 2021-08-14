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

bool pnm::PortableAnymap::saveAnymap(const std::string& path)
{
	if (std::filesystem::path p(path); std::filesystem::exists(p))
	{
		std::cout << "File already exists: " << path << std::endl;
		return false;
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

std::string pnm::PortableAnymap::createHeader() const
{
	std::string header = "";
	header += mFiletype + '\n';
	header += std::to_string(mWidth) + " " + std::to_string(mHeight) + '\n';
	header += std::to_string(mMaxVal) + '\n';

	return header;
}