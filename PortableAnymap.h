#ifndef PORTABLE_ANYMAP
#define PORTABLE_ANYMAP

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

/*
* Protable Anymap class which can perform simple file transformations
* Supported Fileformats: PBM, PGM, PPM
*/

struct RGB
{
	unsigned int r = 255;
	unsigned int g = 255;
	unsigned int b = 255;
};

using MapArrayRGB = std::vector<std::vector<RGB>>;
using MapArray = std::vector<std::vector<unsigned int>>;

namespace pnm
{

	namespace color
	{
		constexpr RGB RED = { 255, 0, 0 };
		constexpr RGB GREEN = { 0, 255, 0 };
		constexpr RGB BLUE = { 0, 0, 255 };
	}

	class PortableAnymap
	{
	public:
		PortableAnymap();
		PortableAnymap(std::string filetype, unsigned int width, unsigned int height, unsigned int maxVal);

		virtual ~PortableAnymap();
		
		virtual bool saveAnymap(const std::string& path) const;

		unsigned int getWidth() const;
		unsigned int getHeight() const;

	protected:
		std::string mFiletype;
		unsigned int mWidth;
		unsigned int mHeight;
		unsigned int mMaxVal;
		MapArray mMapArray;
		MapArrayRGB mMapArrayRGB;

	protected:
		std::string createHeader() const;
	};
}

#endif // PORTABLE_ANYMAP
