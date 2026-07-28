#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	std::cout << "******* Test with int *******" << std::endl;
	Array<int> emptyArray;
	Array<int> test1(5);

	std::cout << "-- Checking the size of the array --" << std::endl;
	std::cout << "The empty array has a size of: " << emptyArray.getSize() << std::endl;
	std::cout << "The test array has a size of: " << test1.getSize() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-- Element Access and modification --" << std::endl;
	std::cout << "· The element is inside the size's range:" << std::endl;
	std::cout << "The memory address for the 3rd element of the test1 array is: " << &test1[2] << std::endl;
	std::cout << std::endl;
	std::cout << "· The element is outside the size's range:" << std::endl;
	try
	{
		std::cout << "The memory address for the 3rd element of the test1 array is: " << &test1[8] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-- Deep Copy Test --" << std::endl;
	Array<int> test2(test1);
	std::cout << "· Accessing the memory direction of the 3rd element of the test1 array: " << std::endl;
	std::cout << "The memory address for the third element of the test1 array is: " << &test1[2] << std::endl;
	std::cout << std::endl;
	std::cout << "· Accessing the memory direction of the 3rd element of the test2 array: " << std::endl;
		std::cout << "The memory address for the third element of the test2 array is: " << &test2[2] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-- Asignment Operator --" << std::endl;
	test1[2] = 3;
	Array<int> test3 = test1;
	std::cout << "· The value of the 3rd element of the test1 array is: " << test1[2] << std::endl;
	std::cout << "· The value of the 3rd element of the test3 array is: " << test3[2] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "******* Test with std::string *******" << std::endl;
	Array<std::string> emptyArray2;
	Array<std::string> test4(5);

	std::cout << "-- Checking the size of the array --" << std::endl;
	std::cout << "The emptyArray2 has a size of: " << emptyArray2.getSize() << std::endl;
	std::cout << "The test4 array has a size of: " << test4.getSize() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-- Element Access and modification --" << std::endl;
	std::cout << "· The element is inside the size's range:" << std::endl;
	std::cout << "The memory address for the 3rd element of the test4 array is: " << &test4[2] << std::endl;
	std::cout << std::endl;
	std::cout << "· The element is outside the size's range:" << std::endl;
	try
	{
		std::cout << "The memory address for the 3rd element of the test4 array is: " << &test4[8] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-- Deep Copy Test --" << std::endl;
	Array<std::string> test5(test4);
	std::cout << "· Accessing the memory direction of the 3rd element of the test4 array: " << std::endl;
	std::cout << "The memory address for the third element of the test4 array is: " << &test4[2] << std::endl;
	std::cout << std::endl;
	std::cout << "· Accessing the memory direction of the 3rd element of the test2 array: " << std::endl;
		std::cout << "The memory address for the third element of the test2 array is: " << &test5[2] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-- Asignment Operator --" << std::endl;
	test4[2] = "3";
	Array<std::string> test6 = test4;
	std::cout << "· The value of the 3rd element of the test4 array is: " << test4[2] << std::endl;
	std::cout << "· The value of the 3rd element of the test4 array is: " << test6[2] << std::endl;
	std::cout << std::endl;
}
