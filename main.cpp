#include <iostream>
#include <math.h>
#include "Bitmap.h"
#include "Graymap.h"

int main()
{
	pnm::Bitmap p1(400, 400);
	pnm::Graymap p2(400, 400, 255);

	p1.fillBitmap(1);
	p1.setPixel(100, 100, 0);

	p2.fillGraymap(128);

	if (p1.saveBitmap("test.pbm"))
	{
		std::cout << "Successfully saved test.pbm!" << std::endl;
	}

	if (p2.saveGraymap("test.pgm"))
	{
		std::cout << "Successfully saved test.pgm!" << std::endl;
	}

	return 0;
}