#include <iostream>
#include <math.h>
#include "Bitmap.h"

int main()
{
	pnm::Bitmap p1(400, 400);

	p1.fillBitmap(1);
	p1.setPixel(100, 100, 0);

	if (p1.saveBitmap("test.pbm"))
	{
		std::cout << "Successfully saved test.pbm!" << std::endl;
	}

	return 0;
}