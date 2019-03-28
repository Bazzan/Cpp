#pragma once
#include "Boat.h"


namespace boats{
class SailingBoat: public Boat
{
private:
	bool wood;

public:
	SailingBoat(std::string n, int len, bool wood);
	~SailingBoat();
};


}