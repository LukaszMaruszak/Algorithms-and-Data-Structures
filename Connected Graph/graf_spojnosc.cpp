//Autor Łukasz Maruszak
#include <iostream>
#include <vector>

using namespace std;

const int maxlength = 50;
typedef int elementtype;
typedef int position;

class Wierzcholek {
public:
	int value = -1;
public:
	int getValue() {
		return value;
	}
};

class Kolejka
{
protected:
	elementtype Queue[maxlength];
	position Front; // Index of Head element
	position Rear; // Index of last element
public:
	Kolejka() {
		Front = 0;
		Rear = maxlength - 1;
	};
	static int AddOne(int i);
	void Enqueue(elementtype x);
	void Dequeue();
	elementtype FrontElem();
	void Makenull();
	bool Empty();
};
void Kolejka::Enqueue(elementtype x)
{
	if (AddOne(AddOne(Rear)) != Front)
	{
		Rear = AddOne(Rear);
		Queue[Rear] = x;
	}
}
void Kolejka::Dequeue()
{
	if (Empty() == 0)
	{
		Front = AddOne(Front);
	}
}
void Kolejka::Makenull()
{
	Front = 0;
	Rear = maxlength - 1;
}
elementtype Kolejka::FrontElem()
{
	if (!Empty())
		return Queue[Front];
	else return 100000000;
}
int Kolejka::AddOne(int i) {
	return ((i + 1) % maxlength);
}
bool Kolejka::Empty()
{
	return (AddOne(Rear) == Front);
}


class Stos
{
protected:
	int S[maxlength];
	position Top;//szczyt stosu
public:
	Stos();
	void Push(int x);
	void Pop();
	bool Empty();
	int TopElem();
	void Makenull();
};

Stos::Stos()
{
	Top = -1;
}// KONSTRUKTOR

void Stos::Makenull()
{
	Top = -1;
}// WYCZYSZCZENIE STOSU	

void Stos::Push(int x)
{
	if (Top < maxlength - 1)
	{
		Top++;
		S[Top] = x;
	}
}// PUSH

void Stos::Pop()
{
	if (Top >= 0) Top--;
}//POP

bool Stos::Empty()
{
	return (Top == -1);
}//Empty 

int Stos::TopElem()
{
	if (Top >= 0) return S[Top];
}//Element na szczycie

class GrafNieSkierowanyLista : public Wierzcholek
{
	int liczbakrawedzi = 0;
	int rozmiar = 0;
	//tablica do funkcji rekurencyjnej
	bool* odwiedzone_rek = new bool[rozmiar];
	int iloscOdwiedzonych = 0;
	vector<vector<Wierzcholek> > w;
public:
	GrafNieSkierowanyLista();
	~GrafNieSkierowanyLista();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void show_BFS(int poczatek);
	void show_DFS();
	void show_DFS_recursion(int pocz);
	void jest_spojny();
	void show();
};


GrafNieSkierowanyLista::GrafNieSkierowanyLista()
{
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			w.push_back(vector<Wierzcholek>(0));

	for (int i = 0; i < rozmiar; i++)
	{
		odwiedzone_rek[i] = false;
	}
}

GrafNieSkierowanyLista::~GrafNieSkierowanyLista()
{

}


void GrafNieSkierowanyLista::podajLiczbeKrawedzi()
{
	cout << "Podaj liczbę krawedzi: ";
	int ilosc;
	cin >> ilosc;
	liczbakrawedzi = ilosc;
}

void GrafNieSkierowanyLista::okreslPolaczenia()
{
	int xpoz, ypoz;
	for (int i = 0; i < liczbakrawedzi; i++)
	{
		cout << "Podaj pare wierzchołków." << endl;
		cin >> xpoz;
		cin >> ypoz;
		Wierzcholek x;
		Wierzcholek y;
		x.value = xpoz;
		y.value = ypoz;
		w[xpoz].push_back(y);
		w[ypoz].push_back(x);
	}
}

void GrafNieSkierowanyLista::show()
{
	for (int i = 0; i < w.size(); i++) {
		if (w[i].size() == 0) continue;
		cout << "(" << i << ")" << " -> ";
		for (int j = 0; j < w[i].size(); j++) {
			cout << "(" << w[i][j].getValue() << "), ";
		}
		cout << endl;
	}
}

void GrafNieSkierowanyLista::show_BFS(int poczatek)
{
	bool* odwiedzone = new bool[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		odwiedzone[i] = false;
	}

	
	Kolejka S = Kolejka();
	S.Enqueue(poczatek);
	odwiedzone[poczatek] = true;
	cout << "Graf przeglądany BFS:";

	while (S.Empty() == false)
	{
		//Wierzcholek next;
		int next = S.FrontElem();
		S.Dequeue();

		cout << " " << next;

		for (int j = 0; j < w[next].size(); j++) {
			int sprawdz = w[next][j].getValue();
			if (odwiedzone[sprawdz] == false) {
				odwiedzone[sprawdz] = true;
				S.Enqueue(sprawdz);
			}
		}
	}
	cout << endl;
	delete[] odwiedzone;
}

