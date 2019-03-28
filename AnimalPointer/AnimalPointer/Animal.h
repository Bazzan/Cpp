#pragma once
class Animal
{
private:
	int vikt;
	int refCount;
	friend class AnimalPointer;


public:
	Animal(int v);
	int getVikt() const;

};

