#include <iostream>
#include <math.h>
#include "PortableAnymap.h"

int main()
{
	pnm::PortableAnymap p1("P2", 400, 400, 255);

	p1.fillAnymap(0);

	for (unsigned int i = 0; i < p1.getWidth(); ++i)
	{
		p1.setPixel((std::sin(i) * 5 + 200), i, 255);
	}

	if (p1.saveAnymap("test.pbm"))
	{
		std::cout << "Saved file successfully!" << std::endl;
	}

	return 0;
}