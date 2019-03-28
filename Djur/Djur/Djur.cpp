#include "Djur.h"



#include <iostream>
#include<string>
#include <vector>



class Djur
{
private:
	std::string namn;
	int vikt;
public:
	Djur * djur;

	//Djur(const Djur&);
	//const Djur& operator=(const Djur& other);
	std::string getName() { return namn; }
	int getVikt() const { return vikt; }
	virtual int getVarde() const = 0;
	virtual ~Djur(){}
protected:
	Djur(std::string n, int v) : namn(n), vikt(v) {}

};


class Elefant : public Djur {
private:
	int snabel;
	Elefant * elefant;
public:
	static Elefant * create(std::string n, int v, int s);

	int getSnabel() const { return snabel; }
	void setSnabel(int nySnabel) { snabel = nySnabel;}
	
	int getVarde() const { return snabel * this->getVikt(); }

protected:
	Elefant(std::string n, int v, int s) : Djur(n, v), snabel(s) {}


};

Elefant * Elefant::create(std::string n, int v, int s) {
	return new Elefant(n, v, s);
}





class Tusenfoting : public Djur {
private:
	double * fotter;
	Tusenfoting * tusenF;
public:

	static Tusenfoting * create(std::string n, int v);

	void setFot(int pos, double vad) { fotter[pos] = vad; }

	int getVarde() const {
		double sum = 0;
		for (int i = 0; i < 1000; i++) {
			sum += fotter[i];
		}
		return this->getVikt() + static_cast<int>(sum);
	}

	~Tusenfoting() { delete[] fotter; }


protected:
	Tusenfoting(std::string n, int v) : Djur(n, v) {
		fotter = new double[1000];
	}

};


Tusenfoting* Tusenfoting::create(std::string n, int v) {
	//Tusenfoting * fotter = new double[1000];
	return new Tusenfoting(n, v);
}


int main() {
	std::vector<Djur*> flock;
	// Skapar en massa Elefant-objekt och stoppar in i flock
	
	Elefant * dumbo = Elefant::create("Dumbo", 10000, 50);
	Tusenfoting * baj = Tusenfoting::create("baj", 100);
	flock.push_back(dumbo);
	flock.push_back(baj);

	int snabelLängd = 0;
	int antalSnablar = 0;
	int vardeSum = 0;

	for (Djur* f : flock) {
		std::cout << f->getName() << f->getVikt() << " " << f->getVarde() << std::endl;
	
	}

	for (Djur* f : flock) {
		vardeSum += f->getVarde();
		if (Elefant * e = dynamic_cast<Elefant*>(f)) {
			antalSnablar++;
			snabelLängd += e->getSnabel();
		}
	}

	std::cout << "värdet är: " << vardeSum << std::endl;



	//Skriv även om det lilla testprogrammet så att det anpassas till de nya klasserna.
	//	Bl.a.ska det bara finnas en enda samling för alla Djuren.
	//	Istället för tre loopar med genomgångar av samlingarna bör det finnas en enda loop.
	//	Funktionaliteten ska dock vara likadan : det totala värdet och genomsnittliga snabellängden för
	//	Elefanterna ska skrivas ut.



	//int summaVarde = 0;
	//for (int i = 0; i < flock.size(); i++)
	//	summaVarde += flock[i].getVarde();
	//for (int i = 0; i < skara.size(); i++)
	//	summaVarde += skara[i].getVarde();
	//std::cout << "Värdet totalt: " << summaVarde << std::endl;
	//if (flock.empty())
	//	std::cout << "Inga elefanter!" << std::endl;
	//else {
	//	int snabelSumma = 0;
	//	for (int i = 0; i < flock.size(); i++)
	//		snabelSumma += flock[i].getSnabel();
	//	std::cout << "Genomsnittlig snabel: " <<
	//		static_cast<double>(snabelSumma) / flock.size() << std::endl;
	//}

	std::cin;
	return 0;
}