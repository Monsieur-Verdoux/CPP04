/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:32 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/26 20:15:07 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\033[1;36m" << j->getType() << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << i->getType() << "\033[0m" << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		const Animal* i = new Cat();
		i->makeSound();
		delete i;

		Cat cat;
		Dog dog;
		Animal animal;
		cat.makeSound(); 
		dog.makeSound();
		animal.makeSound();
	}
	std::cout << std::endl;
	{
		const WrongAnimal* i = new WrongCat();
		i->makeSound();
		delete i;

		WrongCat tac;
		tac.makeSound(); 
	}
	std::cout << std::endl;
	{
		const WrongCat* i = new WrongCat();
		i->makeSound();
		delete i;
	}
	std::cout << std::endl;
	{
		Cat kitty;
		Animal purr;
		Animal hurr(purr);
		std::cout << "\033[1;36mHurr's type: " << hurr.getType() << "\033[0m" << std::endl;
		std::cout << "\033[1;36mPurr's type: " << purr.getType() << "\033[0m" << std::endl;
		purr = kitty;
		std::cout << "\033[1;36mPurr's type: " << purr.getType() << "\033[0m" << std::endl;

		Animal murr(purr);	
		std::cout << "\033[1;36mMurr's type: " << murr.getType() << "\033[0m" << std::endl;

	}
	return 0;
}