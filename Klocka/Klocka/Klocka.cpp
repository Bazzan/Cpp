class Klocka {
public:
	explicit Klocka(int h = 0, int m = 0) :mem(h * 60 + m) {
		if (mem > 60 * 24)
			throw std::out_of_range("Ogilltigt klockslag!");
	}
	Klocka(){}
	Klocka(const Klocka& ) {	
	}

	Klocka& operator++(int) { //postfix v++
		Klocka temp(*this);
		this->mem += 1;
		return temp;
	}
	Klocka operator++()  { // prefix ++v
		this->mem += 1;
		return (*this);
	}

	const Klocka& operator=(const Klocka& other) {
		if (this != &other) {
			this->mem = other.mem;
		}
		return *this;
	}

	Klocka operator+(int value) {
		Klocka temp(*this);
		temp.mem += value;
		return temp;
	}

	const Klocka& operator+=(int value) {
		Klocka(*this);
		this->mem += value;
		return *this;
	}


private:
	int mem; // Minuter efter midnatt
	Klocka * ptr;
};int main() {
}