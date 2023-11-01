#include <iostream>
using namespace std;

class Recolta
{
private:
	const int numarSoiuri;
	static string calitateDeReferinta;
	string tipCultura;
	float cantitate;
	int numarZileRecoltare;
	int* orePeZi;
public:

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

	Recolta(const Recolta& r) : numarSoiuri(r.numarSoiuri) {
		this->tipCultura = r.tipCultura;
		this->cantitate = r.cantitate;
		this->numarZileRecoltare = r.numarZileRecoltare;
		this->orePeZi = new int[numarZileRecoltare];
		for (int i = 0; i < numarZileRecoltare; i++) {
			this->orePeZi[i] = r.orePeZi[i];
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

	static string getCalitateDeReferinta() {
		return Recolta::calitateDeReferinta;
	}

	int getNrSoiuri() {
		return this->numarSoiuri;
	}

	void setTipCultura(string tipCultura) {
		if (tipCultura.length() > 0)
			this->tipCultura = tipCultura;
	}

	string getTipCultura() {
		return this->tipCultura;
	}

	void setCantitate(float cantitate) {
		if (cantitate != 0) {
			this->cantitate = cantitate;
		}
	}

	float getCantitate() {
		return this->cantitate;
	}
	
	void setNrZileRecoltare(int numarZileRecoltare, int* ore) {
		if (numarZileRecoltare > 0) {
			this->numarZileRecoltare = numarZileRecoltare;
			if (this->orePeZi != NULL) {
				delete[]orePeZi;
			}
			orePeZi = new int[this->numarZileRecoltare];
			for (int i = 0; i < numarZileRecoltare; i++) {
				this->orePeZi[i] = ore[i];
			}
		}
	}

	int getOrePeZi(int index) {
		if (index >= 0 && index <= numarZileRecoltare) {
			return this->orePeZi[index];
		}
	}
};

string Recolta::calitateDeReferinta = "superioara";

class Livada
{
private:
	const int anPlantatie;
	static string scopLivada;
	string tipFructe;
	float randamentAnual;
	int numarPomi;
	int* vechimePomi;
public:

	Livada() :anPlantatie(2015) {
		this->tipFructe = "-";
		this->randamentAnual = 0;
		this->numarPomi = 0;
		this->vechimePomi = NULL;
	}

	Livada(string tipFructe, float randamentAnual) :anPlantatie(2018) {
		this->tipFructe = tipFructe;
		this->randamentAnual = randamentAnual;
		this->numarPomi = 0;
		this->vechimePomi = NULL;
	}

	Livada(string tipFructe, float randamentAnual, int numarPomi, int* vechimePomi) :anPlantatie(2011) {
		this->tipFructe = tipFructe;
		this->randamentAnual = randamentAnual;
		this->numarPomi = numarPomi;
		this->vechimePomi = new int[numarPomi];
		for (int i = 0; i < numarPomi; i++) {
			this->vechimePomi[i] = vechimePomi[i];
		}
	}

	Livada(const Livada& l) : anPlantatie(l.anPlantatie) {
		this->tipFructe = l.tipFructe;
		this->randamentAnual = l.randamentAnual;
		this->numarPomi = l.numarPomi;
		this->vechimePomi = new int[numarPomi];
		for (int i = 0; i < numarPomi; i++) {
			this->vechimePomi[i] = l.vechimePomi[i];
		}
	}

	~Livada() {
		if (this->vechimePomi != NULL) {
			delete[]this->vechimePomi;
		}
	}

	void afisareLivada() {
		cout << "Livada plantata in anul " << anPlantatie << " pentru " << scopLivada << " contine " << tipFructe << " , are randamentul anul de " << randamentAnual << " kg si are un numar de " << numarPomi << " pomi. Urmatorii ani reprezinta vechimea fiecarui pom: " << endl;
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

	static string getScopLivada() {
		return Livada::scopLivada;
	}

	int getAnPlantatie() {
		return this->anPlantatie;
	}

	void setTipFructe(string tipFructe) {
		if (tipFructe.length() > 0)
			this->tipFructe = tipFructe;
	}

	string getTipFructe() {
		return this->tipFructe;
	}
	
	void setRandamentAnual(float randamentAnual) {
		if (randamentAnual > 2) {
			this->randamentAnual = randamentAnual;
		}
	}

	float getRandamentAnual() {
		return this->randamentAnual;
	}

	void setNrPomi(int numarPomi, int* vechime) {
		if (numarPomi > 0) {
			this->numarPomi = numarPomi;
			if (this->vechimePomi != NULL) {
				delete[]vechimePomi;
			}
			vechimePomi = new int[this->numarPomi];
			for (int i = 0; i < numarPomi; i++) {
				this->vechimePomi[i] = vechime[i];
			}
		}
	}

	int getVechimePomi(int index) {
		if (index >= 0 && index <= numarPomi) {
			return this->vechimePomi[index];
		}
	}

}; 

string Livada::scopLivada = "consum";

class Sol {
private:
	const int anPrimaCultura;
	static float phOptim;
	string tipSol;
	string fertilitate;
	float suprafataCultivata;
	int numarCulturi;
	string* tipCulturi;
public:
	
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

	Sol(const Sol& s) : anPrimaCultura(s.anPrimaCultura) {
		this->tipSol = s.tipSol;
		this->fertilitate = s.fertilitate;
		this->suprafataCultivata = s.suprafataCultivata;
		this->numarCulturi = s.numarCulturi;
		this->tipCulturi = new string[numarCulturi];
		for (int i = 0; i < numarCulturi; i++) {
			this->tipCulturi[i] = s.tipCulturi[i];
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

	static float getPhOptim() {
		return Sol::phOptim;
	}

	int getAnPrimaCultura() {
		return this->anPrimaCultura;
	}

	void setTipSol(string tipSol) {
		if (tipSol.length() > 0) {
			this->tipSol = tipSol;
		}
	}

	string getTipSol() {
		return this->tipSol;
	}

	void setFertilitate(string fertilitate) {
		if (fertilitate.length() > 0) {
			this->fertilitate = fertilitate;
		}
	}

	string getFertilitate() {
		return this->fertilitate;
	}

	void setSuprafataCultivata(float suprafataCultivata) {
		if (suprafataCultivata != 0) {
			this->suprafataCultivata = suprafataCultivata;
		}
	}

	float getSuprafataCultivata() {
		return this->suprafataCultivata;
	}

	void setNrCulturi(int numarCulturi, string* culturi) {
		if (numarCulturi > 0) {
			this->numarCulturi = numarCulturi;
		}
		if (tipCulturi != NULL) {
			delete[]tipCulturi;
		}
		tipCulturi = new string[this->numarCulturi];
		for (int i = 0; i < numarCulturi; i++) {
			this->tipCulturi[i] = culturi[i];
		}
	}

	string getTipCulturi(int index) {
		if (index >= 0 && index <= numarCulturi) {
			return this->tipCulturi[index];
		}
	}

};

float Sol::phOptim = 6.8;


void main() {
	Recolta::setCalitateDeReferinta("buna");

	Recolta recolta1;
	recolta1.afisareRecolta();

	int* orePeZi = new int[3];
	orePeZi[0] = 7;
	orePeZi[1] = 3;
	orePeZi[2] = 5;

	Recolta recolta2("ceapa", 150, 3, orePeZi);
	recolta2.afisareRecolta();

	Recolta recolta3("morcov", 80);
	recolta3.setCalitateDeReferinta("superioara");
	recolta3.afisareRecolta();

	Recolta::setCalitateDeReferinta("buna");

	Recolta recolta4(recolta2);
	recolta4.afisareRecolta();

	cout << endl << recolta4.getCalitateDeReferinta() << endl;

	cout << endl << recolta1.getNrSoiuri() << endl;

	recolta4.setTipCultura("cartof");
	cout << endl << recolta4.getTipCultura() << endl;

	recolta4.setCantitate(176.7);
	cout << endl << recolta4.getCantitate() << endl;

	int* vectorRecolta = new int [4] {6, 3, 4, 2};

	recolta4.setNrZileRecoltare(4, vectorRecolta);
	recolta4.afisareRecolta();

	delete[]vectorRecolta;

	cout << endl << recolta4.getOrePeZi(1) << endl;



	Livada::setScopLivada("alimentatie");
	Livada livada1;
	livada1.setScopLivada("consumatie");
	livada1.afisareLivada();

	Livada::setScopLivada("alimentatie");

	int* vechimePomi = new int[4];
	vechimePomi[0] = 12;
	vechimePomi[1] = 12;
	vechimePomi[2] = 11;
	vechimePomi[3] = 9;

	Livada livada2("meri", 52, 4, vechimePomi);                    
	livada2.afisareLivada();

	Livada livada3("pruni", 24);
	livada3.afisareLivada();

	Livada livada4(livada2);
	livada4.afisareLivada();

	cout << endl << livada4.getScopLivada() << endl;

	cout << endl << livada1.getAnPlantatie() << endl;

	livada4.setTipFructe("peri");
	cout << endl << livada4.getTipFructe() << endl;

	livada4.setRandamentAnual(56.4);
	cout << endl << livada4.getRandamentAnual() << endl;

	int* vectorLivada = new int[3] {11, 10, 12};

	livada4.setNrPomi(3, vectorLivada);
	livada4.afisareLivada();

	delete[]vectorLivada;

	cout << endl << livada4.getVechimePomi(0) << endl;

    

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

	Sol sol4(sol2);
	sol4.afisareSol();

	cout << endl << sol4.getPhOptim() << endl;

	cout << endl << sol1.getAnPrimaCultura() << endl;

	sol4.setTipSol("negru");
	cout << endl << sol4.getTipSol() << endl;
	
	sol4.setFertilitate("foarte crescuta");
	cout << endl << sol4.getFertilitate() << endl;

	sol4.setSuprafataCultivata(22.3);
	cout << endl << sol4.getSuprafataCultivata() << endl;

	string* vectorSol = new string[2]{ "morcov", "ceapa" };
	sol4.setNrCulturi(2, vectorSol);
	sol4.afisareSol();

	delete[]vectorSol;

	cout << endl << sol4.getTipCulturi(1) << endl;

}
