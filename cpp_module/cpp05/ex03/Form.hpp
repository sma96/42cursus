#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#define C_NRML "\033[0m"
#define C_RED  "\033[31m"
#define C_GREN "\033[32m"

class Form{
    private:
        std::string const   name;
        int         const   sign_grade;
        int         const   exec_grade;
        bool                _signed;
    
    public:
        Form(void);
        Form(const Form &tmp);
        Form(std::string const &name, int const sign_grade, int const exec_grade);
        virtual ~Form(void);

        std::string const   &getName(void) const;
        int         const   &getSignGrade(void) const;
        int         const   &getExecGrade(void) const;
        bool                getSigned(void) const;

        void                beSigned(const Bureaucrat &B);
        virtual void        execute(const Bureaucrat &B) const =0;  

        class	GradeTooHighException : public std::exception{
			public:
				const char *what(void) const throw(); //exception class에 있는 가상함수 what함수를 오버라이딩한다
		};
		class	GradeTooLowException : public std::exception{
			public:
				const char *what(void) const throw();
		};
        class   FormIsNotSigned : public std::exception{
            public:
                const char  *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const Form &tmp);

#endif