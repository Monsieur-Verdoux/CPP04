/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:07:22 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/25 18:43:16 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	std::cout << "\033[1;32mDefault Cat constructor called\033[0m"  << std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "\033[1;31mDefault Cat destructor called\033[0m"  << std::endl;
}

Cat::Cat(const Cat& original): Animal(original)
{
	std::cout << "\033[1;33mCopy Cat constructor called\033[0m" << std::endl;
	_type = original._type;
}

Cat& Cat::operator=(const Cat& original)
{
	std::cout << "\033[1;36mCopy assignment Cat operator called\033[0m" << std::endl;
	if(this != &original)
	{
		std::cout << "\033[1;36mThe Cat formerly identified as "<< _type << " is now " << original._type << "\033[0m" << std::endl;
		_type = original._type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "\033[1;93m*Meow*\033[0m"  << std::endl;
}