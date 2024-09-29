/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:51 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/25 18:58:56 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): _type("An unidentified yet fearsome creature")
{
	std::cout << "\033[1;32mDefault WrongAnimal constructor called\033[0m"  << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;31mDefault WrongAnimal destructor called\033[0m"  << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original): _type(original._type)
{
	std::cout << "\033[1;33mCopy WrongAnimal constructor called\033[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	std::cout << "\033[1;36mCopy assignment WrongAnimal operator called\033[0m" << std::endl;
	if(this != &original)
	{
		std::cout << "\033[1;36mThe WrongAnimal formerly identified as "<< _type << " is now " << original._type << "\033[0m" << std::endl;
		_type = original._type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[1;93m*Even more disturbing sounds that cause you to shiver all over*\033[0m"  << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(_type);
}