#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form () {}

Form::Form (std::string name, int sgrade, int egrade) : _name(name), _sgrade(sgrade), _egrade(egrade)
{
	this->_signed = false;
	if (_sgrade < 1)
		throw GradeTooHighException();
	if (_sgrade > 150)
		throw GradeTooLowException();
	if (_egrade < 1)
		throw GradeTooHighException();
	if (_egrade > 150)
		throw GradeTooLowException();
}

Form::Form (const Form& other) : _name(other._name), _sgrade(other._sgrade), _egrade(other._egrade) {}

Form &Form::operator=(const Form &other)
{
	this->_name=other._name;
	this->_signed=other._signed;
	this->_sgrade=other._sgrade;
	this->_egrade=other._egrade;
	return *this;
}

Form::~Form () {}



std::string const& Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSgrade() const
{
	return this->_sgrade;
}

int Form::getEgrade() const
{
	return this->_egrade;
}



const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade of the Form is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade of the Form is too low.");
}



void Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() <= this->_sgrade)
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException();
}



std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form name: " << f.getName() << "." << std::endl
	<< "Form signed: " << (f.getSigned() ? "Yes" : "No") << "." << std::endl
	<< "Form's sign grade: " << f.getSgrade() << "." << std::endl
	<< "Form's execution grade: " << f.getEgrade() << "." << std::endl;

	return (os);
}



