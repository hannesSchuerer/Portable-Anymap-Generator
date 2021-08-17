#ifndef PIXMAP_H
#define PIXMAP_H

#include "PortableAnymap.h"

namespace pnm
{
	class Pixmap : public pnm::PortableAnymap
	{
	public:
		Pixmap();
		Pixmap(unsigned int width, unsigned int height, unsigned int maxVal);

		virtual bool saveAnymap(const std::string& path) const override;

		void fillPixmap(const RGB& color);
		void setPixel(const unsigned int x, const unsigned int y, const RGB& color);
	};
}

#endif // PIXMAP_H