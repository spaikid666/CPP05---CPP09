#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm () : AForm ("no name", 145, 137, "no target") {}
ShrubberyCreationForm::ShrubberyCreationForm (const std::string& target) : AForm("ShrubberyCreationForm", 145, 137, target) {}
ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm& other) : AForm(other) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {}

void ShrubberyCreationForm::execute (Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw (FormNotSignedException());

	if (this->getEgrade() < executor.getGrade())
		throw (FormExecutionException());

	std::ofstream out((getTarget() + "_shrubbery").c_str());

	if (!out)
	{	
		std::cerr << "Error: Could not create shrubbery file." << std::endl;
		return;
	}
	
	else
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	
	out << "	|	      |     " << std::endl;
	out << "   |||	     |||    " << std::endl;
	out << "  |||||	    |||||   " << std::endl;
	out << " |||||||   |||||||  " << std::endl;
	out << "||||||||| ||||||||| " << std::endl;
	out << "   |||	     |||    " << std::endl;
	out.close();
}