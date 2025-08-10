#ifndef CURE_HPP
#define CURE_HPP

#include "AMteria.hpp"

class Cure : public AMteria{
	public:
		Cure(void);
		Cure(std::string const &type);
		Cure(const Cure &tmp);
		~Cure(void);
		
		Cure &operator=(const Cure &tmp);

		AMteria *clone(void) const;
		void	use(ICharacter &target);
};

#endif