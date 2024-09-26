/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:06:25 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/26 19:47:52 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(): _type("An unidentified yet fearsome creature")
{
	std::cout << "\033[1;32mDefault Animal constructor called\033[0m"  << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[1;31mDefault Animal destructor called\033[0m"  << std::endl;
}

Animal::Animal(const Animal& original): _type(original._type)
{
	std::cout << "\033[1;33mCopy Animal constructor called\033[0m" << std::endl;
}

Animal& Animal::operator=(const Animal& original)
{
	std::cout << "\033[1;36mCopy assignment Animal operator called\033[0m" << std::endl;
	if(this != &original)
	{
		std::cout << "\033[1;36mThe Animal formerly identified as "<< _type << " is now " << original._type << "\033[0m" << std::endl;
		_type = original._type;
	}
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "\033[1;93m*Disturbing gurgling sounds* You can't tell if it a meow or a bark...\033[0m"  << std::endl;
}

std::string Animal::getType() const
{
	return(_type);
}
