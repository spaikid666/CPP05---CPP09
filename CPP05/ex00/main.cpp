#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("BureauHigh", 1);
		std::cout << b1 << std::endl;

		std::cout << "Incrementing the bureaucrat level by 1." << std::endl;

		b1.incrementGrade();
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
 	
	std::cout<< std::endl;
	
	try
	{
		Bureaucrat b2("BureauLow", 150);
		std::cout << b2 << std::endl;

		std::cout << "Decrementing the bureaucrat level by 1." << std::endl;
		b2.decrementGrade();
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}