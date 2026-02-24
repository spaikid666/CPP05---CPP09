#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("Jhon", 1);
		Bureaucrat junior("Junior", 150);

		Intern lacayo;
		AForm* rrf;

		rrf = lacayo.makeForm("robotomy request", "Bender");

		std::cout << "# Test 1: the form is not signed" << std::endl;
		try
		{
			rrf->execute(jhon);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 2: not enough grade to sign the form" << std::endl;\
		try
		{
			junior.signForm(*rrf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 3: the is signed but not enough execution grade" << std::endl;\
		try
		{
			jhon.signForm(*rrf);
			junior.executeForm(*rrf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 4: execution good" << std::endl;\
		try
		{
			jhon.executeForm(*rrf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "### With an invalid form" << std::endl;

		try
		{
			AForm* fail = lacayo.makeForm("failure", "Test");
			(void)fail;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}