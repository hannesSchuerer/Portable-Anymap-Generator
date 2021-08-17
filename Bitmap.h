#ifndef BITMAP_H
#define BITMAP_H

#include "PortableAnymap.h"

namespace pnm
{

	class Bitmap : public pnm::PortableAnymap
	{
	public:
		Bitmap();
		Bitmap(unsigned int width, unsigned int height);

		bool saveBitmap(const std::string& path) const;

		void fillBitmap(const unsigned int value);
		void setPixel(const unsigned int x, const unsigned int y, const unsigned int value);

	private:
		MapArray mMapArray;
	};

}

#endif // BITMAP