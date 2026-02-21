#ifndef INTER_HPP 
#define INTER_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern ();
		Intern (const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		class EmptyParameter : public std::exception
		{
			public:
				const char* what() const throw ();
		};

		class InvalidForm : public std::exception
		{
			public:
				const char* what() const throw ();
		};

		AForm* makeForm(std::string const& formName, std::string const& target);

	private:
		AForm* createShrubbery(std::string const& target);
		AForm* createRobotomy(std::string const& target);
		AForm* createPresidential(std::string const& target);
};

#endif