void GrafNieSkierowanyLista::show_DFS()
{
	bool* odwiedzone = new bool[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		odwiedzone[i] = false;
	}

	int pocz = 0;
	Stos S;
	S.Push(pocz);
	odwiedzone[0] = true;
	iloscOdwiedzonych++;
	cout << "Graf przeglądany DFS:";

	while (S.Empty() == false)
	{
		//Wierzcholek next;
		int next = S.TopElem();
		S.Pop();

		cout << " " << next;

		for (int j = 0; j < w[next].size(); j++) {
			int sprawdz = w[next][j].getValue();
			if (odwiedzone[sprawdz] == false) {
				odwiedzone[sprawdz] = true;
				iloscOdwiedzonych++;
				S.Push(sprawdz);
			}
		}
	}
	cout << endl;
	delete[] odwiedzone;
}

void GrafNieSkierowanyLista::show_DFS_recursion(int pocz)
{
	odwiedzone_rek[pocz] = true;
	cout << " " << pocz;
	
	for (int j = 0; j < w[pocz].size(); j++) {
		int sprawdz = w[pocz][j].getValue();
		if (odwiedzone_rek[sprawdz] == false) {
			show_DFS_recursion(sprawdz);			
		}
	}
}

void GrafNieSkierowanyLista::jest_spojny()
{
	if (iloscOdwiedzonych == rozmiar)
		cout << "Graf jest spójny" << endl;
	else
		cout << "Graf nie jest spójny" << endl;
}

// GRAF SKIEROWANY

class GrafSkierowanyLista 
{
	int liczbakrawedzi = 0;
	int rozmiar = 0;
	int iloscOdwiedzonych = 0;
	vector<vector<Wierzcholek> > w;
public:
	GrafSkierowanyLista();
	~GrafSkierowanyLista();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void show_BFS(int poczatek);
	void jest_spojny();
	void show();
};


GrafSkierowanyLista::GrafSkierowanyLista()
{
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			w.push_back(vector<Wierzcholek>(0));
}

GrafSkierowanyLista::~GrafSkierowanyLista()
{
}


void GrafSkierowanyLista::podajLiczbeKrawedzi()
{
	cout << "Podaj liczbę krawedzi: ";
	int ilosc;
	cin >> ilosc;
	liczbakrawedzi = ilosc;
}

void GrafSkierowanyLista::okreslPolaczenia()
{
	int xpoz, ypoz;
	for (int i = 0; i < liczbakrawedzi; i++)
	{
		cout << "Podaj pare wierzchołków." << endl;
		cin >> xpoz;
		cin >> ypoz;
		Wierzcholek y;
		y.value = ypoz;		
		w[xpoz].push_back(y);
	}
}

void GrafSkierowanyLista::show_BFS(int poczatek)
{
	bool* odwiedzone = new bool[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		odwiedzone[i] = false;
	}
	iloscOdwiedzonych = 0;
	Kolejka S = Kolejka();
	S.Enqueue(poczatek);
	odwiedzone[poczatek] = true;
	iloscOdwiedzonych++;
	cout << "Graf przeglądany BFS:";

	while (S.Empty() == false)
	{
		//Wierzcholek next;
		int next = S.FrontElem();
		S.Dequeue();

		cout << " " << next;

		for (int j = 0; j < w[next].size(); j++) {
			int sprawdz = w[next][j].getValue();
			if (odwiedzone[sprawdz] == false) {
				odwiedzone[sprawdz] = true;
				iloscOdwiedzonych++;
				S.Enqueue(sprawdz);
			}
		}
	}
    cout << endl;
	delete[] odwiedzone;
}

void GrafSkierowanyLista::jest_spojny()
{
	int odwiedzone_razem = 0;
	for (int i = 0; i < rozmiar; i++) {
		show_BFS(i);
		odwiedzone_razem += iloscOdwiedzonych;
	}
	if (odwiedzone_razem == rozmiar * rozmiar)
			cout << "Graf jest spójny" << endl;
		else
			cout << "Graf nie jest spójny" << endl;
}


void GrafSkierowanyLista::show()
{
	for (int i = 0; i < w.size(); i++) {
		if (w[i].size() == 0) continue;
		cout << "(" << i << ")" << " -> ";
		for (int j = 0; j < w[i].size(); j++) {
			cout << "(" << w[i][j].getValue() << "), ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Polish");
	/*GrafNieSkierowanyLista graf;
	graf.podajLiczbeKrawedzi();
	graf.okreslPolaczenia();
	graf.show();
	graf.show_BFS(0);
	graf.show_DFS();
	cout << "Graf przeglądany DFS:";
	graf.show_DFS_recursion(0);
	cout << endl;
	graf.jest_spojny();*/

	GrafSkierowanyLista graf1 = GrafSkierowanyLista();
	graf1.podajLiczbeKrawedzi();
	graf1.okreslPolaczenia();
	graf1.show();
	graf1.show_BFS(0);
	graf1.jest_spojny();
}