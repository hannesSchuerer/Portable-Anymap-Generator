#ifndef PORTABLE_ANYMAP
#define PORTABLE_ANYMAP

#include <vector>
#include <string>

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

using MapArray = std::vector<std::vector<unsigned int>>;
using MapArrayRGB = std::vector<std::vector<RGB>>;

namespace pnm
{
	class PortableAnymap
	{
	public:
		PortableAnymap();
		PortableAnymap(std::string filetype, unsigned int width, unsigned int height, unsigned int maxVal);

		virtual ~PortableAnymap();
		
		unsigned int getWidth() const;
		unsigned int getHeight() const;

	protected:
		std::string mFiletype;
		unsigned int mWidth;
		unsigned int mHeight;
		unsigned int mMaxVal;

	protected:
		std::string createHeader() const;
	};
}

#endif // PORTABLE_ANYMAP
