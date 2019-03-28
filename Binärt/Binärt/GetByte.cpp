#pragma
#include <iostream>
unsigned long int uli;

unsigned int get(unsigned long int uli, int nr) {
	unsigned int sum;
	unsigned int p2;
	uli = (uli >> (4 * nr) ) & 0xfU;

}

void set(unsigned long int& uli, int nr, unsigned int value) {
	uli &= ~(0xfU << nr * 4);
	uli |= value << nr * 4;
}

int main() {
	const char printf(0xfU);
	
}