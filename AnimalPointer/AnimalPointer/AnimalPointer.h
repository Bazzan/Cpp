#pragma once
#include"Animal.h"
class AnimalPointer
{
private:
	Animal* theAnimal;

public:
	AnimalPointer(Animal* a = 0);
	~AnimalPointer();

	int getVikt() const;
	AnimalPointer(const AnimalPointer& other);
	const AnimalPointer& operator=(const AnimalPointer& other);


};

