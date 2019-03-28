#include "Animal.h"


Animal::Animal(int v):vikt(v),refCount(0) {}

int Animal::getVikt() const { return vikt; }

