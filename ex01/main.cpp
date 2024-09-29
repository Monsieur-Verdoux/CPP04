/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:32 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/26 20:15:07 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	Animal** animals = new Animal*[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << "\033[1;93mTesting that the array was properly filled: \033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	delete[] animals;
	std::cout << std::endl;

	Cat* Archibald = new Cat();

	Archibald->fetchBrain()->implementIdea(0, "Run around at supersonic speeds");
	Archibald->fetchBrain()->implementIdea(1, "Chew the Christmas tree");
	Archibald->fetchBrain()->implementIdea(2, "Slice Andrey's arms with my sharp claws");

	std::cout << std::endl;
	std::cout << "\033[1;93mTesting Cat copy! \033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;93mArchibald's ideas: \033[0m" << std::endl;

	std::cout << Archibald->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << Archibald->fetchBrain()->fetchIdea(1) << std::endl;
	std::cout << Archibald->fetchBrain()->fetchIdea(2) << std::endl;
	std::cout << Archibald->fetchBrain()->fetchIdea(3) << std::endl;

	std::cout << std::endl;
	Cat* ArchibaldJr = new Cat(*Archibald);

	std::cout << std::endl;

	std::cout << "\033[1;93mArchibaldJr's ideas: \033[0m" << std::endl;

	std::cout << ArchibaldJr->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << ArchibaldJr->fetchBrain()->fetchIdea(1) << std::endl;
	std::cout << ArchibaldJr->fetchBrain()->fetchIdea(2) << std::endl;
	std::cout << ArchibaldJr->fetchBrain()->fetchIdea(3) << std::endl;

	std::cout << std::endl;

	ArchibaldJr->fetchBrain()->implementIdea(2, "Hide in the shadows waiting to strike");

	std::cout << "\033[1;93mAfter changing ArchibaldJr's idea [2]: \033[0m" << std::endl;
	std::cout << "\033[1;36mArchibald's idea [2]: \033[0m" << Archibald->fetchBrain()->fetchIdea(2) << std::endl;
	std::cout << "\033[1;36mArchibaldJr's idea [2]: \033[0m" << ArchibaldJr->fetchBrain()->fetchIdea(2) << std::endl;

	std::cout << std::endl;

	delete Archibald;
	delete ArchibaldJr;
	
	std::cout << std::endl;
	std::cout << "\033[1;93mTesting Dog copy! \033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;93mSansa's ideas: \033[0m" << std::endl;

	Dog* Sansa = new Dog();
	Sansa->fetchBrain()->implementIdea(0, "Beg for a treat");
	Sansa->fetchBrain()->implementIdea(1, "Go for a walk");
	std::cout << std::endl;

	std::cout << "\033[1;93mSansa's ideas: \033[0m" << std::endl;
	std::cout << Sansa->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << Sansa->fetchBrain()->fetchIdea(1) << std::endl;

	std::cout << std::endl;
	Dog* Asterix = new Dog(*Sansa);
	std::cout << std::endl;
	
	std::cout << "\033[1;93mAsterix's ideas: \033[0m" << std::endl;
	std::cout << Asterix->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << Asterix->fetchBrain()->fetchIdea(1) << std::endl;

	std::cout << std::endl;
	Asterix->fetchBrain()->implementIdea(0, "Devour the delicious homework");

	std::cout << "\033[1;93mAfter changing Asterix's idea [0]: \033[0m" << std::endl;
	std::cout << "\033[1;36mSansa's idea [0]: \033[0m" << Sansa->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << "\033[1;36mAsterix's idea [0]: \033[0m" << Asterix->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << std::endl;

	
	std::cout << "\033[1;93mAfter changing Sansa's idea [1]: \033[0m" << std::endl;
	std::cout << "\033[1;36mSansa's idea [1]: \033[0m" << Sansa->fetchBrain()->fetchIdea(1) << std::endl;
	std::cout << "\033[1;36mAsterix's idea [1]: \033[0m" << Asterix->fetchBrain()->fetchIdea(1) << std::endl;
	std::cout << std::endl;

	delete Sansa;
	delete Asterix;

	std::cout << std::endl;
	std::cout << "\033[1;93mTesting assignment operator! \033[0m" << std::endl;
	std::cout << std::endl;
	
	Cat* Pepsi = new Cat();
	Cat* Dumle = new Cat();

	Pepsi->fetchBrain()->implementIdea(0, "Shed fur everywhere");
	Dumle->fetchBrain()->implementIdea(0, "Hide until the guests leave");

	std::cout << std::endl;
	std::cout << "\033[1;93mInitial ideas: \033[0m" << std::endl;
	std::cout << "\033[1;36mPepsi's idea [0]: \033[0m" << Pepsi->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << "\033[1;36mDumle's idea [0]: \033[0m" << Dumle->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << std::endl;

	*Dumle = *Pepsi;
	std::cout << std::endl;

	std::cout << "\033[1;93mIdeas after reassignment: \033[0m" << std::endl;
	std::cout << "\033[1;36mPepsi's idea [0]: \033[0m" << Pepsi->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << "\033[1;36mDumle's idea [0]: \033[0m" << Dumle->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	Dumle->fetchBrain()->implementIdea(0, "Purr loudly");

	std::cout << "\033[1;93mAfter changing Dumle's idea [0]: \033[0m" << std::endl;
	std::cout << "\033[1;36mDumle's idea [0]: \033[0m" << Dumle->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << "\033[1;36mPepsi's idea [0]: \033[0m" << Pepsi->fetchBrain()->fetchIdea(0) << std::endl;
	std::cout << std::endl;

	delete Dumle;
	delete Pepsi;
	
	return 0;
}