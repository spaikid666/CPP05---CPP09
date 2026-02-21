#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm ();
		RobotomyRequestForm (const std::string& target);
		RobotomyRequestForm (const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm ();

		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif