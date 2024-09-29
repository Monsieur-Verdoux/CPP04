/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:02 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/25 18:58:54 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "\033[1;32mDefault WrongCat constructor called\033[0m"  << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;31mDefault WrongCat destructor called\033[0m"  << std::endl;
}

WrongCat::WrongCat(const WrongCat& original): WrongAnimal(original)
{
	std::cout << "\033[1;33mCopy WrongCat constructor called\033[0m" << std::endl;
	_type = original._type;
}

WrongCat& WrongCat::operator=(const WrongCat& original)
{
	std::cout << "\033[1;36mCopy assignment WrongCat operator called\033[0m" << std::endl;
	if(this != &original)
	{
		std::cout << "\033[1;36mThe WrongCat formerly identified as "<< _type << " is now " << original._type << "\033[0m" << std::endl;
		_type = original._type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "\033[1;93m*Mooooeow?*\033[0m"  << std::endl;
}