//Author: Łukasz Maruszak
#include <iostream>
#include <locale.h>
#include <vector>
#include <queue> 

const int inf = 65535;

using namespace std;

class GrafSkierowanyMacierz {
	int **macierz;
	int **wagiKrawedzi;
	int liczbakrawedzi = 0;
	int rozmiar = 0;
	int *Wierzcholki;
	//piorytet, wierzcholek
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
public:
	GrafSkierowanyMacierz(int rozmiar);
	~GrafSkierowanyMacierz();
	void dodajWierzcholek(int numer);
	void okreslPolaczenia(int z, int y, int waga);
	void podajSasiedzi();
	void printPath(int predecessor[], int end);
	int* Dijkstra_Algorithm(int poczatek);
	void show();
};


GrafSkierowanyMacierz::GrafSkierowanyMacierz(int r) {
	rozmiar = r;
	macierz = new int* [rozmiar];
	wagiKrawedzi = new int* [rozmiar];
	Wierzcholki = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		macierz[i] = new int[rozmiar];
		for (int j = 0; j < rozmiar; ++j) //wpisanie wartosci do tablicy
			macierz[i][j] = 0;
	}

	for (int i = 0; i < rozmiar; i++)
	{
		wagiKrawedzi[i] = new int[rozmiar];
		for (int j = 0; j < rozmiar; ++j) //wpisanie wartosci do tablicy
			wagiKrawedzi[i][j] = 0;
	}
}

GrafSkierowanyMacierz::~GrafSkierowanyMacierz()
{
	for (int i = 0; i < rozmiar; ++i)
		delete[] macierz[i]; //uwolnienie pamieci
		delete[] macierz; //uwolnienie pamieci
	
}

void GrafSkierowanyMacierz::dodajWierzcholek(int numer)
{
	Wierzcholki[numer] = numer;
}

void GrafSkierowanyMacierz::okreslPolaczenia(int xpoz, int ypoz, int waga)
{
	macierz[xpoz][ypoz] = 1;
	wagiKrawedzi[xpoz][ypoz] = waga;
}


void GrafSkierowanyMacierz::podajSasiedzi()
{
	cout << "Podaj wierzchołek aby podać sąsiadów." << endl;
	int t = 0;
	cin >> t;
	cout << "Sąsiedzi wierzchołka " << t << " ";
	if (t < rozmiar)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			if (macierz[t][i] == 1)
				cout << '(' << i << ')' << " ";
		}
	}
	cout << endl;
}

int* GrafSkierowanyMacierz::Dijkstra_Algorithm(int poczatek)
{
	bool *known = new bool [rozmiar];
	int *distance = new int[rozmiar];
	int * predecessor = new int[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{
		known[i] = false;
		distance[i] = inf;
		predecessor[i] = -1;
	}

	distance[poczatek] = 0;

	pq.push(make_pair(0, poczatek));

	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		int wierzchołek = top.second;

		if (known[wierzchołek] != true) {
			known[wierzchołek] = true;

			for (int i = 0; i < rozmiar; i++)
			{
				if (macierz[wierzchołek][i] == 1) {
					int w = i;
					int d = distance[wierzchołek] + wagiKrawedzi[wierzchołek][w];
					if (distance[w] > d) {
						distance[w] = d;
						predecessor[w] = wierzchołek;
						pq.push(make_pair(d, w));
					}
				}
			}
		}
	}
	return predecessor;
	
	delete[] known;
	delete[] distance;
	delete[] predecessor;
}

void GrafSkierowanyMacierz::printPath(int predecessor[],int end)
{
	if (predecessor[end] == -1) return;

	printPath(predecessor, predecessor[end]);

	cout << end << " ";
}

void GrafSkierowanyMacierz::show()
{
	cout << " ";
	for (int k = 0; k < rozmiar; k++) cout << " " << k;
	cout << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << i << " ";
		for (int j = 0; j < rozmiar; j++) cout << macierz[i][j] << " ";
		cout << endl;
	}
}





int main()
{
	setlocale(LC_CTYPE, "Polish");
	int start = 0;
	int end = 6;
	int size = 7;
	GrafSkierowanyMacierz graf = GrafSkierowanyMacierz(size);
    graf.dodajWierzcholek(0);
	graf.dodajWierzcholek(1);
	graf.dodajWierzcholek(2);
	graf.dodajWierzcholek(3);
	graf.dodajWierzcholek(4);
	graf.dodajWierzcholek(5);
	graf.dodajWierzcholek(6);

	graf.okreslPolaczenia(0, 1, 1);
	graf.okreslPolaczenia(0, 2, 2);
	graf.okreslPolaczenia(1, 2, 1);
	graf.okreslPolaczenia(1, 5, 5);
	graf.okreslPolaczenia(1, 3, 3);
	graf.okreslPolaczenia(6, 1, 2);
	graf.okreslPolaczenia(3, 4, 3);
	graf.okreslPolaczenia(4, 6, 3);
	graf.okreslPolaczenia(6, 5, 1);
	graf.okreslPolaczenia(5, 4, 2);

	int *tablica = new int[size];

	tablica = graf.Dijkstra_Algorithm(start);
	
	graf.show();

	cout << "Poprzedniki: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " " << tablica[i] << endl;
	}

	cout << "Path from " << start << " to " << end << "; ";
	graf.printPath(tablica, end);


	return 0;
}
