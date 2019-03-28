#pragma once
#include <string>
#include <iostream>
#include <vector>



class Djur
{
private:
	std::string namn;
	int vikt;
	int vard;

public:
	std::string getNamn() const { return namn; }
	int getVikt() const { return vikt; }
	virtual int getVarde() const = 0;
	
	Djur(const Djur&) = delete;
	const Djur& operator=(const Djur& other) = delete;

	~Djur();
protected:
	Djur(std::string n, int v) :namn(n), vikt(v) {}

};


class Elefant : public Djur {
private:
	int snabel;
public:
	static Elefant * create(std::string n, int v, int s);
	int getSnable() const { return snabel; }
	void setSnabel(int ny) {
		snabel = ny;
	}
	int getVarde() const { return snabel * getVikt(); }


protected:

	Elefant(std::string n, int v, int s) :Djur(n, v), snabel(s) {}

};

Elefant * Elefant::create(std::string n, int v, int s) {
	return new Elefant(n, v, s);
}


class Tusenfoting:public Djur {
private:
	std::string namn;
	int vikt;
	double* fotter;

public:

	static Tusenfoting* create(std::string n, int v);
	~Tusenfoting() { delete[] fotter; }
	void setFot(int pos, double vad) { fotter[pos] = vad; }
	
	int getVarde() const {
		double sum = 0;
		for (int i = 0; i < 1000; i++)
			sum += fotter[i];
		return vikt + sum;
	}

protected:

	Tusenfoting(std::string n, int v) : Djur(n,v)  {
		//fotter = new double[1000];
	}
};

Tusenfoting * Tusenfoting::create(std::string n, int v) {
	return new Tusenfoting(n, v);
}

int main() {
	std::vector<Djur*> flock;


	Elefant * DingleBerry = Elefant::create("dingleBerry", 1000, 55);
	Elefant * dumbo = Elefant::create("dumbo", 100, 5);
	Elefant * ding = Elefant::create("ding", 10000, 3);

	Tusenfoting * bajja = Tusenfoting::create("Bajja", 100);
	flock.push_back(bajja);
	flock.push_back(DingleBerry);
	flock.push_back(dumbo);
	flock.push_back(ding);

	Djur* d;

	int summa;
	int snablar;
	int snabelmedel;

	//for (int i = 0; i < flock.size(); i++) {
	//	std::cout << d->getNamn() << ", " << d->getVikt() << ", " << d->getVarde() << std::endl;

	//}

	for(Djur * d : flock) {
		std::cout << d->getNamn() << ", " << d->getVikt() << ", " << d->getVarde() << std::endl;

	}


	std::cin;
	return 0;
}