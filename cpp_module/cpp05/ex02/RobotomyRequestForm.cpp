#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), target("default target")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &tmp) : Form(tmp.getName(), tmp.getSignGrade(), tmp.getExecGrade()), target(tmp.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void                    RobotomyRequestForm::execute(const Bureaucrat &B) const
{
    if (B.getGrade() > getExecGrade())
    {   
        std::cout << "can't execute, ";
        throw   GradeTooLowException();
    }
    if (!getSigned())
    {
        std::cout << "can't execute, ";
        throw   FormIsNotSigned();
    }
    std::cout<< "drrrrrrrrrrrrr, " << target << " has been robotomize successfully 50% of the time" << std::endl;
}