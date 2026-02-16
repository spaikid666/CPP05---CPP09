#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm () {}
RobotomyRequestForm::RobotomyRequestForm (const std::string& target) : AForm("RobotomyRequestForm", 145, 137, target) {}
RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm& other) : AForm(other) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute (Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw (FormNotSignedException());

	if (this->getEgrade() < executor.getGrade())
		throw (FormExecutionException());	

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->getTarget() << std::endl;
}