#include "AnimalPointer.h"


AnimalPointer::AnimalPointer(Animal* a = 0) : theAnimal(a) {
	if (theAnimal) {
		theAnimal->refCount++;
	}
}


AnimalPointer::~AnimalPointer() {
	if (theAnimal && --theAnimal->refCount == 0) {
		delete theAnimal;
	}
}

int AnimalPointer::getVikt() const { return getVikt(); }

AnimalPointer::AnimalPointer(const AnimalPointer& other) : theAnimal(other.theAnimal) {
	if (theAnimal) {
		theAnimal->refCount++;
	}
}

const AnimalPointer& AnimalPointer::operator=(const AnimalPointer& other) {
	if (theAnimal != other.theAnimal) {
		if (theAnimal && --theAnimal->refCount == 0) {
			delete theAnimal;
		}
		theAnimal = other.theAnimal;
		theAnimal->refCount++;
	}
	return *this;
}