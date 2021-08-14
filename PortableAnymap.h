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

		bool saveAnymap(const std::string& path) const;

		void fillAnymap(const unsigned int value);
		void setPixel(const unsigned int x, const unsigned int y, const unsigned int value);
		
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
