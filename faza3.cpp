
#include <iostream>
#include<fstream>
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

	Recolta() :numarSoiuri(1) {
		this->tipCultura = "-";
		this->cantitate = 0;
		this->numarZileRecoltare = 0;
		this->orePeZi = NULL;
	}

	Recolta(string tipCultura, float cantitate) :numarSoiuri(2) {
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

	Recolta& operator=(const Recolta& r) {
		if (this != &r) {
			if (this->orePeZi != NULL) {
			delete[]this->orePeZi;
		    }
			this->tipCultura = r.tipCultura;
			this->cantitate = r.cantitate;
			this->numarZileRecoltare = r.numarZileRecoltare;
			this->orePeZi = new int[numarZileRecoltare];
			for (int i = 0; i < numarZileRecoltare; i++) {
				this->orePeZi[i] = r.orePeZi[i];
			}
		}
			return *this;
	}

	~Recolta() {
		if (this->orePeZi != NULL) {
			delete[]this->orePeZi;
		}
	}

	Recolta operator+(const Recolta& r) {
		Recolta aux = *this;
		aux.tipCultura = this->tipCultura;
		aux.cantitate = this->cantitate + r.cantitate;
		aux.numarZileRecoltare = this->numarZileRecoltare + r.numarZileRecoltare;
		if (aux.orePeZi != NULL) {
			delete[]aux.orePeZi;
		}
		aux.orePeZi = new int[aux.numarZileRecoltare];
		for (int i = 0; i < this->numarZileRecoltare; i++) {
			aux.orePeZi[i] = this->orePeZi[i];
		}
		for (int j = this->numarZileRecoltare; j < aux.numarZileRecoltare; j++) {
			aux.orePeZi[j] = r.orePeZi[j - this->numarZileRecoltare];
		}
		return aux;
	}

	Recolta operator+=(const Recolta& r) {
		this->cantitate += r.cantitate;
		int auxNumarZileRecoltare = this->numarZileRecoltare + r.numarZileRecoltare;
		int* auxOrePeZi = new int[auxNumarZileRecoltare];
		for (int i = 0; i < this->numarZileRecoltare; i++) {
			auxOrePeZi[i] = this->orePeZi[i];
		}
		for (int j = this->numarZileRecoltare; j < auxNumarZileRecoltare; j++) {
			auxOrePeZi[j] = r.orePeZi[j - this->numarZileRecoltare];
		}
		this->numarZileRecoltare = auxNumarZileRecoltare;
		if (this->orePeZi != NULL) {
			delete[]this->orePeZi;
		}
		this->orePeZi = auxOrePeZi;
		return *this;
	}

	bool operator>(const Recolta& r) {
		return this->cantitate > r.cantitate;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->numarZileRecoltare) {
			return this->orePeZi[index];
		}
	}

	Recolta operator++(int) {
		Recolta recoltaInitiala = *this;
		this->cantitate += 12;
		return recoltaInitiala;
	}

	void afisareRecolta() {
		cout << endl << "Din cultura de tip " << tipCultura << " ,avand  " << numarSoiuri << " soiuri si avand calitatea de referinta " << calitateDeReferinta << " , a fost recoltata intr-o cantitate de " << cantitate << " kg pe parcursul a " << numarZileRecoltare << " zile. Numarul de ore in care s-a recoltat in fiecare zi a fost: " << endl;
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
		if (tipCultura.length() > 0) {
			this->tipCultura = tipCultura;
		}
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
			this->orePeZi = new int[numarZileRecoltare];
			for (int i = 0; i < numarZileRecoltare; i++) {
				this->orePeZi[i] = ore[i];
			}
		}
	}

	int getNrZileRecoltare() {
		return this->numarZileRecoltare;
	}

	int* getOrePeZi() {
		return this->orePeZi;
	}

	friend float getTimpMediuPeZi(const Recolta& recolta);

	friend ostream& operator<<(ostream& out, const Recolta& recolta);

	friend istream& operator>>(istream& in, Recolta& recolta);

	void scriereBinRecolta(fstream& f) {
		int lungimeTipCultura = tipCultura.length();
		f.write((char*)&lungimeTipCultura, sizeof(int));
		f.write(tipCultura.c_str(), lungimeTipCultura + 1);
		f.write((char*)&this->cantitate, sizeof(float));
		f.write((char*)&this->numarZileRecoltare, sizeof(int));
		for (int i = 0; i < numarZileRecoltare; i++) {
			f.write((char*)&this->orePeZi[i], sizeof(int));
	}
	}

	void citireBinRecolta(fstream& f) {
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		char* bufferTipCultura = new char[lungime + 1];
		f.read(bufferTipCultura, lungime + 1);
		this->tipCultura = bufferTipCultura;
		delete[] bufferTipCultura;
		f.read((char*)&this->cantitate, sizeof(float));
		f.read((char*)&this->numarZileRecoltare, sizeof(int));
		if (this->orePeZi != NULL) {
			delete[] this->orePeZi;
		}
		this->orePeZi = new int[numarZileRecoltare];
		for (int i = 0; i < numarZileRecoltare; i++) {
			f.read((char*)&this->orePeZi[i], sizeof(int));
		}
	}
	
};

string Recolta::calitateDeReferinta = "superioara";

float getTimpMediuPeZi(const Recolta& recolta) {
	int suma = 0;
	if (recolta.numarZileRecoltare == 0)
		return 0;
	for (int i = 0; i < recolta.numarZileRecoltare; i++)
		suma += recolta.orePeZi[i];
	return suma / (float)recolta.numarZileRecoltare;
}

