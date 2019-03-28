#include "Boat.h"


using namespace boats;

Boat::Boat(std::string n, int len) : name(n), lenght(len) {}


std::string Boat::getName() const { return name; }
int Boat::getLenght() const { return lenght; }

void printBoat(Boat * aBoat) {
	std::cout << aBoat->getName() << ": " << aBoat->getLenght() << std::endl;

}


