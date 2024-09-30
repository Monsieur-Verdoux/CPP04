/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:04:29 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/30 14:04:29 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

 MateriaSource::MateriaSource()
 {
	_count = 0;
	for (int i = 0; i < 4; i++)
		_materias[i] = nullptr;
 }

MateriaSource::~MateriaSource() 
{
	for (int i = 0; i < 4; i++) 
	{
		if (_materias[i])
			delete (_materias[i]);
	}
}

MateriaSource::MateriaSource(const MateriaSource& original)
{
	_count = original._count;
	for (int i = 0; i < 4; i++)
	{
		if (original._materias[i])
			_materias[i] = original._materias[i]->clone();
		else
			_materias[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& original)
{
	if (this != &original)
	{
		_count = original._count;
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
				delete (_materias[i]);
			if (original._materias[i])
				_materias[i] = original._materias[i]->clone();
			else
				_materias[i] = nullptr;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* new_materia)
{
	if (new_materia && _count < 4) 
	{
		_materias[_count] = new_materia;
		_count++;
	}
	else if (_count == 4)
		std::cout << "\033[1;31mMateria Source is full!\033[0m"  << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _count; i++) 
	{
		if (_materias[i] && _materias[i]->getType() == type) {
			return (_materias[i]->clone());
		}
	}
	std::cout << "\033[1;31mMateria creation failed: no type match\033[0m"  << std::endl;
	return (0);
}