ostream& operator<<(ostream& out, const Recolta& recolta) {
	out << endl << "Din cultura de tip " << recolta.tipCultura << " ,avand  " << recolta.numarSoiuri << " soiuri si avand calitatea de referinta " << recolta.calitateDeReferinta << " , a fost recoltata intr-o cantitate de " << recolta.cantitate << " kg pe parcursul a " << recolta.numarZileRecoltare << " zile. Numarul de ore in care s-a recoltat in fiecare zi a fost: " << endl;

	if (recolta.numarZileRecoltare == 0)
		out << "-";
	else
		for (int i = 0; i < recolta.numarZileRecoltare; i++)
			out << recolta.orePeZi[i] << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& in, Recolta& recolta) {
	cout << "Tip cultura: ";
	in >> recolta.tipCultura;
	cout << "Cantitate: ";
	in >> recolta.cantitate;
	cout << "Numar de zile in care se recolteaza: ";
	in >> recolta.numarZileRecoltare;
	if (recolta.orePeZi != NULL)
	{
		delete[]recolta.orePeZi;
	}
	recolta.orePeZi = new int[recolta.numarZileRecoltare];
	for (int i = 0; i < recolta.numarZileRecoltare; i++)
	{
		cout << "Orele de recoltare in ziua " << i + 1 << ": ";
		in >> recolta.orePeZi[i];

	}
	return in;
}

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

	Livada() :anPlantatie(2020) {
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

	Livada& operator=(const Livada& l) {
		if (this != &l) {
			if (this->vechimePomi != NULL)
				delete[]this->vechimePomi;
			this->tipFructe = l.tipFructe;
			this->randamentAnual = l.randamentAnual;
			this->numarPomi = l.numarPomi;
			this->vechimePomi = new int[numarPomi];
			for (int i = 0; i < numarPomi; i++) {
				this->vechimePomi[i] = l.vechimePomi[i];
			}
		}
		return *this;
	}

	~Livada() {
		if (this->vechimePomi != NULL) {
			delete[]this->vechimePomi;
		}
	}

	Livada operator+(const Livada& l) {
		Livada aux = *this;
		aux.tipFructe = this->tipFructe;
		aux.randamentAnual = this->randamentAnual + l.randamentAnual;
		aux.numarPomi = this->numarPomi + l.numarPomi;
		if (aux.vechimePomi != NULL) {
			delete[]aux.vechimePomi;
		}
		aux.vechimePomi = new int[aux.numarPomi];
		for (int i = 0; i < this->numarPomi; i++) {
			aux.vechimePomi[i] = this->vechimePomi[i];
		}
		for (int j = this->numarPomi; j < aux.numarPomi; j++) {
			aux.vechimePomi[j] = l.vechimePomi[j - this->numarPomi];
		}
		return aux;
	}

	Livada operator+=(const Livada& l) {
		this->randamentAnual += l.randamentAnual;
		int auxNumarPomi = this->numarPomi + l.numarPomi;
		int* auxVechimePomi = new int[auxNumarPomi];
		for (int i = 0; i < this->numarPomi; i++) {
			auxVechimePomi[i] = this->vechimePomi[i];
		}
		for (int j = this->numarPomi; j < auxNumarPomi; j++) {
			auxVechimePomi[j] = l.vechimePomi[j - this->numarPomi];
		}
		this->numarPomi = auxNumarPomi;
		if (this->vechimePomi != NULL) {
			delete[]this->vechimePomi;
		}
		this->vechimePomi = auxVechimePomi;
		return *this;
	}

	bool operator==(const Livada& l) {
		return this->randamentAnual == l.randamentAnual && this->numarPomi == l.numarPomi;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->numarPomi) {
			return this->vechimePomi[index];
		}
	}
	float operator()(int start, int stop) {
		if (start >= 0 && start <= this->numarPomi && stop >= 0 && stop <= numarPomi && start < stop) {
			int suma = 0;
			for (int i = start;i <= stop;i++) {
				suma += this->vechimePomi[i];
			}
			return suma/(float)stop;
		}
	}

	void afisareLivada() {
		cout << endl << "Livada plantata in anul " << anPlantatie << " pentru " << scopLivada << " contine " << tipFructe << " , are randamentul anul de " << randamentAnual << " kg si are un numar de " << numarPomi << " pomi. Urmatorii ani reprezinta vechimea fiecarui pom: " << endl;
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
		if (tipFructe.length() > 0) {
			this->tipFructe = tipFructe;
		}
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
			this->vechimePomi = new int[numarPomi];
			for (int i = 0; i <  numarPomi; i++) {
				this->vechimePomi[i] = vechime[i];
			}
		}
	}

	int getNrPomi() {
		return this->numarPomi;
	}

	int* getVechimePomi() {
			return this->vechimePomi;
	}
	
	friend ostream& operator<<(ostream& out, const Livada& livada);
	friend istream& operator>>(istream& in, Livada& livada);

	void scriereBinLivada(fstream& f)
	{
		int lungimeTipFructe = tipFructe.length();
		f.write((char*)&lungimeTipFructe, sizeof(int));
		f.write(tipFructe.c_str(), lungimeTipFructe + 1);
		f.write((char*)&this->randamentAnual, sizeof(float));
		f.write((char*)&this->numarPomi, sizeof(int));
		for (int i = 0; i < numarPomi; i++) {
			f.write((char*)&this->vechimePomi[i], sizeof(int));
		}
	}

	void citireBinLivada(fstream& f) {
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		char* bufferTipFructe = new char[lungime + 1];
		f.read(bufferTipFructe, lungime + 1);
		this->tipFructe = bufferTipFructe;
		delete[] bufferTipFructe;
		f.read((char*)&this->randamentAnual, sizeof(float));
		f.read((char*)&this->numarPomi, sizeof(int));
		if (this->vechimePomi != NULL) {
			delete[] this->vechimePomi;
		}
		this->vechimePomi = new int[numarPomi];
		for (int i = 0; i < numarPomi; i++) {
			f.read((char*)&this->vechimePomi[i], sizeof(int));
		}
	}
};

string Livada::scopLivada = "consum";

