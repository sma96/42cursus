#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class phonebook{

	private:
		int         index;
		int         contacts_num;
		std::string first_name[8];
		std::string last_name[8];
		std::string nick_name[8];
		std::string phone_number[8];
		std::string darkest_secret[8];

		void    printf_output(std::string str);
		int		check_str(std::string str);

    public:
		void    init(void);
		void    fill_info(void);
		void	search_command(void);
        void	print_phonebook(int i);
};
#endif