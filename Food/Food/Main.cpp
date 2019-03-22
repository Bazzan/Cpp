#include "Vegetable.h"
#include "Dish.h"
using namespace Food;

int main() {
	Dish* supper[3];

	supper[0] = new Dish("Hamburgare", 1500);
	supper[1] = new Vegetable(true);
	supper[2] = new Dish("Tårta", 5000);
	for (int i = 0; i < 3; i++) {
		printDish(dynamic_cast<Dish*>(supper[i]));

	}
	std::cin;
	return 0;
}