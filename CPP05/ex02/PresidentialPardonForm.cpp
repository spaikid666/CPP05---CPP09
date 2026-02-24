#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm () : AForm("no name", 25, 5, "no target") {}
PresidentialPardonForm::PresidentialPardonForm (const std::string& target) : AForm("PresidentialPardonForm", 25, 5, target) {}
PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm& other) : AForm(other) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm () {}

void PresidentialPardonForm::execute (Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw (FormNotSignedException());

	if (this->getEgrade() < executor.getGrade())
		throw (FormExecutionException());

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << this->getTarget() << " has been pardoned by Zaphod BeebleBox." << std::endl;
}