ostream& operator<<(ostream& out, const Livada& livada) {
	out << endl << "Livada plantata in anul " << livada.anPlantatie << " pentru " << livada.scopLivada << " contine " << livada.tipFructe << " , are randamentul anul de " << livada.randamentAnual << " kg si are un numar de " << livada.numarPomi << " pomi. Urmatorii ani reprezinta vechimea fiecarui pom: " << endl;
	if (livada.numarPomi == 0)
		out << "-";
	else
		for (int i = 0; i < livada.numarPomi; i++)
			out << livada.vechimePomi[i] << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& in, Livada& livada) {
	cout << "Tip fructe: ";
	in >> livada.tipFructe;
	cout << "Randament anual: ";
	in >> livada.randamentAnual;
	cout << "Numar de pomi: ";
	in >> livada.numarPomi;
	if (livada.vechimePomi != NULL)
	{
		delete[]livada.vechimePomi;
	}
	livada.vechimePomi = new int[livada.numarPomi];
	for (int i = 0; i < livada.numarPomi; i++)
	{
		cout << "Vechimea pomului " << i + 1 << ": ";
		in >> livada.vechimePomi[i];

	}
	return in;
}

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

	Sol() : anPrimaCultura(2020) {
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

	Sol& operator=(const Sol& s) {
		if (this != &s) {
			if (this->tipCulturi != NULL)
				delete[]this->tipCulturi;
			this->tipSol = s.tipSol;
			this->fertilitate = s.fertilitate;
			this->suprafataCultivata = s.suprafataCultivata;
			this->numarCulturi = s.numarCulturi;
			this->tipCulturi = new string[numarCulturi];
			for (int i = 0; i < numarCulturi; i++) {
				this->tipCulturi[i] = s.tipCulturi[i];
			}
		}
		return *this;
	}

	~Sol() {
		if (this->tipCulturi != NULL) {
			delete[]this->tipCulturi;
		}
	}

	Sol operator+(const Sol& s) {
		Sol aux = *this;
		aux.tipSol = this->tipSol;
		aux.fertilitate = this->fertilitate;
		aux.suprafataCultivata = this->suprafataCultivata + s.suprafataCultivata;
		aux.numarCulturi = this->numarCulturi + s.numarCulturi;
		if (aux.tipCulturi != NULL) {
			delete[]aux.tipCulturi;
		}
		aux.tipCulturi = new string[aux.numarCulturi];
		for (int i = 0; i < this->numarCulturi; i++) {
			aux.tipCulturi[i] = this->tipCulturi[i];
		}
		for (int j = this->numarCulturi; j < aux.numarCulturi; j++) {
			aux.tipCulturi[j] = s.tipCulturi[j - this->numarCulturi];
		}
		return aux;
	}

	Sol operator+=(const Sol& s) {
		this->suprafataCultivata += s.suprafataCultivata;
		int auxNumarCulturi = this->numarCulturi + s.numarCulturi;
		string* auxTipCulturi = new string[auxNumarCulturi];
		for (int i = 0; i < this->numarCulturi; i++) {
			auxTipCulturi[i] = this->tipCulturi[i];
		}
		for (int j = this->numarCulturi; j < auxNumarCulturi; j++) {
			auxTipCulturi[j] = s.tipCulturi[j - this->numarCulturi];
		}
		this->numarCulturi = auxNumarCulturi;
		if (this->tipCulturi != NULL) {
			delete[]this->tipCulturi;
		}
		this->tipCulturi = auxTipCulturi;
		return *this;
	}

	bool operator!=(const Sol& s) {
		return this->fertilitate != s.fertilitate;
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->numarCulturi) {
			return this->tipCulturi[index];
		}
	}

    explicit operator int() {
		return this->numarCulturi;
	}

	void afisareSol() {
		cout << endl << "Solul ce a avut prima cultura in anul " << anPrimaCultura << " avand ph-ul optim de " << phOptim << " este un sol " << tipSol << " cu o fertilitate " << fertilitate << " si o suprafata cultivata de " << suprafataCultivata << " m patrati si " << numarCulturi << " culturi precedente. Culturile au fost de: " << endl;
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
		if (this->tipCulturi != NULL) {
			delete[]tipCulturi;
		}
		this->tipCulturi = new string[numarCulturi];
		for (int i = 0; i < numarCulturi; i++) {
			this->tipCulturi[i] = culturi[i];
		}
	}

	int getNrCulturi() {
		return this->numarCulturi;
	}

	string getTipCulturi(int index) {
		if (index >= 0 && index <= numarCulturi) {
			return this->tipCulturi[index];
		}
	}

	Sol operator+(float suprafataCultivata) {
		Sol aux = *this;
			aux.suprafataCultivata = this->suprafataCultivata + suprafataCultivata;
		return aux;
	}

	friend Sol operator+(float, Sol);

	friend ostream& operator<<(ostream& out, const Sol& sol);
	friend istream& operator >>(istream& in, Sol& sol);

	friend ofstream& operator<<(ofstream& out, const Sol& sol) {
		out << sol.tipSol << endl << sol.fertilitate << endl << sol.suprafataCultivata << endl << sol.numarCulturi << endl;
		for (int i = 0; i < sol.numarCulturi; i++)
			out << sol.tipCulturi[i] << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Sol& sol) {
		in >> sol.tipSol;
		in >> sol.fertilitate;
		in >> sol.suprafataCultivata;
		in >> sol.numarCulturi;
		if (sol.tipCulturi != NULL)
			delete[]sol.tipCulturi;
		sol.tipCulturi = new string[sol.numarCulturi];
		for (int i = 0; i < sol.numarCulturi; i++)
			in >> sol.tipCulturi[i];
		return in;
	}

};

float Sol::phOptim = 6.8;

Sol operator+(float suprafataCultivata, Sol sol) {
	Sol aux = sol;
	aux.suprafataCultivata = sol.suprafataCultivata + suprafataCultivata;
	return aux;
}

