#include "Intern.hpp"

Intern::Intern () {}
Intern::Intern (const Intern& other) {(void)other;}
Intern& Intern::operator=(const Intern& other) {(void)other; return (*this);}
Intern::~Intern () {}

const char *Intern::EmptyParameter::what() const throw ()
{
	return("Try again: The parameters of the form are empty.");
}

const char *Intern::InvalidForm::what() const throw ()
{
	return("Try again: The parameters of the form are invalid.");
}

AForm* Intern::createShrubbery(std::string const& target)
{
	static ShrubberyCreationForm form(target);
	form.setCreated();
	return(&form);
}

AForm* Intern::createRobotomy(std::string const& target)
{
	static RobotomyRequestForm form(target);
	form.setCreated();
	return(&form);
}

AForm* Intern::createPresidential(std::string const& target)
{
	static PresidentialPardonForm form(target);
	form.setCreated();
	return(&form);
}

AForm* Intern::makeForm(std::string const& type, std::string const& target)
{
	if (type.empty() || target.empty())
		throw EmptyParameter();

	std::string Form_type[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*functions[3])(std::string const&) =
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (type == Form_type[i])
			return (this->*functions[i])(target);
	}

	throw InvalidForm();
}