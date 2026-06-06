#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T element)
{
	std::cout << element << " ";
}

template <typename T>
void addToElement(T& element)
{
	element++;
}

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	std::size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

	const std::string charArr[] = {"Templates", "are", "fun", ":)"};
	std::size_t charLen = sizeof(charArr) / sizeof(charArr[0]);

	std::cout << "--- Int Array: ---" << std::endl;
	std::cout << std::endl;

	
	std::cout << "Original Array: " << std::endl;
	::iter(intArr, intLen, printElement<int>);
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Incremented Array: " << std::endl;
	::iter(intArr, intLen, addToElement<int>);
	::iter(intArr, intLen, printElement<int>);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "--- Char Array: ---" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Original Array: " << std::endl;
	::iter(charArr, charLen, printElement<const std::string>);
	std::cout << std::endl;
	std::cout << std::endl;
	
	/*
	std::cout << "Incremented Array: " << std::endl;
	::iter(charArr, charLen, addToElement<const std::string>);
	::iter(charArr, charLen, printElement<const std::string>);
	std::cout << std::endl;
	*/

	
	return 0;
}