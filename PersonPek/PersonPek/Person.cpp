#pragma once
#include <string>
#include <iostream>


class Person {
public:
	Person(std::string n) :name(n) {}
	std::string getName() const { return name; }

private:
	std::string name;
	int refCount = 0; // Anv�nds av objekt av Pointer-klassen
	friend class Pointer; // Pointer-objekt f�r �tkomst till private data
};

class Pointer {
public:
	Pointer(Person *p = 0) :pers(p) {
		if (pers != nullptr)
			pers->refCount++;
	}



	Person* operator->() const {
		if (pers == nullptr)
			throw std::logic_error("Null Pointer!");
		return pers;
	}

	Pointer(const Pointer& other) :pers(other.pers){
		if (pers != nullptr) {
			pers->refCount++;
		}
		return;
	}

	~Pointer() {
		if (pers != nullptr) {
			pers->refCount++;
		}
	}

	const Pointer operator=(const Pointer& other) {
		if (pers != other.pers) {
			if (pers && --pers->refCount == 0) {
				delete pers;
			}
			pers = other.pers;
			if (pers) {
				pers->refCount++;
			}

		}
		return *this;
	}


private:
	Person *pers;
};int main() {
}