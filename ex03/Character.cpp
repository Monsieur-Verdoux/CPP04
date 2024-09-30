/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:04:17 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/30 14:04:17 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(): _name("John Doe"), _inventoryCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete(_inventory[i]);
	}
}

Character::Character(std::string name): _name(name), _inventoryCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& original): _name(original._name), _inventoryCount(original._inventoryCount)
{
	for (int i = 0; i < 4; i++)
		if (original._inventory[i])
			_inventory[i] = original._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
}

Character& Character::operator=(const Character& original)
{
	if (this != &original)
	{
		_name = original._name;
		_inventoryCount = original._inventoryCount;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (original._inventory[i])
				_inventory[i] = original._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (m && _inventoryCount < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				_inventoryCount++;
				return;
			}
		}
	}
	else if (_inventoryCount == 4)
		std::cout << "\033[1;31mInventory is full!\033[0m"  << std::endl;
}
void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "\033[1;31mMateria unequip failed: incorrect idx\033[0m"  << std::endl;
		return;
	}
	if (_inventory[idx])
	{
		_inventory[idx] = nullptr;
		_inventoryCount--;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "\033[1;31mMateria use failed: incorrect idx\033[0m"  << std::endl;
		return;
	}
	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
		return;
	}
	std::cout << "\033[1;31mMateria use failed: not equipped\033[0m"  << std::endl;
}