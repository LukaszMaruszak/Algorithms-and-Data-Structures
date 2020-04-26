//Author Łukasz Maruszak
#include <iostream>
#include<vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Node
{
	int nodeNumber;
public:
	Node();
	Node(int value) : nodeNumber(value) {}
	int getNode() {
		return nodeNumber;
	}
};

class Edge
{
	Node node1;
	Node node2;
public:
	Edge(Node _node1, Node _node2) : node1(_node1), node2(_node2) {}
	void showEdge() {
		cout << node1.getNode() << " " << node2.getNode() << endl;
	}
	int GetNode1() {
		return node1.getNode();
	}
	int GetNode2() {
		return node2.getNode();
	}
};

class Graph
{
protected:
	vector<Node> nodes;
	vector<Edge> edges;
public:
	void addNode(int nodeNumber);
	void addEdge(int nodeNumber1, int nodeNumber2);
	virtual vector<int> getNeighbours(int nodeNumber) = 0;
};

void Graph::addNode(int nodeNumber)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].getNode() == nodeNumber) {
			cout << "Taki wierzcholek juz istnieje" << endl;
			nodes.erase(nodes.begin() + i);
		}

	}
	Node newNode = Node(nodeNumber);
	nodes.push_back(newNode);
}

void Graph::addEdge(int nodeNumber1, int nodeNumber2)
{
	Node node1 = Node(nodeNumber1);
	Node node2 = Node(nodeNumber2);
	Edge newEdge = Edge(node1, node2);
	edges.push_back(newEdge);

}

class UndirectedGraph : public Graph
{
public:
	int getDegree(int nodeNumber);
	vector<int> getNeighbours(int nodeNumber);
};

int UndirectedGraph::getDegree(int nodeNumber)
{
	int stopien = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].GetNode1() == nodeNumber) stopien++;
		if (edges[i].GetNode2() == nodeNumber) stopien++;
	}
	return stopien;
}

vector<int> UndirectedGraph::getNeighbours(int nodeNumber)
{
	vector<int> w;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].GetNode1() == nodeNumber) w.push_back(edges[i].GetNode2());
		if (edges[i].GetNode2() == nodeNumber) w.push_back(edges[i].GetNode1());
	}
	return w;
}

class DirectedGraph : public Graph
{
public:
	int getIndegree(int nodeNumber);
	int getOutdegree(int nodeNumber);
	vector<int> getIsNeighbour(int nodeNumber);
	vector<int> getNeighbours(int nodeNumber);
};

int DirectedGraph::getIndegree(int nodeNumber)
{
	int stopien = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].GetNode2() == nodeNumber) stopien++;
	}
	return stopien;
}

int DirectedGraph::getOutdegree(int nodeNumber)
{
	int stopien = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].GetNode1() == nodeNumber) stopien++;
	}
	return stopien;
}

vector<int> DirectedGraph::getIsNeighbour(int nodeNumber)
{
	vector<int> w;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].GetNode2() == nodeNumber) w.push_back(edges[i].GetNode1());
	}
	return w;
}

vector<int> DirectedGraph::getNeighbours(int nodeNumber)
{
	vector<int> w;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].GetNode1() == nodeNumber) w.push_back(edges[i].GetNode2());
	}
	return w;
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

		UndirectedGraph graf;

		cout << "Podaj ilość wierzchołków: ";
		int ilosc;
		cin >> ilosc;
		for (int i = 0; i < ilosc; i++)
		{
			cout << "Podaj wierzchołek" << endl;
			int nazwa;
			cin >> nazwa;
			graf.addNode(nazwa);
		}
		cout << "Podaj ilość krawędzi: ";
		int ilosck;
		cin >> ilosck;
		for (int i = 0; i < ilosck; i++)
		{
			cout << "Podaj poczatek i koniec krawedzi." << endl;
			int pocz, kon;
			cin >> pocz;
			cin >> kon;
			graf.addEdge(pocz, kon);
		}
		cout << "Stopień wierzchołka: ";
		int w;
		cin >> w;
		cout << "To " << graf.getDegree(w);
		break;
	}
	case 2:
	{
		cout << "Wybrano graf skierowany. Podaj liczbe wierzchołków, krawędzi i pary wierzchołków." << endl;
		DirectedGraph graf1;

		cout << "Podaj ilość wierzchołków: ";
		int ilosc;
		cin >> ilosc;
		for (int i = 0; i < ilosc; i++)
		{
			cout << "Podaj wierzchołek" << endl;
			int nazwa;
			cin >> nazwa;
			graf1.addNode(nazwa);
		}
		cout << "Podaj ilość krawędzi: ";
		int ilosck;
		cin >> ilosck;
		for (int i = 0; i < ilosck; i++)
		{
			cout << "Podaj poczatek i koniec krawedzi." << endl;
			int pocz, kon;
			cin >> pocz;
			cin >> kon;
			graf1.addEdge(pocz, kon);
		}
		cout << "Stopień wchodzący wierzchołka: ";
		int w;
		cin >> w;
		cout << "To " << graf1.getIndegree(w) << endl;

		cout << "Stopień wychodzący wierzchołka: ";
		int wy;
		cin >> wy;
		cout << "To " << graf1.getOutdegree(wy) << endl;

		cout << "Lista sąsiadów wierzchołka: ";
		int s;
		cin >> s;
		vector<int> sasiedzi = graf1.getNeighbours(s);
		for (int i = 0; i < sasiedzi.size(); i++)
		{
			cout << sasiedzi[i] << " ";
		}

		cout << "\nLista wierzchołków dla których jest sąsiadem: ";
		int wierzcholek;
		cin >> wierzcholek;
		vector<int> sasiedziw = graf1.getIsNeighbour(w);
		for (int i = 0; i < sasiedziw.size(); i++)
		{
			cout << sasiedziw[i] << " ";
		}



		break;
	}
	}//SWITCH
}

