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
    srand(time(NULL));
    if (B.getGrade() > getExecGrade())
    {   
        throw   GradeTooLowException();
    }
    if (!getSigned())
    {
        throw   FormIsNotSigned();
    }
    if (rand() % 100 >= 50)
        std::cout << C_GREN <<  "drrrrrrrrrrrrr, " << target << " has been robotomize successfully 50% of the time" << C_NRML << std::endl;
    else
        std::cout << C_RED << target << " failed robotomize" << C_NRML <<std::endl;
}