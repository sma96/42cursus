#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &name, const int &grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &tmp) : name(tmp.name), grade(tmp.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &tmp)
{
    grade = tmp.grade;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    return (*this);
}

std::string const   &Bureaucrat::getName(void) const
{
    return (name);   
}

int                 Bureaucrat::getGrade(void) const
{
    return (grade);
}

void                Bureaucrat::decrement(void)
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

void                Bureaucrat::increment(void)
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void                Bureaucrat::signForm(Form &F)
{
    try
    {
        F.beSigned(*this);
        std::cout << getName() << " signs " << F.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " cannot sign " << F.getName() << " " << e.what() << std::endl;
    }
}

void                Bureaucrat::executeForm(Form const &form) const
{
    try{
        form.execute(*this);
        std::cout << name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " can't execute " << form.getName()  << " : " <<  e.what() << std::endl;
    }
}

const char                *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("grade too low");
}

const char                *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("grade too high");
}

std::ostream    &operator<<(std::ostream &o, const Bureaucrat &tmp)
{
    o << tmp.getName() << ", bureaucrat grade " << tmp.getGrade();
    return (o);
}