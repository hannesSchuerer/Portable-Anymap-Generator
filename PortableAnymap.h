#ifndef PORTABLE_ANYMAP
#define PORTABLE_ANYMAP

#include <vector>

using MapArray = std::vector<std::vector<unsigned int>>;

namespace pnm
{
	enum class Filetype : unsigned int
	{
		PORTABLE_BITMAP = 0,
		PORTABLE_GRAYMAP = 1,
		PORTABLE_PIXMAP = 2,
		UNKNOWN_PIXMAP = 3
	};

	class PortableAnymap
	{
	public:
		PortableAnymap();
		PortableAnymap(Filetype filetype, unsigned int mWidth, unsigned int mHeight, unsigned int maxVal);

	private:
		Filetype mFiletype;
		unsigned int mWidth;
		unsigned int mHeight;
		unsigned int mMaxVal;
		MapArray mMapArray;
	};
}

#endif // PORTABLE_ANYMAP
