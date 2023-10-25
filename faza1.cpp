#include <iostream>
using namespace std;

class Recolta
{
public:
	const int numarSoiuri;
	static string calitateDeReferinta;
	string tipCultura;
	float cantitate;
	int numarZileRecoltare;
	int* orePeZi;

	Recolta() :numarSoiuri(2) {
		this->tipCultura = "-";
		this->cantitate = 0;
		this->numarZileRecoltare = 0;
		this->orePeZi = NULL;
	}

	Recolta(string tipCultura, float cantitate) :numarSoiuri(1) {
		this->tipCultura = tipCultura;
		this->cantitate = cantitate;
		this->numarZileRecoltare = 0;
		this->orePeZi = NULL;
	}

	Recolta(string tipCultura, float cantitate, int numarZileRecoltare, int* orePeZi) :numarSoiuri(3) {
		this->tipCultura = tipCultura;
		this->cantitate = cantitate;
		this->numarZileRecoltare = numarZileRecoltare;
		this->orePeZi = new int[numarZileRecoltare];
		for (int i = 0; i < numarZileRecoltare; i++) {
			this->orePeZi[i] = orePeZi[i];
		}
	}

	~Recolta() {
		if (this->orePeZi != NULL) {
			delete[]this->orePeZi;
		}
	}

	void afisareRecolta() {
		cout << "Din cultura de tip " << tipCultura << " ,avand  " << numarSoiuri  << " soiuri si avand calitatea de referinta " << calitateDeReferinta << " , a fost recoltata intr-o cantitate de " << cantitate << " kg pe parcursul a " << numarZileRecoltare << " zile. Numarul de ore in care s-a recoltat in toate zilele a fost: " << endl;
		if (numarZileRecoltare == 0)
			cout << "-";
		else
			for (int i = 0; i < numarZileRecoltare; i++)
				cout << orePeZi[i] << " ";
		cout << endl;
	}

	static void setCalitateDeReferinta(string calitateDeReferinta) {
		Recolta::calitateDeReferinta = calitateDeReferinta;
	}
};

string Recolta::calitateDeReferinta = "superioara";

class Livada
{
public:
	const int anPlantatie;
	static string scopLivada;
	string tipFructe;
	float suprafataLivada;
	float randamentAnual;
	int numarPomi;
	int* vechimePomi;

	Livada() :anPlantatie(2015) {
		this->tipFructe = "-";
		this->suprafataLivada = 0;
		this->randamentAnual = 0;
		this->numarPomi = 0;
		this->vechimePomi = NULL;
	}

	Livada(string tipFructe, float randamentAnual) :anPlantatie(2018) {
		this->tipFructe = tipFructe;
		this->suprafataLivada = 0;
		this->randamentAnual = randamentAnual;
		this->numarPomi = 0;
		this->vechimePomi = NULL;
	}

	Livada(string tipFructe, float suprafataLivada, float randamentAnual, int numarPomi, int* vechimePomi) :anPlantatie(2011) {
		this->tipFructe = tipFructe;
		this->suprafataLivada = suprafataLivada;
		this->randamentAnual = randamentAnual;
		this->numarPomi = numarPomi;
		this->vechimePomi = new int[numarPomi];
		for (int i = 0; i < numarPomi; i++) {
			this->vechimePomi[i] = vechimePomi[i];
		}
	}

	~Livada() {
		if (this->vechimePomi != NULL); {
			delete[]this->vechimePomi;
		}
	}

	void afisareLivada() {
		cout << "Livada plantata in anul " << anPlantatie << " pentru " << scopLivada << " contine " << tipFructe << " , se intinde pe o suprafata de " << suprafataLivada << " m patrati, are randamentul anul de " << randamentAnual << " kg si are un numar de " << numarPomi << " pomi. Urmatorii ani reprezinta vechimea fiecarui pom: " << endl;
		if (numarPomi == 0)
			cout << "-";
		else
			for (int i = 0; i < numarPomi; i++)
				cout << vechimePomi[i] << " ";
		cout << endl;
	}

	static void setScopLivada(string scopLivada) {
		Livada::scopLivada = scopLivada;
	}
};

string Livada::scopLivada = "consum";

class Sol {
public:
	const int anPrimaCultura;
	static float phOptim;
	string tipSol;
	string fertilitate;
	float suprafataCultivata;
	int numarCulturi;
	string* tipCulturi;
	
	Sol() : anPrimaCultura(2023) {
		this->tipSol = "-";
		this->fertilitate = "-";
		this->suprafataCultivata = 0;
		this->numarCulturi = 0;
		this->tipCulturi = NULL;
	}

	Sol(string tipSol, string fertilitate, float suprafataCultivata) : anPrimaCultura(2010) {
		this->tipSol = tipSol;
		this->fertilitate = fertilitate;
		this->suprafataCultivata = suprafataCultivata;
		this->numarCulturi = 0;
		this->tipCulturi = NULL;
	}

	Sol(string tipSol, string fertilitate, float suprafataCultivata, int numarCulturi, string* tipCulturi) : anPrimaCultura(2005) {
		this->tipSol = tipSol;
		this->fertilitate = fertilitate;
		this->suprafataCultivata = suprafataCultivata;
		this->numarCulturi = numarCulturi;
		this->tipCulturi = new string[numarCulturi];
		for (int i = 0; i < numarCulturi; i++) {
			this->tipCulturi[i] = tipCulturi[i];
		}
	}

	~Sol() {
		if (this->tipCulturi != NULL) {
			delete[]this->tipCulturi;
		}
	}

	void afisareSol() {
		cout << "Solul ce a avut prima cultura in anul " << anPrimaCultura << " avand ph-ul optim de " << phOptim << " este un sol " << tipSol << " cu o fertilitate " << fertilitate << " si o suprafata cultivata de " << suprafataCultivata << " m patrati si " << numarCulturi << " culturi precedente. Culturile au fost de: " << endl;
		if (numarCulturi == 0)
			cout << "-";
		else
			for (int i = 0; i < numarCulturi; i++)
				cout << this->tipCulturi[i] << " ";
		cout << endl;
	}

	static void setPhOptim(float phOptim) {
		Sol::phOptim = phOptim;
	}
};

float Sol::phOptim = 6.8;


void main() {
	Recolta recolta1;
	recolta1.afisareRecolta();

	int* orePeZi = new int[3];
	orePeZi[0] = 7;
	orePeZi[1] = 3;
	orePeZi[2] = 5;

	Recolta recolta2("ceapa", 150, 3, orePeZi);
	recolta2.afisareRecolta();

	Recolta recolta3("morcov", 80);
	recolta3.afisareRecolta();

	Recolta::setCalitateDeReferinta("superioara");
	recolta3.setCalitateDeReferinta("superioara");

	Livada livada1;
	livada1.afisareLivada();

	int* vechimePomi = new int[4];
	vechimePomi[0] = 12;
	vechimePomi[1] = 12;
	vechimePomi[2] = 11;
	vechimePomi[3] = 9;

	Livada livada2("meri", 15, 52, 4, vechimePomi);
	livada2.afisareLivada();

	Livada livada3("pruni", 24);
	livada3.afisareLivada();

	Sol::setPhOptim(6.7);


	Sol sol1;
	sol1.afisareSol();
	
	

	string* tipCulturi = new string[3];
	tipCulturi[0] = "varza";
	tipCulturi[1] = "mazare";
	tipCulturi[2] = "fasole";

	Sol sol2("argilos", "medie", 20, 3, tipCulturi);
	sol2.afisareSol();

	Sol sol3("calcaros", "crescuta", 25);
	sol3.afisareSol();

	
}