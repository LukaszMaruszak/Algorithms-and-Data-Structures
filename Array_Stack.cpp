//Author: Łukasz Maruszak﻿
#include <iostream>

using namespace std;

const int maxlength = 50;
typedef int elementtype;
typedef int position;

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


int main()
{
	Stos stos = Stos();
	cout << "Czy stos pusty " << stos.Empty() << endl;
	cout << "Dodaje 5 na stos." << endl;
	stos.Push(5);
	cout << "Element na szczycie stosu " << stos.TopElem() << endl;
	cout << "Czy stos pusty " << stos.Empty() << endl;
	cout << "Zdejmuje element ze stosu." << endl;
	stos.Pop();
	cout << "Czy stos pusty " << stos.Empty() << endl;
	cout << "Dodaje 2 na stos." << endl;
	stos.Push(2);
	cout << "Dodaje 3 na stos." << endl;
	stos.Push(3);
	cout << "Element na szczycie stosu " << stos.TopElem() << endl;
	cout << "Czyszcze stos." << endl;
	stos.Makenull();
	cout << "Czy stos pusty " << stos.Empty() << endl;
	return 0;

}