ostream& operator<<(ostream& out, const Sol& sol) {
	out << endl << "Solul ce a avut prima cultura in anul " << sol.anPrimaCultura << " avand ph-ul optim de " << sol.phOptim << " este un sol " << sol.tipSol << " cu o fertilitate " << sol.fertilitate << " si o suprafata cultivata de " << sol.suprafataCultivata << " m patrati si " << sol.numarCulturi << " culturi precedente. Culturile au fost de: " << endl;

	if (sol.numarCulturi == 0)
		out << "-";
	else
		for (int i = 0; i < sol.numarCulturi; i++)
			out << sol.tipCulturi[i] << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& in, Sol& sol) {
	cout << endl << "Tip sol: ";
	in >> sol.tipSol;
	cout << "Fertilitate: ";
	in >> sol.fertilitate;
	cout << "Suprafata cultivata: ";
	in >> sol.suprafataCultivata;
	cout << "Numar culturi: ";
	in >> sol.numarCulturi;
	if (sol.tipCulturi != NULL) {
		delete[]sol.tipCulturi;
	}
	sol.tipCulturi = new string[sol.numarCulturi];
	for (int i = 0; i < sol.numarCulturi; i++) {
		cout << "Tipul culturii " << i + 1 << ": ";
		in >> sol.tipCulturi[i];
	}
	return in;
}

class Ferma {
private:
	const int id;
	bool sistemIrigatie;
	int numarRecolte;
	Recolta* recolte;
public:

	Ferma() : id(0) {
		this->sistemIrigatie = false;
		this->numarRecolte = 0;
		this->recolte = NULL;
	}

	Ferma(int id, bool sistemIrigatie, int numarRecolte, Recolta* recolte) :id(id) {
		this->sistemIrigatie = sistemIrigatie;
		this->numarRecolte = numarRecolte;
		this->recolte = new Recolta[numarRecolte];
		for (int i = 0; i < numarRecolte; i++) {
			this->recolte[i] = recolte[i];
		}
	}

	Ferma(const Ferma& f) : id(f.id) {
		this->sistemIrigatie = f.sistemIrigatie;
		this->numarRecolte = f.numarRecolte;
		this->recolte = new Recolta[numarRecolte];
		for (int i = 0; i < numarRecolte; i++) {
			this->recolte[i] = f.recolte[i];
		}
	}

	~Ferma() {
		if (this->recolte != NULL) {
			delete[]this->recolte;
		}
	}

	Ferma& operator=(const Ferma& f) {
		if (this != &f) {
			if (this->recolte != NULL) {
				delete[]this->recolte;
			}
			this->sistemIrigatie = f.sistemIrigatie;
			this->numarRecolte = f.numarRecolte;
			this->recolte = new Recolta[numarRecolte];
			for (int i = 0; i < numarRecolte; i++) {
				this->recolte[i] = f.recolte[i];
			}
		}
		return *this;
	}

	Ferma operator+(const Ferma& f) {
		Ferma aux = *this;
		aux.sistemIrigatie = this->sistemIrigatie;
		aux.numarRecolte = this->numarRecolte + f.numarRecolte;
		if (aux.recolte != NULL) {
			delete[]aux.recolte;
		}
		aux.recolte = new Recolta[aux.numarRecolte];
		for (int i = 0; i < this->numarRecolte; i++) {
			aux.recolte[i] = this->recolte[i];
		}
		for (int j = this->numarRecolte; j < aux.numarRecolte; j++) {
			aux.recolte[j] = f.recolte[j - this->numarRecolte];
		}
		return aux;
	}

	Recolta& operator[](int index) {
		if (index >= 0 && index < numarRecolte) {
			return this->recolte[index];
		}
	}

	Ferma operator!() {
		Ferma aux = *this;
		aux.sistemIrigatie = !aux.sistemIrigatie;
		return aux;
	}

	void afisareFerma() {
		cout << endl << "Ferma cu id-ul " << id << (sistemIrigatie ? " are sistem de irigatie mecanizat " : " nu are sistem de irigatie mecanizat ") << "si are un numar de " << numarRecolte << " recolte. Recoltele sunt: " << endl;
		if (numarRecolte == 0) 
			cout << "-";
		else
			for (int i = 0; i < numarRecolte; i++)
				cout << recolte[i];
		cout << endl;
	}

	int getId() {
		return this->id;
	}

	void setSistemIrigatie(bool sistemIrigatie) {
		this->sistemIrigatie = sistemIrigatie;
	}

	bool getSistemIrigatie() {
		return this->sistemIrigatie;
	}

	void setNrRecolte(int numarRecolte, Recolta* recolte) {
		if (numarRecolte > 0) {
			this->numarRecolte = numarRecolte;
			if (this->recolte != NULL) {
				delete[]this->recolte;
			}
			this->recolte = new Recolta[numarRecolte];
			for (int i = 0; i < numarRecolte; i++) {
				this->recolte[i] = recolte[i];
			}
		}
	}

	int getNrRecolte() {
		return this->numarRecolte;
	}

	Recolta* getRecolte() {
		return this->recolte;
	}

