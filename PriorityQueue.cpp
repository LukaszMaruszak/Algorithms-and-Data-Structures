//Łukasz Maruszak
#include <iostream>

using namespace std;

struct element {
    int priorytet;
    char value;
};

class Heap
{
public:
    element nodes[100];
    int iloscelementow = 0;
public:
    void add(int x, char v);
    void print();
};

class PriorityQueue : public Heap
{

public:
    void Enqueue(int priorytet, char wartosc);
    element FindMax();
    element DequeueMax();
    void show();
    void downheap(int i);
};

void PriorityQueue::Enqueue(int priorytet, char wartosc) {
    element e;
    e.priorytet = priorytet;
    e.value = wartosc;
    add(e.priorytet, e.value);
}

element PriorityQueue::FindMax()
{  
  return nodes[0];
}

void PriorityQueue::downheap(int i) 
{
    int j = (2 * i) + 1;
    int k = (2 * i) + 2;
    if (k < iloscelementow) {
        
        if (nodes[i].priorytet < nodes[j].priorytet) {
            element p = nodes[i];
            nodes[i] = nodes[j];
            nodes[j] = p;
            downheap(j);
        }
       
        if (nodes[i].priorytet < nodes[k].priorytet) {
            element t = nodes[i];
            nodes[i] = nodes[k];
            nodes[k] = t;
            downheap(k);
        }
    }
}

element PriorityQueue::DequeueMax() 
{
    //element o njawiekszym priorytecie
    element max;
    max = nodes[0];
   
    //usuwam element o najwiekszym priorytecie czyli
    //zastepuje go ostatnim lisciem 
    int k = iloscelementow -1;
    nodes[0] = nodes[k];
    iloscelementow = iloscelementow -1;
    downheap(0);
  
    return max;
}

void Heap::add(int x, char v)
{
    int i = iloscelementow++;
    int j = (i - 1) / 2;
    while (i > 0 && x > nodes[j].priorytet)
    {
        nodes[i] = nodes[j];
        i = j;
        j = (i - 1) / 2;
    }

    nodes[i].priorytet = x;
    nodes[i].value = v;
}

void Heap::print()
{
    for (int i = 0; i < iloscelementow; i++)
    {
        cout << "( " << nodes[i].priorytet << ', ' << nodes[i].value << ' )'  << " ";
    }
}

void PriorityQueue::show()
{
    for (int i = 0; i < iloscelementow; i++)
    {
        cout << "(" << nodes[i].priorytet << ", " << nodes[i].value << ")" << " ";
    }
}

//Tablicowa implemenyacja kolejki priorytetowej

class PriorityQueueTablicowa
{
public:

    element tablica[100];
    int iloscelementowtablicy = 0;
public:
    void EnqueueNodes(int priorytet, char wartosc);
    element FindMaxNodes();
    element DequeueMaxNodes();
    void printtablica();
};

void PriorityQueueTablicowa::EnqueueNodes(int priorytet, char wartosc) {
    tablica[iloscelementowtablicy].priorytet = priorytet;
    tablica[iloscelementowtablicy].value = wartosc;
    iloscelementowtablicy++;
}

element PriorityQueueTablicowa::FindMaxNodes() {
    element max;
    max.priorytet = tablica[0].priorytet;
    max.value = tablica[0].value;

    for (int i = 0; i < iloscelementowtablicy; i++) {
       
        if (max.priorytet < tablica[i].priorytet) {
            max.priorytet = tablica[i].priorytet;
            max.value = tablica[i].value;
        }
    }
  
    return max;
}

element PriorityQueueTablicowa::DequeueMaxNodes() {
    element dqMax;
    dqMax.priorytet = tablica[0].priorytet;
    dqMax.value = tablica[0].value;
    int i;
    int j = 0;
    for (i = 0; i < iloscelementowtablicy; i++) 
    {
        if (dqMax.priorytet < tablica[i].priorytet)
        {
            dqMax.priorytet = tablica[i].priorytet;
            dqMax.value = tablica[i].value;
            j = i;
        }
    }
    
    int k = j+1;
    for (j; j < iloscelementowtablicy; j++) 
    {
        tablica[j] = tablica[k];
        k++;
    }

    iloscelementowtablicy--;
   
    return dqMax;
}

void PriorityQueueTablicowa::printtablica()
{
    for (int i = 0; i < iloscelementowtablicy; i++)
    {
        cout << "(" << tablica[i].priorytet << ", " << tablica[i].value << ")" << " ";
    }
}


int main()
{
    cout << "Implementacja PriorityQueue za pomoca BinaryHeap" << endl;
    PriorityQueue pq;
    pq.Enqueue(4, 'K');
    pq.Enqueue(1, 'A');
    pq.Enqueue(9, 'A');
    pq.Enqueue(3, 'O');
    pq.Enqueue(8, 'L');
    pq.Enqueue(5, 'A');
    pq.Enqueue(2, 'T');
    pq.Enqueue(7, 'A');
    pq.Enqueue(6, 'M');
    pq.show();
    cout << endl;
    cout << "Element max " << "(" << pq.FindMax().priorytet << ", " << pq.FindMax().value << ")" << endl;
    cout << "Element max " << "(" <<  pq.FindMax().priorytet << ", " << pq.FindMax().value << ")" << endl;
    cout << "Dequeue " << "(" << pq.DequeueMax().priorytet << ", " << pq.FindMax().value << ")" << endl;
    pq.show();
    cout << endl;
    cout << "Dequeue " << "(" << pq.DequeueMax().priorytet << ", " << pq.FindMax().value << ")" << endl;
    pq.show();
    cout << endl;
    
    
    cout << "\nTablicowa implementacja PriorityQueue " << endl;
    
    PriorityQueueTablicowa tab;
    tab.EnqueueNodes(4, 'K');
    tab.EnqueueNodes(1, 'A');
    tab.EnqueueNodes(9, 'A');
    tab.EnqueueNodes(3, 'O');
    tab.EnqueueNodes(8, 'L');
    tab.EnqueueNodes(5, 'A');
    tab.EnqueueNodes(2, 'T');
    tab.EnqueueNodes(7, 'A');
    tab.EnqueueNodes(6, 'M');
    tab.printtablica();
    cout << endl;
    cout << "Element max " << "(" << tab.FindMaxNodes().priorytet << ", " << tab.FindMaxNodes().value << ")" << endl;
    cout << "Element max " << "(" << tab.FindMaxNodes().priorytet << ", " << tab.FindMaxNodes().value << ")" << endl;
    cout << "Dequeue " << "(" << tab.DequeueMaxNodes().priorytet << ", " << tab.FindMaxNodes().value << ")" << endl;
    tab.printtablica();
    cout << endl;
    cout << "Dequeue " << "(" << tab.DequeueMaxNodes().priorytet << ", " << tab.FindMaxNodes().value << ")" << endl;
    tab.printtablica();
    cout << endl;
    
    return 0;
}
