#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "########### BUREAUCRATS ###########" << std::endl;

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
 	
	std::cout << std::endl;
	
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

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "########### FORMS ###########" << std::endl;

	try
	{
		Form f1("Form 1", 1, 1);
		std::cout << f1 << std::endl;
		
		Form f2("Form 2", 0, 0);
		std::cout << f2 << std::endl;
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form f3("Form 3", 150, 150);
		std::cout << f3 << std::endl;
		
		Form f4("Form 4", 151, 151);
		std::cout << f4 << std::endl;
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form f5("Form 5", 150, 150);
		std::cout << f5 << std::endl;
		
		Form f6("Form 6", 75, 75);
		std::cout << f6 << std::endl;

		Bureaucrat b3("Bureaucrat 3", 80);
		std::cout << b3 << std::endl;

		b3.signForm(f5);
		std::cout << std::endl;

		std::cout << f5 << std::endl;
	
		b3.signForm(f6);
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}