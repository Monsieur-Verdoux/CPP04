/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:00 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/25 18:47:04 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	std::cout << "\033[1;32mDefault Dog constructor called\033[0m"  << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "\033[1;31mDefault Dog destructor called\033[0m"  << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& original): Animal(original)
{
	std::cout << "\033[1;33mCopy Dog constructor called\033[0m" << std::endl;
	_type = original._type;
	_brain = new Brain(*original._brain);
}

Dog& Dog::operator=(const Dog& original)
{
	std::cout << "\033[1;36mCopy assignment Dog operator called\033[0m" << std::endl;
	if(this != &original)
	{
		std::cout << "\033[1;36mThe Dog formerly identified as "<< _type << " is now " << original._type << "\033[0m" << std::endl;
		_type = original._type;
		delete _brain;
		_brain = new Brain(*original._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "\033[1;93m*Bark*\033[0m"  << std::endl;
}

Brain* Dog::fetchBrain() const
{
	return(this->_brain);
}