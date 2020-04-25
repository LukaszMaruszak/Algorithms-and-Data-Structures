//Author Łukasz Maruszak
#include <iostream>

using namespace std;

const int rozmiarZbioru = 10;

class Zbior {
public:
    bool zbior[rozmiarZbioru];

public:
    Zbior();

    void wstaw(int x);
    void usun(int x);
    bool sprawdzCzyNalezy(int x);
    void print();

};
//Zbior SumaZbiorow(Zbior const& s, Zbior const& t);

Zbior::Zbior() {
    for (int i = 0; i < rozmiarZbioru; i++) zbior[i] = false;
}


void Zbior::wstaw(int x) {
    if (x < rozmiarZbioru ) zbior[x] = true;
    else cout << "Przekroczyles rozmiar zbioru ";
}

void Zbior::usun(int x) {
    zbior[x] = false;
}

bool Zbior::sprawdzCzyNalezy(int x) {

    if (zbior[x] == true) return true;

}

void Zbior::print() {
    for (int i = 0; i < rozmiarZbioru; i++) {
        if (zbior[i] == true) cout << i << " ";
    }
    cout << "\n";
}

Zbior SumaZbiorow(Zbior const& s, Zbior const& t) {
    Zbior suma;
    for (int i = 0; i < rozmiarZbioru; i++) {
        suma.zbior[i] = s.zbior[i] || t.zbior[i];
    }
    return suma;
}

Zbior PrzeciecieZbiorow(Zbior const& s, Zbior const& t) {
    Zbior przeciecie;
    for (int i = 0; i < rozmiarZbioru; i++) {
        if (s.zbior[i] == true && t.zbior[i] == true) przeciecie.zbior[i] = true;
    }

    return przeciecie;
}

Zbior RoznicaZbiorow(Zbior const& s, Zbior const& t){
Zbior roznica;
for(int i = 0; i < rozmiarZbioru; i++){
    roznica.zbior[i] = s.zbior[i];
    if (s.zbior[i] == true && t.zbior[i] == true) roznica.zbior[i] = false;
    }
return roznica;
}

int main()
{
    Zbior A;
    Zbior B;
    Zbior C;
    Zbior D;
    Zbior E;

    A.wstaw(2);
    A.wstaw(8);
    A.wstaw(1);
    A.print();
    B.wstaw(3);
    B.wstaw(2);
    B.print();
    cout << "suma zbiorow " << endl; 
   C = SumaZbiorow(A, B);
   C.print();
   cout << "przeciecie zbiorow " << endl;
    D = PrzeciecieZbiorow(A, B);
    D.print();
    cout << "roznica zbiorow" << endl;
    E = RoznicaZbiorow(A, B);
    E.print();
    
    return 0;
}