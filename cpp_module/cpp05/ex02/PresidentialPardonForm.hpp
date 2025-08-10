#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form{
    private:
        std::string target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm &tmp);
        PresidentialPardonForm(std::string const &target);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(const PresidentialPardonForm &tmp);

        std::string const &getTarget(void) const;
        
        void                execute(const Bureaucrat &B) const;
};

#endif