	friend ostream& operator<<(ostream& out, const Ferma& ferma) {
		out << endl << "Ferma cu id-ul " << ferma.id << (ferma.sistemIrigatie ? " are sistem de irigatie mecanizat " : " nu are sistem de irigatie mecanizat ") << "si are un numar de " << ferma.numarRecolte << " recolte. Recoltele sunt: " << endl;
		if (ferma.numarRecolte == 0)
			out << "-";
		else
			for (int i = 0; i < ferma.numarRecolte; i++)
				out << ferma.recolte[i];
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Ferma& ferma) {
		cout << "Sitem de irigatie? 0-NU 1-DA: ";
		in >> ferma.sistemIrigatie;
		cout << "Numar recolte: ";
		in >> ferma.numarRecolte;
		if (ferma.recolte != NULL)
			delete[]ferma.recolte;
		ferma.recolte= new Recolta[ferma.numarRecolte];
		for (int i = 0; i < ferma.numarRecolte; i++)
			in >> ferma.recolte[i];
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const Ferma& ferma) {
		out << "Sistem de irigatie:" << ferma.sistemIrigatie << endl << "Numar recolte:" << ferma.numarRecolte << endl;

		for (int i = 0; i < ferma.numarRecolte; i++)
			out << ferma.recolte[i] << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Ferma& ferma) {
		in >> ferma.sistemIrigatie;
		in >> ferma.numarRecolte;
		if (ferma.recolte != NULL)
			delete[]ferma.recolte;
		ferma.recolte = new Recolta[ferma.numarRecolte];
		for (int i = 0; i < ferma.numarRecolte; i++)
			in >> ferma.recolte[i];
		return in;
	}
};

class LivadaIrigata : public Livada {
private:
	float cantitateApaAnuala;
	char* sistemIrigare;
public:

	LivadaIrigata() : Livada("piersici", 0) {
		this->cantitateApaAnuala = 0;
		this->sistemIrigare = new char[strlen("picurare") + 1];
		strcpy_s(this->sistemIrigare, strlen("picurare") + 1, "picurare");
	}

	LivadaIrigata(float cantitateApaAnuala, const char* sistemIrigare, string tipFructe) : Livada(tipFructe, 0) {
		this->cantitateApaAnuala = cantitateApaAnuala;
		this->sistemIrigare = new char[strlen(sistemIrigare) + 1];
		strcpy_s(this->sistemIrigare, strlen(sistemIrigare) + 1, sistemIrigare);
	}

	LivadaIrigata(float cantitateApaAnuala, const char* sistemIrigare, string tipFructe, float randamentAnual, int numarPomi, int* vechimePomi) : Livada(tipFructe, randamentAnual, numarPomi, vechimePomi) {
		this->cantitateApaAnuala = cantitateApaAnuala;
		this->sistemIrigare = new char[strlen(sistemIrigare) + 1];
		strcpy_s(this->sistemIrigare, strlen(sistemIrigare) + 1, sistemIrigare);
	}

	LivadaIrigata(const LivadaIrigata& li) : Livada(li) {
		this->cantitateApaAnuala = li.cantitateApaAnuala;
		this->sistemIrigare = new char[strlen(li.sistemIrigare) + 1];
		strcpy_s(this->sistemIrigare, strlen(li.sistemIrigare) + 1, li.sistemIrigare);
	}

	LivadaIrigata operator=(const LivadaIrigata& li) {
		if (this != &li) {
			Livada::operator=(li);
			if (this->sistemIrigare != NULL) {
				delete[]this->sistemIrigare;
			}
			this->cantitateApaAnuala = li.cantitateApaAnuala;
			this->sistemIrigare = new char[strlen(li.sistemIrigare) + 1];
			strcpy_s(this->sistemIrigare, strlen(li.sistemIrigare) + 1, li.sistemIrigare);
		}
		return *this;
	}

	~LivadaIrigata() {
		if (this->sistemIrigare != NULL) {
			delete[]this->sistemIrigare;
		}
	}

	void setCantitateApaAnuala(float cantitateApaAnuala) {
		if (cantitateApaAnuala > 0) {
			this->cantitateApaAnuala = cantitateApaAnuala;
		}
	}

	float getCantitateApaAnuala() {
		return this->cantitateApaAnuala;
	}

	void setSistemIrigare(const char* sistemIrigare) {
		if (this->sistemIrigare != NULL) {
			delete[]this->sistemIrigare;
		}
		this->sistemIrigare = new char[strlen(sistemIrigare) + 1];
		strcpy_s(this->sistemIrigare, strlen(sistemIrigare) + 1, sistemIrigare);
	}

	char* getSistemIrigare() {
		return this->sistemIrigare;
	}

	friend ostream& operator<<(ostream& out, const LivadaIrigata& li) {
		out << (Livada)li;
		out << "Cantitate apa anuala folosita: " << li.cantitateApaAnuala << "m cubi" << endl;
		out << "Sistemul de irigare folosit: " << li.sistemIrigare << endl;
		return out;
	}

	friend istream& operator>>(istream& in, LivadaIrigata& li) {
		in >> (Livada&)li;
		cout << "Cantitatea anuala de apa folosita: ";
		in >> li.cantitateApaAnuala;
		if (li.sistemIrigare)
		{
			delete[]li.sistemIrigare;
		}
		cout << "Sistem de irigare folosit: ";
		char buffer[30];
		in >> buffer;
		li.sistemIrigare = new char[strlen(buffer) + 1];
		strcpy_s(li.sistemIrigare, strlen(buffer) + 1, buffer);
		return in;
	}

	//upcasting
	LivadaIrigata(const Livada& l) :Livada(l) {
		this->cantitateApaAnuala = 235.5;
		this->sistemIrigare = new char[strlen("automatizat")+1];
		strcpy_s(this->sistemIrigare, strlen("automatizat") + 1, "automatizat");
	}
};

class SolPoluat : public Sol {
private:
	string tipPoluare;
	int numarDeseuri;
	string* deseuri;
public:

	SolPoluat() :Sol() {
		this->tipPoluare = "-";
		this->numarDeseuri = 0;
		this->deseuri = NULL;
	}

	SolPoluat(int numarDeseuri, string* deseuri, string tipSol ) :Sol(tipSol, "medie", 0) {
		this->tipPoluare = "biologica";
		this->numarDeseuri = numarDeseuri;
		this->deseuri = new string[numarDeseuri];
		for (int i = 0; i < numarDeseuri; i++) {
			this->deseuri[i] = deseuri[i];
		}
	}

