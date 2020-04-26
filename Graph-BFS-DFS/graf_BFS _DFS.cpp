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
}//ENQUEUE

void Kolejka::Dequeue()
{
	if (Empty() == 0)
	{
		Front = AddOne(Front);
	}
}//DEQUEUE

void Kolejka::Makenull()
{
	Front = 0;
	Rear = maxlength - 1;
}//WYCZSZCZENIE KOLEJKI

elementtype Kolejka::FrontElem()
{
	if (!Empty())
		return Queue[Front];
	else return 100000000;
}//PIERWSZY ELEMENT W KOLEJCE

int Kolejka::AddOne(int i) {
	return ((i + 1) % maxlength);
}//ADDONE

bool Kolejka::Empty()
{
	return (AddOne(Rear) == Front);
}//EMPTY


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
}//EMPTY 

int Stos::TopElem()
{
	if (Top >= 0) return S[Top];
}//ELEMENT NA SZCZYCIE 

class GrafNieSkierowanyLista : public Wierzcholek
{
	int liczbakrawedzi = 0;
	int rozmiar = 0;
	vector<vector<Wierzcholek> > w;
public:
	GrafNieSkierowanyLista();
	~GrafNieSkierowanyLista();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void show_BFS();
	void show_DFS();
	void show();
};


GrafNieSkierowanyLista::GrafNieSkierowanyLista()
{
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			w.push_back(vector<Wierzcholek>(0));
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

void GrafNieSkierowanyLista::show_BFS()
{
	bool* odwiedzone = new bool[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		odwiedzone[i] = false;
	}

	int pocz = 0;
	Kolejka S = Kolejka();
	S.Enqueue(pocz);
	odwiedzone[0] = true;
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
				S.Push(sprawdz);
			}
		}
	}
	cout << endl;
	delete[] odwiedzone;
}


int main()
{
	setlocale(LC_CTYPE, "Polish");
	GrafNieSkierowanyLista graf;
	graf.podajLiczbeKrawedzi();
	graf.okreslPolaczenia();
	graf.show();
	graf.show_BFS();
	graf.show_DFS();
}