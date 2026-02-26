#include "Base.hpp"

Base::~Base(void) {}

Base	*generate(void)
{
	static bool	seeded = false;

	if (!seeded)
	{
		std::srand(static_cast<unsigned>(std::time(NULL)));
		seeded = true;
	}
	
	int r = std::rand() % 3;
	switch (r)
	{
		case 0 : return new A;
		case 1 : return new B;
		case 2 : return new C;
		default : return new A;
	}		
}