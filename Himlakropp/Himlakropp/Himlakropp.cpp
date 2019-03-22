#include <string>
#include <vector>
#include <iostream>
#include "Himlakropp.h"


class Himlakropp {

private:
	std::string namn;
	int dia;
	//Himlakropp(const Himlakropp&);
	//const Himlakropp& operator= (const Himlakropp&);

public:
	virtual int getVikt() const = 0;

	int getDia() const { return dia; }

	std::string getName() const { return namn;  }

	~Himlakropp() {	}
protected:
	Himlakropp(std::string n, int d) : namn(n), dia(d)	{}


};


class Måne : public Himlakropp {

private:
	int kratrar;
public:
	int getVikt() const {
		int v = (10 * getDia()) - kratrar;
		return v;
	}
	
	
	static Måne * create(std::string n, int d, int k);


protected:
	Måne(std::string n, int d, int k):Himlakropp(n,d), kratrar(k) {}

};

Måne*  Måne::create(std::string n, int d, int k){
	return new Måne(n, d,k);
}


class Planet :public Himlakropp {
private:
	bool atmo;
	Måne * måne;
public:
	static Planet * create(std::string n, int d, bool a);
	static Planet * create(std::string n, int d, bool a, Måne* måne);

	int getVikt() const {
		int vp = (10 * getDia());
		if (atmo) {
			vp *= 2; 
		}
		if (måne) {
			vp += måne->getVikt();
		}
		return vp;
	}


	void  addMåne(Måne * m) {
		if (måne) {
			delete måne;
			måne = m;
		}
	}

	//std::string getMåne() const { return måne->getName; }


protected:
	Planet(std::string n, int d, bool a) : Himlakropp(n, d), atmo(a) {}
	Planet(std::string n, int d, bool a, Måne * m) : Himlakropp(n, d), atmo(a),  måne(m) {
		if (måne) {
			måne = m;
		}
	}

};

Planet * Planet::create(std::string n, int d, bool a) {
	return new Planet(n, d, a);
}
Planet * Planet::create(std::string n, int d, bool a, Måne* m) {
	return new Planet(n, d, a, m);
}


class Stjärna : public Himlakropp {

private:
	int ljus;
	std::vector<Himlakropp*> system;

public:
	static Stjärna* create(std::string n, int d, int s);

	int getLjus() { return ljus; }

	void addHimla(Himlakropp* ny) { system.push_back(ny); }
	int getVikt() const;


protected:

	Stjärna(std::string n, int d, int s) : Himlakropp(n, d), ljus(s) {}
	// initiera vector för himlakroppar
};

int Stjärna::getVikt()const {
	int v = ljus * getDia();
	for (int i = 0; i < system.size(); i++) {
		v += system[i]->getVikt();
		if (Stjärna* stjärna = dynamic_cast<Stjärna*>(system[i])) {
			v += stjärna->getLjus();
		}
	}

	return v;
}
Stjärna * Stjärna::create(std::string n, int d, int s) {
	return new Stjärna(n, d, s);
}

int main() {
	std::string mell = ", ";

	//Himlakropp * måne;
	Måne *måne = Måne::create("dumbo", 1000, 50);
	Måne *måne2 = Måne::create("bimbo", 100, 50);

	Planet *planet = Planet::create("jorden", 5000, true);
	Planet *planet2 = Planet::create("jorden2", 5000, false, måne );
	
	Stjärna * stjärna1 = Stjärna::create("solen", 1000000, 5);
	std::cout << stjärna1->getName() << mell << stjärna1->getDia() << mell << stjärna1->getVikt() << mell << stjärna1->getLjus() << mell << std::endl;

	stjärna1->addHimla(planet2);
	stjärna1->addHimla(måne);


	std::cout << stjärna1->getName() << mell << stjärna1->getDia() << mell << stjärna1->getVikt() << mell << stjärna1->getLjus() << mell << std::endl;

	std::cout << måne->getName() << mell << måne->getDia() << mell << måne->getVikt() << std::endl;
	std::cout << måne2->getName() << mell << måne2->getDia() << mell << måne2->getVikt() << std::endl;

	std::cout << planet->getName()<< mell << planet->getDia()<< mell << planet->getVikt() << std::endl;
	std::cout << planet2->getName() << mell << planet2->getDia() << mell << planet2->getVikt() << std::endl;
	planet2->addMåne(måne2);
	//std::cout << planet2->getName() << mell << planet2->getDia() << mell << planet2->getVikt() << mell << planet2->getMåne() << std::endl;

	std::cin;
	return 0;
}

