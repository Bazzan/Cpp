#pragma once
#include <iostream>
#include <string>

namespace boats {



	class Boat
	{
	private:
		std::string name;
		int lenght;
	public:


		Boat(std::string n, int len);
		std::string getName() const;
		int getLenght() const;

		~Boat();
	};

	void printBoat(Boat* aBoat);


}