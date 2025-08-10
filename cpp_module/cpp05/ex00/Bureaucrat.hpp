#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

#define GRADE_MAX 150;
#define GRADE_MIN 1;

class Bureaucrat{
	private:
		std::string const   name;
		int                 grade;

	public:
		Bureaucrat(const Bureaucrat &tmp);
		Bureaucrat(std::string const &name, const int &grade);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &tmp);

		std::string const   &getName(void) const;
		int					getGrade(void) const;

		void				increment(void);
		void				decrement(void);
		// GradeTooHighException 클래스를 throw하여 what함수를 실행시켜 에러메시지를 출력
		class	GradeTooHighException : public std::exception{
			public:
				const char *what(void) const throw(); //exception class에 있는 가상함수 what함수를 오버라이딩한다
		};
		class	GradeTooLowException : public std::exception{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &tmp);

#endif