#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), target("default target")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &tmp) : Form(tmp.getName(), tmp.getSignGrade(), tmp.getExecGrade()), target(tmp.target)
{
    std::cout << "presidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardeonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardeonForm target constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &tmp)
{
    target = tmp.target;
    return (*this);
}

std::string const &PresidentialPardonForm::getTarget(void) const
{
    return (target);
}

void                PresidentialPardonForm::execute(const Bureaucrat &B) const
{
    if (B.getGrade() > getExecGrade())
    {   
        throw   GradeTooLowException();
    }
    if (!getSigned())
    {
        throw   FormIsNotSigned();
    }
    std::cout << C_GREN << target << " has been pardoned by Zafod Beeblebrox " << C_NRML << std::endl;
}

