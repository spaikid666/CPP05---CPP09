#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string _name, int _sgrade, int _egrade, std::string _target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		std::string const& getName(void) const;
		bool getSigned(void) const;
		int getSgrade(void) const;
		int getEgrade(void) const;
		std::string getTarget() const;

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

		class FormNotSignedException : public std::exception
		{
			const char *what() const throw();
		};

		class FormExecutionException : public std::exception
		{
			const char *what() const throw();
		};

		void beSigned(Bureaucrat const& b);

		virtual void execute(Bureaucrat const & executor) const = 0;

	private:
		std::string _name;
		bool		_signed;
		int			_sgrade;
		int			_egrade;
		std::string _target;
		bool		_created;
};

std::ostream& operator<<(std::ostream&, const AForm& f);

#endif

