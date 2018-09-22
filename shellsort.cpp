#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#define TAM 10
using namespace std;

void shellsort(int *&v, int tam){
    int j, h = 1;
    while(h < tam/3)
        h = 3*h+1;
    while(h >= 1){
        for (int i = h; i < tam; i++){
            j=i;
            while((j>=h) && (v[j] <  v[j-h])){
                swap(v[j], v[j-h]);
                j=j-h;
            }
        }
        h=h/3;
    }
}

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void startV(int *v){
//    srand(time(NULL));
    for(int i = 1; i < TAM; i++)
        v[i] = rand()%101;
}

void showV(int *v){
    for(int i = 0; i < TAM; i++)
        printf("%3d", v[i]);
    cout << endl;
}

void areSort(int *v){
    bool sort = true;
    for(int i = 1; i < TAM-1; i++){
        if(v[i] > v[i+1])
            sort = false;
    }
    cout << "Ordenado?: " << (sort?"Sim":"Nao") << endl;
}

int main(int argc, char const *argv[]) {
    /* code */
    int *v = new int [TAM];
    srand(time(NULL));
    startV(v);
    showV(v);
    areSort(v);
    shellsort(v, TAM);
    showV(v);
    areSort(v);
    return 0;
}
