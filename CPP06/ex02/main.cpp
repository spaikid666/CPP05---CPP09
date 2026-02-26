#include "Base.hpp"

void identify(Base *p)
{
	if (!p)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast &) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast &) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast &) {}
}

int main(void)
{
	std::cout << "Test 1:" << std::endl;
	Base *test1 = generate();
	std::cout << "Identify using pointer: ";
	identify(test1);
	std::cout << "Identify using reference: ";
	identify(*test1);
	std::cout << std::endl;
	delete test1;

	std::cout << "Test 2:" << std::endl;
	Base *test2 = generate();
	std::cout << "Identify using pointer: ";
	identify(test2);
	std::cout << "Identify using reference: ";
	identify(*test2);
	std::cout << std::endl;
	delete test2;

	std::cout << "Test 3:" << std::endl;
	Base *test3 = generate();
	std::cout << "Identify using pointer: ";
	identify(test3);
	std::cout << "Identify using reference: ";
	identify(*test3);
	std::cout << std::endl;
	delete test3;

	return (0);
}