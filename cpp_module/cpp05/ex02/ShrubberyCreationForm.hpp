#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &tmp);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &tmp);

        std::string const &getTarget(void) const;

        void                execute(const Bureaucrat &B) const;

        class   FileIsNotOpen : public std::exception{
            public:
                const char* what(void) const throw();
        };
};

#endif