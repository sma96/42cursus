#include "phonebook.hpp"

void    phonebook::init(void)
{
	this->index = 0;
	this->contacts_num = 0;
	std::cout << "input command - ADD , SEARCH, EXIT -" << std::endl;
}

int		phonebook::check_str(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('0' > str[i] || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void    phonebook::fill_info(void)
{
	std::string idx;

	if (this->contacts_num == 8)
	{
		std::cout << "phonebook is full, The oldest contact is now replaced" << std::endl;
		this->index = this->index % 8;
	}
	std::cout << "enter your firstname : ";
	std::getline(std::cin, this->first_name[this->index]);
	std::cout << "enter your lasttname : ";
	std::getline(std::cin, this->last_name[this->index]);
	std::cout << "enter your nickname : ";
	std::getline(std::cin, this->nick_name[this->index]);
	std::cout << "enter your phone number : ";
	std::getline(std::cin, this->phone_number[this->index]);
	std::cout << "enter your darkest secret : ";
	std::getline(std::cin, this->darkest_secret[this->index]);
	if (this->contacts_num <= 7)
		this->contacts_num++;
	this->index++;
}

void    phonebook::printf_output(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9).append(".") << "|";
	else
		std::cout << std::setw(10) << str << "|";
}

void	phonebook::search_command(void)
{
	int		i;
	std::string idx;

	i = 0;
	if (this->contacts_num == 0)
	{
		std::cout << "EMPTY PHONEBOOK" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name| nick name|" << std::endl;
	while (i < this->contacts_num)
	{
		print_phonebook(i);
		i++;
	}
	std::cout << "select index : ";
	std::getline(std::cin, idx);
	if (idx == "\0")
	{
		std::cout << "please input number, try search again" << std::endl;
		return ;
	}
	if (!check_str(idx))
	{
		std::cout << "wrong input, try search again" << std::endl;
		return ;
	}
	i = atoi(idx.c_str());
	if (i + 1 > this->contacts_num)
	{
		std::cout << "out of index range, try search again" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name| nick name|" << std::endl;
	print_phonebook(i);
}

void	phonebook::print_phonebook(int i)
{
	std::cout << std::setw(10) << i << "|";
	printf_output(this->first_name[i]);
	printf_output(this->last_name[i]);
	printf_output(this->nick_name[i]);
	std::cout << std::endl;
}
