#ifndef GRAYMAP_H
#define GRAYMAP_H

#include "PortableAnymap.h"

namespace pnm
{
	class Graymap : public pnm::PortableAnymap
	{
	public:
		Graymap();
		Graymap(unsigned int width, unsigned int height, unsigned int maxVal);

		bool saveGraymap(const std::string& path) const;

		void fillGraymap(const unsigned int value);
		void setPixel(const unsigned int x, const unsigned int y, const unsigned int value);
	};
}

#endif // GRAYMAP_H