#include "Boat.h"
#include "SailingBoat.h"

using namespace boats;


int main() {
	Boat* theBoats[3];

	theBoats[0] = new Boat("Octo", 105);
	theBoats[1] = new SailingBoat("Pussy", 23, false);
	theBoats[2] = new SailingBoat("xxx", 8, false);
	for (int i = 0; i < 3; i++) {
		printBoat(theBoats[i]);
	}

	std::cin;
	return 0;


}
