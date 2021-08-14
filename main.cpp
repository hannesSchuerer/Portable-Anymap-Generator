#include <iostream>
#include "PortableAnymap.h"

int main()
{
	pnm::PortableAnymap p1("P1", 1000, 1000, 1);

	if (p1.saveAnymap("test.pbm"))
	{
		std::cout << "Saved file successfully!" << std::endl;
	}

	return 0;
}