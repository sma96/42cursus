#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &)
{
}

Intern &Intern::operator=(const Intern &)
{
    return (*this);
}

Form *Intern::makeForm(std::string const &type, std::string const &target)
{
    std::string type_list[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
    {
        if (type_list[i] == type)
        {
            switch (i)
            {
                case 0:
                    return (new ShrubberyCreationForm(target));
                    break;
                case 1:
                    return (new RobotomyRequestForm(target));
                    break;
                case 2:
                    return (new PresidentialPardonForm(target));
                    break;
            }
        }
    }
    std::cout << type <<  " : ";
    throw UnknownTypeException();
    return (0);
}

const   char    *Intern::UnknownTypeException::what(void) const throw()
{
    return ("unknown form type");
}