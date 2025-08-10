#include "Form.hpp"

void	f_make(const std::string& name, const int& sign_grade, const int& exec_grade)
{
	try
	{
		Form	f(name, sign_grade, exec_grade);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	Bureaucrat	h("holly", 1);
	Bureaucrat	m("molly", 75);
	Form		f1("f1", 30, 30);
	Form		f2(f1);
	Form		f3("f3", 75, 50);

	std::cout << f1 << std::endl
				<< f2 << std::endl
				<< f3 << std::endl;
	std::cout << std::endl;
	h.signForm(f1);
	m.signForm(f2);
	h.signForm(f3);
	std::cout << std::endl;
	std::cout << f1 << std::endl
				<< f2 << std::endl
				<< f3 << std::endl;
	std::cout << std::endl;
	f_make("f4", 0, 50);
	f_make("f5", 50, 0);
	f_make("f6", 151, 50);
	f_make("f7", 50, 151);
	return (0);
}