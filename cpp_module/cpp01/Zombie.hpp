#ifndef	ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class zombie
{
	private:
		std::string name;

	public:
		zombie(void);
		~zombie(void);
		void	setName(std::string str);
		void    announce(void);
};

zombie	*zombiehorde(int n, std::string name);
std::string make_num(int num);

#endif