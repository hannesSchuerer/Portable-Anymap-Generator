#include "Pixmap.h"

pnm::Pixmap::Pixmap()
    : PortableAnymap("P3", 0, 0, 255)
{
}

pnm::Pixmap::Pixmap(unsigned int width, unsigned int height, unsigned int maxVal)
    : PortableAnymap("P3", width, height, maxVal)
{
}

bool pnm::Pixmap::saveAnymap(const std::string& path) const
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

	for (size_t i = 0; i != mMapArrayRGB.size(); ++i)
	{
		for (size_t j = 0; j != mMapArrayRGB[i].size(); ++j)
		{
			portableAnymapFile << mMapArrayRGB[i][j].r << " ";
			portableAnymapFile << mMapArrayRGB[i][j].g << " ";
			portableAnymapFile << mMapArrayRGB[i][j].b << " ";
		}
		portableAnymapFile << '\n';
	}

	portableAnymapFile.close();
	return true;
}

void pnm::Pixmap::fillPixmap(const RGB& color)
{
	for (size_t i = 0; i < mMapArrayRGB.size(); ++i)
		for (size_t j = 0; j < mMapArrayRGB[i].size(); ++j)
			mMapArrayRGB[i][j] = color;
}

void pnm::Pixmap::setPixel(const unsigned int x, const unsigned int y, const RGB& color)
{
	mMapArrayRGB[x][y] = color;
}
