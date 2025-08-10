#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat			b1("Admin", 1);
	Bureaucrat			b2("sma", 15);
	Bureaucrat			b3("ang", 70);
	Bureaucrat			b4("bob", 140);

	Form*				f1 = new PresidentialPardonForm("holly");
	Form*				f2 = new RobotomyRequestForm("molly");
	Form*				f3 = new ShrubberyCreationForm("polly");

	std::cout << b1 << std::endl
				<< b2 << std::endl
				<< b3 << std::endl
				<< b4 << std::endl;
	std::cout << std::endl;
	std::cout << *f1 << std::endl
				<< *f2 << std::endl
				<< *f3 << std::endl;
	std::cout << std::endl;
	b2.signForm(*f1);
	b3.signForm(*f2);
	b4.signForm(*f3);
	std::cout << std::endl;
	b2.executeForm(*f1);
	b3.executeForm(*f2);
	b4.executeForm(*f3);
	std::cout << std::endl;
	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;
	return (0);
}