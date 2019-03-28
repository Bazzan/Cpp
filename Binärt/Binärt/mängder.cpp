typedef unsigned int Set;


void add(Set& set, int value) {
	set = (set << 8) | value;
}



void sub(Set& set, int value) {
	set & ~(1U << value);
}


bool isMember(Set set, int value) {
	return set & (1U << value);
}
Set intersection(Set s1, Set s2) {
	s1 & s2;
	}
