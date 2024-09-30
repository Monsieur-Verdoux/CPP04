/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:04:30 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/30 14:04:30 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[4];
		int _count;
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource& original);
		MateriaSource& operator=(const MateriaSource& original);

		virtual void learnMateria(AMateria* new_materia) override;
		virtual AMateria* createMateria(std::string const & type) override;
};

#endif