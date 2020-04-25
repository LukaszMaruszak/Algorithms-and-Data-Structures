//Author: Łukasz Maruszak
#include <iostream>

using namespace std;

const int maxlength = 100;
typedef int elementtype;
typedef int position;

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

int main()
{
	Kolejka kolejka = Kolejka();
	cout << "Czy kolejka jest pusta : " << kolejka.Empty() << endl;
	cout << "Wstawiam do kolejki 5." << endl;
	kolejka.Enqueue(5);
	cout << "Czy kolejka jest pusta : " << kolejka.Empty() << endl;
	cout << "Pierwszy element w kolejce to: " << kolejka.FrontElem() << endl;
	cout << "Usuwam element z kolejki." << endl;
	kolejka.Dequeue();
	cout << "Czy kolejka jest pusta : " << kolejka.Empty() << endl;
	cout << "Wstawiam do kolejki 4." << endl;
	kolejka.Enqueue(4);
	cout << "Wstawiam do kolejki 3." << endl;
	kolejka.Enqueue(3);
	cout << "Wstawiam do kolejki 2." << endl;
	kolejka.Enqueue(2);
	cout << "Pierwszy element w kolejce to: " << kolejka.FrontElem() << endl;
	cout << "Wstawiam do kolejki 1." << endl;
	kolejka.Enqueue(1);
	cout << "Pierwszy element w kolejce to: " << kolejka.FrontElem() << endl;
	cout << "Usuwam element z kolejki." << endl;
	kolejka.Dequeue();
	cout << "Pierwszy element w kolejce to: " << kolejka.FrontElem() << endl;
	cout << "Wstawiam do kolejki 6." << endl;
	kolejka.Enqueue(6);
	cout << "Pierwszy element w kolejce to: " << kolejka.FrontElem() << endl;
	cout << "Usuwam element z kolejki." << endl;
	kolejka.Dequeue();
	cout << "Usuwam element z kolejki." << endl;
	kolejka.Dequeue();
	cout << "Pierwszy element w kolejce to: " << kolejka.FrontElem() << endl;
	cout << "Czyszcze kolejke." << endl;
	kolejka.Makenull();
	cout << "Czy kolejka jest pusta: " << kolejka.Empty() << endl;


	return 0;
}

