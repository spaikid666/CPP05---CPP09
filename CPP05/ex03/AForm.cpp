#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm () {}

AForm::AForm (std::string name, int sgrade, int egrade, std::string target) : _name(name), _sgrade(sgrade), _egrade(egrade), _target(target)
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
	this->_created = false;
}

AForm::AForm (const AForm& other) : _name(other._name), _sgrade(other._sgrade), _egrade(other._egrade) {}

AForm &AForm::operator=(const AForm &other)
{
	this->_name=other._name;
	this->_signed=other._signed;
	this->_sgrade=other._sgrade;
	this->_egrade=other._egrade;
	return *this;
}

AForm::~AForm () {}



std::string const& AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getSgrade() const
{
	return this->_sgrade;
}

int AForm::getEgrade() const
{
	return this->_egrade;
}

std::string AForm::getTarget() const
{
	return this->_target;
}

bool AForm::getCreated() const
{
	return this->_created;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The grade of the AForm is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The grade of the AForm is too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("The form is not signed.");
}

const char *AForm::FormExecutionException::what() const throw()
{
	return ("The bureaucrat can't execute this form.");
}



void AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() <= this->_sgrade)
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException();
}



std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form name: " << f.getName() << "." << std::endl
	<< "Form signed: " << (f.getSigned() ? "Yes" : "No") << "." << std::endl
	<< "Form's sign grade: " << f.getSgrade() << "." << std::endl
	<< "Form's execution grade: " << f.getEgrade() << "." << std::endl
	<< "Form's is created: " << (f.getCreated() ? "Yes" : "No") << "." << std::endl;

	return (os);
}

void AForm::setCreated(void)
{
	this->_created = true;
}