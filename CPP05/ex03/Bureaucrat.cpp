#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat () {}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_name=other._name;
	this->_grade=other._grade;
	return *this;
} 
Bureaucrat::~Bureaucrat() {}




std::string const& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}




void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}




const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade of the Bureaucrat is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade of the Bureaucrat is too low.");
}




std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}



void Bureaucrat::signForm(AForm& f)
{
	if (this->getGrade() <= f.getSgrade())
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl; 
	}
	else
		std::cout << this->getName() << " couldn't sign " << f.getName() << " becuase " << "the grade of the bureaucrat isn't high enough." << std::endl; 
}


void Bureaucrat::executeForm(AForm const& f) const
{
	f.execute(*this);
}
