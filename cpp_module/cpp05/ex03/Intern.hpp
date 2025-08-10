#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern(void);
        Intern(const Intern &);
        
        Intern &operator=(const Intern &);

        Form *makeForm(std::string const &type, std::string const &target);

        class UnknownTypeException : public std::exception{
            const char *what(void) const throw();
        };
};
#endif