	SolPoluat(string tipPoluare, int numarDeseuri, string* deseuri, string tipSol, string fertilitate, float suprafataCultivata, int numarCulturi, string* tipCulturi) : Sol(tipSol, fertilitate, suprafataCultivata, numarCulturi, tipCulturi) {
		this->tipPoluare = tipPoluare;
		this->numarDeseuri = numarDeseuri;
		this->deseuri = new string[numarDeseuri];
		for (int i = 0; i < numarDeseuri; i++) {
			this->deseuri[i] = deseuri[i];
		}
	}

	SolPoluat(const SolPoluat& sp) :Sol(sp) {
		this->tipPoluare = sp.tipPoluare;
		this->numarDeseuri = sp.numarDeseuri;
		this->deseuri = new string[numarDeseuri];
		for (int i = 0; i < numarDeseuri; i++) {
			this->deseuri[i] = sp.deseuri[i];
		}
	}

	SolPoluat operator=(const SolPoluat& sp) {
		if (this != &sp) {
			Sol::operator=(sp);
			if (this->deseuri != NULL) {
				delete[]this->deseuri;
			}
			this->tipPoluare = sp.tipPoluare;
			this->numarDeseuri = sp.numarDeseuri;
			this->deseuri = new string[numarDeseuri];
			for (int i = 0; i < numarDeseuri; i++) {
				this->deseuri[i] = sp.deseuri[i];
			}
		}
		return *this;
	}

	~SolPoluat() {
		if (this->deseuri != NULL) {
			delete[]this->deseuri;
		}
	}

	void setTipPoluare(string tipPoluare) {
		if (tipPoluare.length() != 0) {
			this->tipPoluare = tipPoluare;
		}
	}

	string getTipPoluare() {
		return this->tipPoluare;
	}

	void setNrDeseuri(int numarDeseuri, string* deseuri) {
		if (numarDeseuri > 0) {
			this->numarDeseuri = numarDeseuri;
		}
		if (this->deseuri != NULL) {
			delete[]this->deseuri;
		}
		this->deseuri = new string[numarDeseuri];
		for (int i = 0; i < numarDeseuri; i++) {
			this->deseuri[i] = deseuri[i];
		}
	}

	int getNrDeseuri() {
		return this->numarDeseuri;
	}

	string* getDeseuri() {
		return this->deseuri;
	}

	friend ostream& operator<<(ostream& out, const SolPoluat& sp) {
		out << (Sol)sp;
		out << "Tipul de poluare: " << sp.tipPoluare  << endl;
		out << "Numarul desurilor: " << sp.numarDeseuri << endl;
		out << "Deseurile sunt: ";
		if (sp.numarDeseuri == 0)
			out << "-";
		else
			for (int i = 0; i < sp.numarDeseuri; i++)
				out << sp.deseuri[i] << " ";
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, SolPoluat& sp) {
		in >> (Sol&)sp;
		cout << "Tipul de poluare: ";
		in >> sp.tipPoluare;
		cout << "Numarul desurilor: ";
		in >> sp.numarDeseuri;
		if (sp.deseuri)
		{
			delete[]sp.deseuri;
		}
		sp.deseuri = new string[sp.numarDeseuri];
		for (int i = 0; i < sp.numarDeseuri; i++) {
			cout << "Deseul " << i + 1 << ": ";
			in >> sp.deseuri[i];
		}
		return in;
	}

