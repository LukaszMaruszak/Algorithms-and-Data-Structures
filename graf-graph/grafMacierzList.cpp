//Autor Łukasz Maruszak
#include <locale.h>
#include <iostream>
#include <vector>

using namespace std;

class GrafNieSkierowanyMacierz {
	int* macierz;
	int liczbakrawedzi = 0;
	int rozmiar = 0;
public:
	GrafNieSkierowanyMacierz();
	~GrafNieSkierowanyMacierz();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void podajStopien();
	void podajSasiedzi();
	void show();
};



GrafNieSkierowanyMacierz::GrafNieSkierowanyMacierz() {
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	macierz = new int[rozmiar * rozmiar];
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++) macierz[i * rozmiar + j] = 0;

}

GrafNieSkierowanyMacierz::~GrafNieSkierowanyMacierz() {
	delete[] macierz;
}

void GrafNieSkierowanyMacierz::podajLiczbeKrawedzi()
{
	cout << "Podaj liczbę krawedzi: ";
	int ilosc;
	cin >> ilosc;
	liczbakrawedzi = ilosc;
}

void GrafNieSkierowanyMacierz::okreslPolaczenia()
{
	int xpoz, ypoz;
	for (int i = 0; i < liczbakrawedzi; i++)
	{
		cout << "Podaj pare wierzchołków." << endl;
		cin >> xpoz;
		cin >> ypoz;
		macierz[ypoz + rozmiar * xpoz] = 1;
		macierz[xpoz + rozmiar * ypoz] = 1;
	}
}

void GrafNieSkierowanyMacierz::podajStopien()
{
	cout << "Podaj wierzchołek aby okreslić stopień." << endl;
	int t = 0;
	int stopien = 0;
	cin >> t;
	if (t < rozmiar)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			stopien += macierz[i + rozmiar * t];
		}
	}
	cout << "Stopien wierzchołka " << t << " to " << stopien << endl;
}

void GrafNieSkierowanyMacierz::podajSasiedzi()
{
	cout << "Podaj wierzchołek aby podać sąsiadów." << endl;
	int t = 0;
	cin >> t;
	cout << "Sąsiedzi wierzchołka " << t << " ";
	if (t < rozmiar)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			if (macierz[i + rozmiar * t] == 1)
				cout << '(' << i << ')' << " ";
		}
	}
}

void GrafNieSkierowanyMacierz::show()
{
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) cout << macierz[i * rozmiar + j] << " ";
		cout << endl;
	}
}

class GrafSkierowanyMacierz {
	int* macierz;
	int liczbakrawedzi = 0;
	int rozmiar = 0;
public:
	GrafSkierowanyMacierz();
	~GrafSkierowanyMacierz();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void podajStopien();
	void podajSasiedzi();
	void jestemSasiadem();
	void show();
};


GrafSkierowanyMacierz::GrafSkierowanyMacierz() {
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	macierz = new int[rozmiar * rozmiar];
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++) macierz[i * rozmiar + j] = 0;

}

GrafSkierowanyMacierz::~GrafSkierowanyMacierz()
{
	delete[] macierz;
}

void GrafSkierowanyMacierz::podajLiczbeKrawedzi()
{
	cout << "Podaj liczbę krawedzi: ";
	int ilosc;
	cin >> ilosc;
	liczbakrawedzi = ilosc;
}

void GrafSkierowanyMacierz::okreslPolaczenia()
{
	int xpoz, ypoz;
	for (int i = 0; i < liczbakrawedzi; i++)
	{
		cout << "Podaj pare wierzchołków." << endl;
		cin >> xpoz;
		cin >> ypoz;
		macierz[ypoz + rozmiar * xpoz] = 1;
	}
}

void GrafSkierowanyMacierz::podajStopien()
{
	cout << "Podaj wierzchołek aby okreslić jego stopienie." << endl;
	int t = 0;
	int wychodzacy = 0;
	int wchodzacy = 0;
	cin >> t;
	if (t < rozmiar)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			wychodzacy += macierz[i + rozmiar * t];
			wchodzacy += macierz[t + rozmiar * i];
		}
	}
	cout << "Stopień wychodzący wierzchołka " << t << " to " << wychodzacy << endl;
	cout << "Stopień wchodzący wierzchołka " << t << " to " << wchodzacy << endl;

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
			if (macierz[i + rozmiar * t] == 1)
				cout << '(' << i << ')' << " ";
		}
	}
	cout << endl;
}

void GrafSkierowanyMacierz::jestemSasiadem()
{
	cout << "Podaj wierzchołek aby podać dla kogo jest sąsiadem." << endl;
	int t = 0;
	cin >> t;
	cout << "Wierzchołek " << t << " jest sąsiadem wierzchołka: " << " ";
	if (t < rozmiar)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			if (macierz[t + rozmiar * i] == 1)
				cout << '(' << i << ')' << " ";
		}
	}
	cout << endl;
}


void GrafSkierowanyMacierz::show()
{
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) cout << macierz[i * rozmiar + j] << " ";
		cout << endl;
	}
}

class GrafNieSkierowanyLista
{
	int liczbakrawedzi = 0;
	int rozmiar = 0;
	vector<vector<int> > w;
public:
	GrafNieSkierowanyLista();
	~GrafNieSkierowanyLista();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void podajStopien();
	void podajSasiedzi();
	void show();
};


GrafNieSkierowanyLista::GrafNieSkierowanyLista()
{
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			w.push_back(vector<int>(0));
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
		w[xpoz].push_back(ypoz);
		w[ypoz].push_back(xpoz);
	}
}

void GrafNieSkierowanyLista::podajStopien()
{
	cout << "Podaj wierzchołek aby okreslić stopień." << endl;
	int t = 0;
	int stopien = 0;
	cin >> t;
	if (t < rozmiar)
		stopien = w[t].size();
	cout << "Stopien wierzchołka " << t << " to " << stopien << endl;
}

