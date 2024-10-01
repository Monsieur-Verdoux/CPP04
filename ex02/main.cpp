/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:32 by akovalev          #+#    #+#             */
/*   Updated: 2024/10/01 16:41:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	//Animal* animal = new Animal();
	const Animal* Archibald = new Cat();

	Archibald->makeSound(); 
	std::cout << "\033[1;93m" << Archibald->getType() << "\033[0m" << std::endl;
	delete Archibald;

	const Dog Sansa;
	Sansa.makeSound(); 
	std::cout << "\033[1;93m" << Sansa.getType() << "\033[0m" << std::endl;

	return 0;
}