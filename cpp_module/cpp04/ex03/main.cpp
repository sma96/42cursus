#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MteriaSource.hpp"
#include "AMteria.hpp"

int main(void)
{
    // // AMteria *cure = new Cure();
    // // AMteria *ice = new Ice();
    // // ICharacter *ch = new Character();
    // // Character cha;

    // // // std::cout << cure->getType() << std::endl;
    // // // std::cout << ice->getType() << std::endl;

    // // ch->equip(ice);
    // // ch->equip(cure);
    // // ch->equip(ice);
    // // ch->equip(cure);
    // // ch->equip(ice);
    // // ch->equip(cure);
    // // ch->use(3, cha);
    // // ch->getInventory();
    // MteriaSource materiaSource;
    // materiaSource.learnMateria(new Ice());
    // materiaSource.learnMateria(new Cure());

    // // materiaSource.info();

    // Character ash("Ash");
    // Character gale("Gale");

    // ash.equip(materiaSource.createMateria("Ice"));
    // ash.equip(materiaSource.createMateria("Cure"));

    // ash.getInventory();

    // ash.use(0, gale);

    // gale.getInventory();

    // gale = ash;

    // gale.getInventory();

    // ash.unequip(0);

    // ash.getInventory();
    // std::cout << "---------------------------" << std::endl;
    // gale.getInventory();

    // ash.equip(materiaSource.createMateria("Ice"));
    // ash.equip(materiaSource.createMateria("Ice"));
    // ash.equip(materiaSource.createMateria("Ice"));
    // ash.equip(materiaSource.createMateria("Ice"));

    // ash.getInventory();
    // delete cure;
    // delete ice;

    IMateriaSource* src = new MteriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMteria* tmp;
	tmp = src->createMateria("Ice");
	me->equip(tmp);
	tmp = src->createMateria("Cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

    return 0;
}