void GrafNieSkierowanyLista::podajSasiedzi()
{
	cout << "Podaj wierzchołek aby podać sąsiadów." << endl;
	int t = 0;
	cin >> t;
	cout << "Sąsiedzi wierzchołka " << t << " ";
	if (t < rozmiar)
	{
		if (w[t].size() != 0) {
			for (int j = 0; j < w[t].size(); j++)
			{
				cout << "(" << w[t][j] << "), ";
			}
		}
		else cout << "Brak sąsiadów." << endl;
	}
}

void GrafNieSkierowanyLista::show()
{
	for (int i = 0; i < w.size(); i++) {
		if (w[i].size() == 0) continue;
		cout << "(" << i << ")" << " -> ";
		for (int j = 0; j < w[i].size(); j++) {
			cout << "(" << w[i][j] << "), ";
		}
		cout << endl;
	}
}

class GrafSkierowanyLista
{
	int liczbakrawedzi = 0;
	int rozmiar = 0;
	vector<vector<int> > w;
public:
	GrafSkierowanyLista();
	~GrafSkierowanyLista();
	void podajLiczbeKrawedzi();
	void okreslPolaczenia();
	void podajStopien();
	void podajSasiedzi();
	void jestemSasiadem();
	void show();
};


GrafSkierowanyLista::GrafSkierowanyLista()
{
	cout << "Podaj liczbe wierzcholkow: ";
	cin >> rozmiar;
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			w.push_back(vector<int>(0));
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
		w[xpoz].push_back(ypoz);
	}
}

void GrafSkierowanyLista::podajStopien()
{
	cout << "Podaj wierzchołek aby okreslić stopień." << endl;
	int t = 0;
	int wychodzacy = 0;
	int wchodzacy = 0;
	cin >> t;
	if (t < rozmiar)
	{
		for (int j = 0; j < rozmiar; j++) {
			for (int i = 0; i < w[j].size(); i++)
			{
				if (w[j][i] == t) wchodzacy += 1;
			}
		}
		wychodzacy = w[t].size();
	}
	cout << "Stopień wychodzący wierzchołka " << t << " to " << wychodzacy << endl;
	cout << "Stopień wchodzący wierzchołka " << t << " to " << wchodzacy << endl;
}

void GrafSkierowanyLista::podajSasiedzi()
{
	cout << "Podaj wierzchołek aby podać sąsiadów." << endl;
	int t = 0;
	cin >> t;
	cout << "Sąsiedzi wierzchołka: " << t << " ";
	if (t < rozmiar)
	{
		if (w[t].size() != 0) {
			for (int j = 0; j < w[t].size(); j++)
			{
				cout << "(" << w[t][j] << "), ";
			}
		}
		else cout << "Brak sąsiadów." << endl;
	}
	cout << endl;
}

void GrafSkierowanyLista::jestemSasiadem()
{
	cout << "Podaj wierzchołek aby podać dla kogo jest sąsiadem." << endl;
	int t = 0;
	cin >> t;
	cout << "Wierzchołek " << t << " jest sąsiadem wierzchołka: " << " ";
	if (t < rozmiar)
	{
		for (int j = 0; j < rozmiar; j++) {
			for (int i = 0; i < w[j].size(); i++)
			{
				if (w[j][i] == t)
					cout << '(' << j << ')' << " ";
			}
		}
	}
	cout << endl;
}
void GrafSkierowanyLista::show()
{
	for (int i = 0; i < w.size(); i++) {
		if (w[i].size() == 0) continue;
		cout << "(" << i << ")" << " -> ";
		for (int j = 0; j < w[i].size(); j++) {
			cout << "(" << w[i][j] << "), ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Polish");
	cout << "Wybierz typ grafu (1. nieskierowany, 2. skierowany)" << endl;
	int typ;
	cin >> typ;

	switch (typ)
	{
	case 1:
	{
		cout << "Wybrano graf nieskierowany. Podaj liczbe wierzchołków, krawędzi i pary wierzchołków." << endl;
		cout << "Graf implementacja tablicowa" << endl;
		GrafNieSkierowanyMacierz graf = GrafNieSkierowanyMacierz();
		graf.podajLiczbeKrawedzi();
		graf.okreslPolaczenia();
		graf.show();
		graf.podajStopien();
		graf.podajSasiedzi();

		cout << "\nGraf implementacja lista sąsiedztwa" << endl;
		GrafNieSkierowanyLista graf1 = GrafNieSkierowanyLista();
		graf1.podajLiczbeKrawedzi();
		graf1.okreslPolaczenia();
		graf1.show();
		graf1.podajStopien();
		graf1.podajSasiedzi();

		break;
	}
	case 2:
	{
		cout << "Wybrano graf skierowany. Podaj liczbe wierzchołków, krawędzi i pary wierzchołków." << endl;
		cout << "Graf implementacja tablicowa" << endl;
		GrafSkierowanyMacierz graf3 = GrafSkierowanyMacierz();
		graf3.podajLiczbeKrawedzi();
		graf3.okreslPolaczenia();
		graf3.show();
		graf3.podajStopien();
		graf3.podajSasiedzi();
		graf3.jestemSasiadem();

		cout << "\nGraf implementacja lista sąsiedztwa" << endl;
		GrafSkierowanyLista graf2 = GrafSkierowanyLista();
		graf2.podajLiczbeKrawedzi();
		graf2.okreslPolaczenia();
		graf2.show();
		graf2.podajStopien();
		graf2.podajSasiedzi();
		graf2.jestemSasiadem();
		break;
	}
	}//SWITCH

	return 0;
}