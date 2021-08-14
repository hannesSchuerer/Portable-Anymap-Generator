#include <iostream>
#include "PortableAnymap.h"

int main()
{
	pnm::PortableAnymap p1("P1", 400, 400, 1);

	p1.fillAnymap(1);
	p1.setPixel(200, 200, 0);

	if (p1.saveAnymap("test.pbm"))
	{
		std::cout << "Saved file successfully!" << std::endl;
	}

	return 0;
}