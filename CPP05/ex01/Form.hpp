#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string _name, int _sgrade, int _egrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string const& getName(void) const;
		bool getSigned(void) const;
		int getSgrade(void) const;
		int getEgrade(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		void beSigned(Bureaucrat const& b);

	private:
		std::string _name;
		bool		_signed;
		int			_sgrade;
		int			_egrade;
};

std::ostream& operator<<(std::ostream&, const Form& f);

#endif


