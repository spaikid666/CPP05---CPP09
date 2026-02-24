#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("Jhon", 1);
		Bureaucrat junior("Junior", 150);

		AForm *sf = new ShrubberyCreationForm("Calamardo");
		AForm *rf = new RobotomyRequestForm("Marvin");
		AForm *pf = new PresidentialPardonForm("Borat");
		
		std::cout << "########### ShrubberyCreationForm ###########" << std::endl;
		std::cout << "# Test 1: the form is not signed" << std::endl;
		try
		{
			sf->execute(jhon);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 2: not enough grade to sign the form" << std::endl;\
		try
		{
			junior.signForm(*sf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 3: the is signed but not enough execution grade" << std::endl;\
		try
		{
			jhon.signForm(*sf);
			junior.executeForm(*sf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 4: execution good" << std::endl;\
		try
		{
			jhon.executeForm(*sf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "########### RobotomyRequestForm ###########" << std::endl;
		std::cout << "# Test 1: the form is not signed" << std::endl;
		try
		{
			rf->execute(jhon);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 2: not enough grade to sign the form" << std::endl;\
		try
		{
			junior.signForm(*rf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 3: the is signed but not enough execution grade" << std::endl;\
		try
		{
			jhon.signForm(*rf);
			junior.executeForm(*rf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 4: execution good" << std::endl;\
		try
		{
			jhon.executeForm(*rf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "########### PresidentialPardonForm ###########" << std::endl;
		std::cout << "# Test 1: the form is not signed" << std::endl;
		try
		{
			pf->execute(jhon);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 2: not enough grade to sign the form" << std::endl;\
		try
		{
			junior.signForm(*pf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 3: the is signed but not enough execution grade" << std::endl;\
		try
		{
			jhon.signForm(*pf);
			junior.executeForm(*pf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "# Test 4: execution good" << std::endl;\
		try
		{
			jhon.executeForm(*pf);
		}

		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		
		delete sf;
        delete rf;
        delete pf;
	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}