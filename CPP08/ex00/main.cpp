#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> intV;
	std::list<int> intL;

	for (int i = 0; i < 4; i++)
	{
		intV.push_back(i);
		intL.push_back(i);
	}

	std::cout << "--- Test with Vector ---" << std::endl;

	try
	{
		std::cout << "Found: " << *::easyfind(intV, 2) << std::endl;
		std::cout << "Found: " << *::easyfind(intV, 6) << std::endl;
	}

	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "--- Test with List ---" << std::endl;

	try
	{
		std::cout << "Found: " << *::easyfind(intL, 2) << std::endl;
		std::cout << "Found: " << *::easyfind(intL, 6) << std::endl;
	}

	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}