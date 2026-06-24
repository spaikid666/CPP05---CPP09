#include "Span.hpp"
#include <iostream>

int main()
{
	Span test1(5);

	std::cout << "--- Testing Adding Numbers & Member Functions ---" << std::endl;

	test1.addNumber(10);
	test1.addNumber(15);
	test1.addNumber(40);
	test1.addNumber(30);
	test1.addNumber(5);

	std::cout << "Test1: Shortest Span = " << test1.shortestSpan() << std::endl;
	std::cout << "Test1: Longest Span = " << test1.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing Adding More Numbers Than Size ---" << std::endl;
	try
	{
		test1.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing with Empty Span ---" << std::endl;
	Span empty(3);
	try
	{
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing with a Massive Span ---" << std::endl;
	Span massiveSpan(10000);
    std::vector<int> bigVector;
    
    // Fill a standard vector with 10,000 numbers (from 1 to 10000)
    for (int i = 1; i <= 10000; i++) {
        bigVector.push_back(i);
    }

    try {
        massiveSpan.addNumber(bigVector.begin(), bigVector.end());
        std::cout << "Successfully added 10,000 numbers" << std::endl;
        std::cout << "Shortest Span: " << massiveSpan.shortestSpan() << " (Expected: 1)" << std::endl;
        std::cout << "Longest Span: " << massiveSpan.longestSpan() << " (Expected: 9999)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Failed: " << e.what() << std::endl;
    }

    return 0;
}