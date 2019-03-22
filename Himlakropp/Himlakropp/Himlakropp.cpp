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


class M�ne : public Himlakropp {

private:
	int kratrar;
public:
	int getVikt() const {
		int v = (10 * getDia()) - kratrar;
		return v;
	}
	
	
	static M�ne * create(std::string n, int d, int k);


protected:
	M�ne(std::string n, int d, int k):Himlakropp(n,d), kratrar(k) {}

};

M�ne*  M�ne::create(std::string n, int d, int k){
	return new M�ne(n, d,k);
}


class Planet :public Himlakropp {
private:
	bool atmo;
	M�ne * m�ne;
public:
	static Planet * create(std::string n, int d, bool a);
	static Planet * create(std::string n, int d, bool a, M�ne* m�ne);

	int getVikt() const {
		int vp = (10 * getDia());
		if (atmo) {
			vp *= 2; 
		}
		if (m�ne) {
			vp += m�ne->getVikt();
		}
		return vp;
	}


	void  addM�ne(M�ne * m) {
		if (m�ne) {
			delete m�ne;
			m�ne = m;
		}
	}

	//std::string getM�ne() const { return m�ne->getName; }


protected:
	Planet(std::string n, int d, bool a) : Himlakropp(n, d), atmo(a) {}
	Planet(std::string n, int d, bool a, M�ne * m) : Himlakropp(n, d), atmo(a),  m�ne(m) {
		if (m�ne) {
			m�ne = m;
		}
	}

};

Planet * Planet::create(std::string n, int d, bool a) {
	return new Planet(n, d, a);
}
Planet * Planet::create(std::string n, int d, bool a, M�ne* m) {
	return new Planet(n, d, a, m);
}


class Stj�rna : public Himlakropp {

private:
	int ljus;
	std::vector<Himlakropp*> system;

public:
	static Stj�rna* create(std::string n, int d, int s);

	int getLjus() { return ljus; }

	void addHimla(Himlakropp* ny) { system.push_back(ny); }
	int getVikt() const;


protected:

	Stj�rna(std::string n, int d, int s) : Himlakropp(n, d), ljus(s) {}
	// initiera vector f�r himlakroppar
};

int Stj�rna::getVikt()const {
	int v = ljus * getDia();
	for (int i = 0; i < system.size(); i++) {
		v += system[i]->getVikt();
		if (Stj�rna* stj�rna = dynamic_cast<Stj�rna*>(system[i])) {
			v += stj�rna->getLjus();
		}
	}

	return v;
}
Stj�rna * Stj�rna::create(std::string n, int d, int s) {
	return new Stj�rna(n, d, s);
}

int main() {
	std::string mell = ", ";

	//Himlakropp * m�ne;
	M�ne *m�ne = M�ne::create("dumbo", 1000, 50);
	M�ne *m�ne2 = M�ne::create("bimbo", 100, 50);

	Planet *planet = Planet::create("jorden", 5000, true);
	Planet *planet2 = Planet::create("jorden2", 5000, false, m�ne );
	
	Stj�rna * stj�rna1 = Stj�rna::create("solen", 1000000, 5);
	std::cout << stj�rna1->getName() << mell << stj�rna1->getDia() << mell << stj�rna1->getVikt() << mell << stj�rna1->getLjus() << mell << std::endl;

	stj�rna1->addHimla(planet2);
	stj�rna1->addHimla(m�ne);


	std::cout << stj�rna1->getName() << mell << stj�rna1->getDia() << mell << stj�rna1->getVikt() << mell << stj�rna1->getLjus() << mell << std::endl;

	std::cout << m�ne->getName() << mell << m�ne->getDia() << mell << m�ne->getVikt() << std::endl;
	std::cout << m�ne2->getName() << mell << m�ne2->getDia() << mell << m�ne2->getVikt() << std::endl;

	std::cout << planet->getName()<< mell << planet->getDia()<< mell << planet->getVikt() << std::endl;
	std::cout << planet2->getName() << mell << planet2->getDia() << mell << planet2->getVikt() << std::endl;
	planet2->addM�ne(m�ne2);
	//std::cout << planet2->getName() << mell << planet2->getDia() << mell << planet2->getVikt() << mell << planet2->getM�ne() << std::endl;

	std::cin;
	return 0;
}

