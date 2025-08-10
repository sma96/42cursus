#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <random>

class RobotomyRequestForm : public Form{
    private:
        std::string target;
    
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &tmp);
        RobotomyRequestForm(std::string const &target);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(const RobotomyRequestForm &tmp);

        std::string const &getTaget(void) const;

        void                execute(const Bureaucrat &B) const;
};

#endif