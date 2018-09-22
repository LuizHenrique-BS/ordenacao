#include <iostream>
#include <time.h>

#define TAM 11

using namespace std;

int pai(int i){
    return i/2;
}

int esq(int i){
    return 2*i;
}

int dir(int i){
    return 2*i+1;
}

void troca(int *a, int *b){
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void inicializaV(int *v){
//    srand(time(NULL));
    for(int i = 1; i < TAM; i++)
        v[i] = rand()%101;
}

void mostraV(int *v){
    for(int i = 0; i < TAM; i++)
        printf("%3d", v[i]);
    cout << endl;
}

void heapFica(int *v, int i, int tamHeap){
    int l = esq(i);
    int r = dir(i);
    int maior;
    if((l <= tamHeap) && v[l] > v[i])
        maior = l;
    else
        maior = i;
    if((r <= tamHeap) && (v[r] > v[maior]))
        maior = r;
    if(maior != i){
        troca(v[i], v[maior]);
        heapFica(v, maior);
    }
}

void constroiHeap(int *v, int tamHeap, int tam){
    tamHeap = tam-1;
    for (int i = tam/2; i >= 1; i--)
        heapFica(v, i, tamHeap);
}

void heapSort(int *v, int tam){
    int tamHeap = 0;
    constroiHeap(v, tamHeap, tam);
    for(int i = tam; i >= 2; i--){
        troca(v[1], v[i]);
        tamHeap -= 1;
        heapFica(v, 1, tam);
    }
}

void ordenado(int *v){
    bool sort = true;
    for(int i = 1; i < TAM-1; i++){
        if(v[i] > v[i+1])
            sort = false;
    }
    cout << "Ordenado?: " << (sort?"Sim":"Nao") << endl;
}

int main(){
    int *v = new [TAM];
    inicializaV(v);
    mostraV(v);
    ordenado(v);
    heapSort(v);

    return 0;
}
