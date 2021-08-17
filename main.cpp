#include <iostream>
#include <math.h>
#include "Bitmap.h"
#include "Graymap.h"
#include "Pixmap.h"

int main()
{
	pnm::Bitmap p1(400, 400);
	pnm::Graymap p2(400, 400, 255);
	pnm::Pixmap p3(400, 400, 255);

	p1.fillBitmap(1);
	p1.setPixel(100, 100, 0);

	p2.fillGraymap(128);

	p3.fillPixmap(pnm::color::GREEN);
	p3.setPixel(100, 100, pnm::color::RED);

	if (p1.saveAnymap("test.pbm"))
	{
		std::cout << "Successfully saved test.pbm!" << std::endl;
	}

	if (p2.saveAnymap("test.pgm"))
	{
		std::cout << "Successfully saved test.pgm!" << std::endl;
	}

	if (p3.saveAnymap("test.ppm"))
	{
		std::cout << "Successfully saved test.ppm!" << std::endl;
	}

	return 0;
}