	//upcasting
	SolPoluat(const Sol& s) :Sol(s) {
		this->tipPoluare = "fara poluare";
		this->numarDeseuri = 0;
		this->deseuri = NULL;
	}
};

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

	cout << endl << "Calitatea de referinta a recoltei4 este: " << recolta4.getCalitateDeReferinta() << endl;

	cout << endl << "Numarul de soiuri al recoltei2 este: " << recolta2.getNrSoiuri() << endl;

	recolta4.setTipCultura("cartof");
	cout << endl << "Cultura recoltei4 este: " << recolta4.getTipCultura() << endl;

	recolta4.setCantitate(176.7);
	cout << endl << "Cantitatea recoltei4 este: " << recolta4.getCantitate() << endl;

	int* vectorRecolta = new int [4] {6, 3, 4, 2};

	recolta4.setNrZileRecoltare(4, vectorRecolta);
	recolta4.afisareRecolta();
	
	delete[]vectorRecolta;

	cout << endl << "Numarul de zile in care s-a recoltat recolta4 este: " << recolta4.getNrZileRecoltare() << endl;

	cout << endl << "Numarul de ore din ziua 2 in care s-a recoltat recolta4: " << recolta4.getOrePeZi()[1] << endl;

	Recolta recolta5 = recolta2;
	cout << recolta5;

	Recolta recolta6;
	recolta6 = recolta2 + recolta4;
	cout << recolta6;

	recolta2 += recolta6;
	cout << recolta2;

	if (recolta2 > recolta4)
		cout << endl << "Recolta 2 are o cantitate mai mare decat recolta 3." << endl;
	else
		cout << endl << "Recolta 2 are o cantitate mai mica sau egala decat recolta 3" << endl;

	cout << endl << "Numarul de ore din ziua 2 in care s-a recoltat recolta4: " << recolta4[1] << endl;
	recolta4[1] = 4;
	cout << recolta4;
	cout << endl << "Noul numar de ore din ziua 2 in care s-a recoltat recolta4: " << recolta4[1] << endl;

	cout << endl << "Timpul mediu pentru reolta2 este: " << getTimpMediuPeZi(recolta2) << endl;

	recolta2 = recolta4++;
	cout << recolta4;
	cout << recolta2;

	//int numarRecolte;
	//cout << endl << "Introduceti numarul de recolte: ";
	//cin >> numarRecolte;
	//Recolta* vectorRecolte = new Recolta[numarRecolte];
	//for (int i = 0; i < numarRecolte; i++) {
	//	cout << endl << "Detalii recolta " << i + 1 << ":" << endl;
	//	cin >> vectorRecolte[i];
	//}
	//for (int i = 0; i < numarRecolte; i++) {
	//	cout << vectorRecolte[i] << endl;
	//}
	//delete[]vectorRecolte;



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

	cout << endl << "Livada4 a fost plantata pentru:  " << livada4.getScopLivada() << endl;

	cout << endl << "Livada1 a fost plantata in anul: " << livada1.getAnPlantatie() << endl;

	livada4.setTipFructe("peri");
	cout << endl << "Pomii din livada4 sunt: " << livada4.getTipFructe() << endl;

	livada4.setRandamentAnual(56.4);
	cout << endl << "Randamentul anual al livezii4 este: " << livada4.getRandamentAnual() << endl;

	int* vectorLivada = new int[3] {11, 10, 12};

	livada4.setNrPomi(3, vectorLivada);
	livada4.afisareLivada();

	delete[]vectorLivada;

	cout << endl << "Numarul de pomi al livezii4 este: " << livada4.getNrPomi() << endl;

	cout << endl << "Vechimea pomului 1 este: " << livada4.getVechimePomi()[0] << endl;

	Livada livada5 = livada2;
	cout << livada5;

	Livada livada6;
	livada6 = livada2 + livada4;
	cout << livada6;

	livada4 += livada2;
	cout << livada4;

	if (livada2 == livada4)
		cout << endl << "Livada 2 si livada 4 au acelasi randament anual si acelasi numar de pomi." << endl;
	else
		cout << endl << "Livada 2 si livada 4 au randamentul anual si numarul de pomi diferite." << endl;

	cout << endl << "Vechime pomului 3 a livezii2 este: " << livada2[2] << endl;
	livada2[2] = 10;
	cout << livada2;
	cout << endl << "Noua vechime a pomului 3 a livezii2 este: " << livada2[2] << endl;

	cout << endl << "Media vechimii pomilor de la 1 la 3 este:" << livada2(1, 3) << endl;

	/*int numarLivezi;
	cout << endl << "Introduceti numarul de livezi: ";
	cin >> numarLivezi;
	Livada* vectorLivezi = new Livada[numarLivezi];
	for (int i = 0; i < numarLivezi; i++) {
		cout << endl << "Detalii livada " << i + 1 << ":" << endl;
		cin >> vectorLivezi[i];
	}
	for (int i = 0; i < numarLivezi; i++) {
		cout << vectorLivezi[i] << endl;
	}
	delete[]vectorLivezi;*/



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

	cout << endl << "Ph-ul optim pentru solul4 este: " << sol4.getPhOptim() << endl;

	cout << endl << "Solul1 a avut prima cultura in anul: " << sol1.getAnPrimaCultura() << endl;

	sol4.setTipSol("negru");
	cout << endl << "Solul4 este de tipul: " << sol4.getTipSol() << endl;

	sol4.setFertilitate("foarte crescuta");
	cout << endl << "Solul4 are fertilitatea: " << sol4.getFertilitate() << endl;

	sol4.setSuprafataCultivata(22.3);
	cout << endl << "Suprafata cultivata a solului4 este de: " << sol4.getSuprafataCultivata() << endl;

	string* vectorSol = new string[2]{ "morcov", "ceapa" };
	sol4.setNrCulturi(2, vectorSol);
	sol4.afisareSol();

	delete[]vectorSol;

	cout << endl << "Numarul de culturi plantate pe solul4 este : " << sol4.getNrCulturi() << endl;

	cout << endl << "Cultura 2 a solului4 a fost de: " << sol4.getTipCulturi(1) << endl;

	Sol sol5 = sol2;
	cout << sol5;

	Sol sol6;
	sol6 = sol2 + sol4;
	cout << sol6;

	sol4 += sol6;
	cout << sol4;

	if (sol2 != sol3)
		cout << endl << "Solul 2 si solul 3 au fertilitate diferita." << endl;
	else
		cout << endl << "Solul 2 si solul 3 au aceeasi fertilitate." << endl;

	cout << sol2;
	cout << endl << "Prima cultura a solului2 este: " << sol2[0] << endl;
	sol2[0] = "conopida";
	cout << sol2;
	cout << endl << "Noua prima cultura a solului2 este: " << sol2[0] << endl;


	int culturiSol;
	culturiSol = (int)sol4;
	cout << endl << culturiSol << endl;

	cout << sol2;
	sol2 = sol2 + 3.2;
	cout << sol2;
	cout << endl << "Noua suprafata cultivata a solului2 este: " << sol2.getSuprafataCultivata() << endl;

	//int numarSoluri;
	//cout << endl << "Introduceti numarul de soluri: ";
	//cin >> numarSoluri;
	//Sol* vectorSoluri = new Sol[numarSoluri];
	//for (int i = 0; i < numarSoluri; i++) {
	//	cout << endl << "Detalii sol " << i + 1 << ":" << endl;
	//	cin >> vectorSoluri[i];
	//}
	//for (int i = 0; i < numarSoluri; i++) {
	//	cout << vectorSoluri[i] << endl;
	//}
	//delete[]vectorSoluri;

	//const int linii = 2;
	//const int coloane = 2;
	//Sol matriceSol[linii][coloane];
	//for (int i = 0; i < linii; i++) {
	//	for (int j = 0; j < coloane; j++) {
	//		cout << endl << "Detaliile solului [" << i + 1 << "][" << j + 1 << "]: " << endl;
	//		cin >> matriceSol[i][j];
	//	}
	//}
	//for (int i = 0; i < linii; i++) {
	//	for (int j = 0; j < coloane; j++) {
	//		cout << endl << "Solul [" << i + 1 << "][" << j + 1 << "]: ";
	//		cout << matriceSol[i][j] << " ";
	//	}
	//	cout << endl;
	//}



	Ferma ferma1;
	ferma1.afisareFerma();
	
	Recolta* recolte = new Recolta[3] {recolta3, recolta4, recolta5};

	Ferma ferma2(1, true, 3, recolte);
	ferma2.afisareFerma();

	Ferma ferma3(ferma2);
	ferma3.afisareFerma();

	cout << endl << "Id-ul fermei1 este: " << ferma1.getId() << endl;

	ferma3.setSistemIrigatie(false);
	cout << endl << "Ferma3 " << (ferma3.getSistemIrigatie() ? "are" : "nu are") << " sistem de irigatie." << endl;
	ferma3.afisareFerma();

	Recolta* vectorFerma = new Recolta[2]{recolta2, recolta6};
	ferma3.setNrRecolte(2, vectorFerma);
	ferma3.afisareFerma();

	delete[]vectorFerma;

	cout << endl << "Numarul de recolte al fermei3 este: " << ferma3.getNrRecolte() << endl;

	cout << endl << "Recolta1 a fermei3 este: " << ferma3.getRecolte()[0] << endl;

	ferma1 = ferma2 + ferma3;
	ferma1.afisareFerma();

	cout << endl << "Recolta 3 a fermei1 este: " << ferma1[2] << endl;
	ferma1[2] = recolta6;
	cout << endl << "Noua recolta 3 a fermei1 este: " << ferma1[2] << endl;

	ferma3.afisareFerma();
	ferma3 = !ferma3;
	ferma3.afisareFerma();

	/*ofstream fsol("soluri.txt",ios::out);
	Sol s1;
	cin >> s1;
	fsol << s1;
	fsol.close();
	ifstream f1sol("soluri.txt", ios::in);
	f1sol >> s1;
	cout << s1;
	f1sol.close();*/

	/*ofstream fferma("ferme.txt", ios::out);
	Ferma f1;
	cin >> f1;
	fferma << f1;
	fferma.close();
	ifstream f1ferma("ferme.txt", ios::in);
	cout << f1;
	f1ferma >> f1;
	f1ferma.close();*/

	
	/*Recolta r1;
	cin >> r1;
	fstream frecolta("recolte.bin", ios::binary | ios::out);
	frecolta.write((char*)&r1, sizeof(Recolta));
	r1.scriereBinRecolta(frecolta);
	frecolta.close();
	fstream f1recolta("recolte.bin", ios::binary | ios::in);
	f1recolta.read((char*)&r1, sizeof(Recolta));
	r1.citireBinRecolta(f1recolta);
	cout << r1;
	f1recolta.close();*/

	/*Livada l1;
	cin >> l1;
	fstream flivada("livezi.bin", ios::binary | ios::out);
	flivada.write((char*)&l1, sizeof(Livada));
	l1.scriereBinLivada(flivada);
	flivada.close();
	fstream f1livada("livezi.bin", ios::binary | ios::in);
	f1livada.read((char*)&l1, sizeof(Livada));
	l1.citireBinLivada(f1livada);
	cout << l1;
	f1livada.close();*/

	
	
	LivadaIrigata li1;
	cout << li1;

	LivadaIrigata li2(0, "microasperisie", "gutui");
	cout << li2;

	int* vectorLivadaIrigata = new int[3] {10, 11, 9};
	LivadaIrigata li3(300.5, "fertirigare", "gutui", 55.5, 3, vectorLivadaIrigata);
	cout << li3;

	LivadaIrigata li4(li3);
	cout << li4;
	
	LivadaIrigata li5;
	li5 = li4;
	cout << li5;

	li3.setCantitateApaAnuala(299.2);
	cout << endl << "Cantitatea de apa anuala folosita pentru livada irigata 3: " << li3.getCantitateApaAnuala() << endl;

	li3.setSistemIrigare("pompare");
	cout << endl << "Sistemul de irigare folosit pentru livada irigata 3: " << li3.getSistemIrigare() << endl;

	cout << endl << "Tipul de pomi fructiferi din livada irigata 3: " << li3.getTipFructe() << endl;

	int* vectorPomi = new int[4] {8, 12, 12, 10};
	li3.setNrPomi(4, vectorPomi);
	
	delete[]vectorPomi;

	cout << endl << "Numarul de pomi din livada irigata 3: " << li3.getNrPomi() << endl;

	cout << li3;
	
	LivadaIrigata li6(livada6);
	cout << li6;



	SolPoluat sp1;
	cout << sp1;

	string* vectorSolPoluat1 = new string[2]{ "bacterii", "virusi" };
	SolPoluat sp2(2, vectorSolPoluat1, "argilos");
	cout << sp2;

	string* vectorSolPoluat2 = new string[2]{ "otel", "petrol" };
	string* culturi = new string[2]{ "ceapa", "usturoi" };
	SolPoluat sp3("industriala", 2, vectorSolPoluat2, "nisipos", "scazuta", 34.6, 2, culturi);
	cout << sp3;

	SolPoluat sp4(sp3);
	cout << sp3;

	SolPoluat sp5;
	sp5 = sp4;
	cout << sp5;

	sp3.setTipPoluare("urbana");
	cout << endl << "Tipul de poluare pentru solul poluat 3: " << sp3.getTipPoluare()<< endl;

	string* deseuri = new string[3] { "sticla", "plastic", "hartie"};
	sp3.setNrDeseuri(3, deseuri);
	delete[]deseuri;

	cout << endl << "Numarul de deseuri continut de solul poluat 3: " << sp3.getNrDeseuri() << endl;

	cout << endl << "Primul deseu din solul poluat 3: " << sp3.getDeseuri()[0] << endl;

	cout << sp3;

	cout << endl << "Prima cultura a solului poluat 3: " << sp3.getTipCulturi(0) << endl;

	SolPoluat sp6(sol6);
	cout << sp6;
	
}
