#ifndef DISH_H
#define DISH_H

#include <string>
#include<iostream>

namespace Food {

	class Dish
	{
	private:
		std::string name;
		int calories;

	public:
		Dish(std::string n, int c) ;

		std::string getName() const;
		int getCalories() const;


	};
	void printDish(Dish* dish);
}


#endif // !1
