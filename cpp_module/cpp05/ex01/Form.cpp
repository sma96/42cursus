#include "Form.hpp"

Form::Form(void) : name("default"), sign_grade(150), exec_grade(150), _signed(false)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &tmp) : name(tmp.name), sign_grade(tmp.sign_grade), exec_grade(tmp.exec_grade), _signed(tmp._signed)
{
    if (sign_grade > 150 || exec_grade > 150)
        throw   GradeTooLowException();
    else if (sign_grade < 1 || exec_grade < 1)
        throw   GradeTooHighException();
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string const &name, int const sign_grade, int const exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade), _signed(false)
{
    if (sign_grade > 150 || exec_grade > 150)
        throw   GradeTooLowException();
    else if (sign_grade < 1 || exec_grade < 1)
        throw   GradeTooHighException();
    std::cout << "Form name constructor called" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

std::string const           &Form::getName(void) const
{
    return (name);
}

int const                   &Form::getExecGrade(void) const
{
    return (exec_grade);
}

int const                   &Form::getSignGrade(void) const
{
    return (sign_grade);
}

bool                        Form::getSigned(void) const
{
    return (_signed);
}

void            Form::beSigned(const Bureaucrat &B)
{
    if (B.getGrade() > 150)
        throw GradeTooLowException();
    else if(B.getGrade() < 0 || B.getGrade() > sign_grade)
        throw GradeTooHighException();
    if (B.getGrade() <= sign_grade)
        _signed = true;
    // std::cout << "successfully signed" << std::endl;

}

const   char*   Form::GradeTooHighException::what(void) const throw()
{
    return ("grade too high");
}

const   char*   Form::GradeTooLowException::what(void) const throw()
{
    return ("grade too low");
}

std::ostream    &operator<<(std::ostream &o, const Form &tmp)
{
    o << tmp.getName() << " Form" << std::endl;
    o << "sign_grade = " << tmp.getSignGrade() << std::endl;
    o << "exec_grade = " << tmp.getExecGrade() << std::endl;  
    o << "signed = " << tmp.getSigned() << std::endl;
    return (o);
}