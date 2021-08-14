#ifndef PORTABLE_ANYMAP
#define PORTABLE_ANYMAP

#include <vector>
#include <string>

using MapArray = std::vector<std::vector<unsigned int>>;

namespace pnm
{
	class PortableAnymap
	{
	public:
		PortableAnymap();
		PortableAnymap(std::string filetype, unsigned int width, unsigned int height, unsigned int maxVal);

		bool saveAnymap(const std::string& path);

	private:
		std::string mFiletype;
		unsigned int mWidth;
		unsigned int mHeight;
		unsigned int mMaxVal;
		MapArray mMapArray;

	private:
		std::string createHeader() const;
	};
}

#endif // PORTABLE_ANYMAP
