#include "Dish.h"

namespace Food {

	Dish::Dish(std::string n, int c) : name(n), calories(c)
	{
	}


	int Dish::getCalories() const { return calories; }
	std::string Dish::getName() const { return name; }



	void printDish(Dish* dish) {
		std::cout << dish->getName() << ": " << dish->getCalories() << std::endl;
	}


}