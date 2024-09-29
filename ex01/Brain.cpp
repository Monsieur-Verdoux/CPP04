/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:42:00 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/29 17:42:00 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "\033[1;32mNew Brain has spawned\033[0m"  << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "No idea!";
}

Brain::~Brain()
{
	std::cout << "\033[1;31mThe Brain has melted away\033[0m"  << std::endl;
}

Brain::Brain(const Brain& original)
{
	std::cout << "\033[1;33mCopy Brain constructor called\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = original._ideas[i];
}
Brain& Brain::operator=(const Brain& original)
{
	std::cout << "\033[1;36mCopy assignment Brain operator called\033[0m" << std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = original._ideas[i];
	}
	return (*this);
}

void	Brain::implementIdea(int id, const std::string& idea)
{
	if (id < 0 || id > 99)
		std::cout << "Invalid id, only range of 0-100 is allowed";
	else 
		this->_ideas[id] = idea; 
	
}
std::string Brain::fetchIdea(int id) const
{
	if (id < 0 || id > 99)
	{
		std::cout << "Invalid id, only range of 0-100 is allowed";
		return "";
	}
	else 
		return(this->_ideas[id]);
}