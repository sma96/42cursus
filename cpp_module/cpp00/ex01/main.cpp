#include "phonebook.hpp"

int main(void)
{
	phonebook phonebook;
	std::string str;

	phonebook.init();
	while (true)
	{
		std::cout << "input command >> ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break;
		if (str == "ADD")
			phonebook.fill_info();
		else if (str == "SEARCH")
			phonebook.search_command();
		else if (str == "EXIT")
		{
			std::cout << "good bye~" << std::endl;
			break;
		}
		else 
			std::cout << "wrong input" << std::endl;
	}
	return (0);
}