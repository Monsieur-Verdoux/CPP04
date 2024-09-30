/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:25:11 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/30 16:25:11 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "\033[1;36mOriginal test: \033[0m" << std::endl;
		std::cout << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	{	
		std::cout << std::endl;
		std::cout << "\033[1;36mMateria reassignment type preservation: \033[0m" << std::endl;
		std::cout << std::endl;
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();

		std::cout << ice->getType() << std::endl;
		std::cout << cure->getType() << std::endl;

		*ice = *cure;
		std::cout << std::endl;
		std::cout << "\033[1;95mAfter reassignment: \033[0m" << std::endl;
		std::cout << std::endl;


		std::cout << ice->getType() << std::endl;
		std::cout << cure->getType() << std::endl;
		delete ice;
		delete cure;
	}
	{
		std::cout << std::endl;
		std::cout << "\033[1;36mCharacter copy testing: \033[0m" << std::endl;
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		Ice* ice = new Ice();
		Cure* cure = new Cure();
		Ice* ice1 = new Ice();
		me->equip(ice);
		me->equip(cure);

		ICharacter* myShadow = new Character(*dynamic_cast<Character*>(me));
		myShadow->use(0, *me);
		myShadow->use(1, *me);

		myShadow->unequip(1);
		myShadow->equip(ice1);

		myShadow->use(1, *me);
		me->use(1, *myShadow);

		delete me;
		delete myShadow;
	}
	{
		std::cout << std::endl;
		std::cout << "\033[1;36mVarious fail case testing: \033[0m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		std::cout << std::endl;
		std::cout << "\033[1;93mAssigning more than 4 materias to Materia Source: \033[0m" << std::endl;
		std::cout << std::endl;
		src->learnMateria(new Ice());

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		std::cout << std::endl;
		std::cout << "\033[1;93mTrying to use not yet equipped slot \033[0m" << std::endl;
		std::cout << std::endl;
		me->use(0, *bob);

		std::cout << std::endl;
		std::cout << "\033[1;93mTrying to create materia type not in the source \033[0m" << std::endl;
		std::cout << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		std::cout << std::endl;
		std::cout << "\033[1;93mTrying to use already uneqipped slot \033[0m" << std::endl;
		std::cout << std::endl;
		me->unequip(0);
		me->use(0, *bob);

		std::cout << std::endl;
		std::cout << "\033[1;93mTrying to use incorrect idx slot \033[0m" << std::endl;
		std::cout << std::endl;
		me->use(10, *bob);

		std::cout << std::endl;
		std::cout << "\033[1;93mTrying to unequip incorrect idx slot \033[0m" << std::endl;
		std::cout << std::endl;
		me->unequip(12);

		std::cout << std::endl;
		std::cout << "\033[1;93mTrying to equip too many materias \033[0m" << std::endl;
		std::cout << std::endl;
		AMateria* tmp0 = src->createMateria("ice");
		AMateria* tmp1 = src->createMateria("ice");
		AMateria* tmp2 = src->createMateria("ice");
		AMateria* tmp3 = src->createMateria("ice");
		AMateria* tmp4 = src->createMateria("ice");
		me->equip(tmp0);
		me->equip(tmp1);
		me->equip(tmp2);
		me->equip(tmp3);
		me->equip(tmp4);
		
		delete tmp4;
		delete src;
		delete bob;
		delete me;
	}
}