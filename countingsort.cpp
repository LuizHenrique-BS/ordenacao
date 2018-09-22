#include<iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

#define TAM 11
using namespace std;

void countingSort(int *&vA, int *&vB, int k, int tam){
    int *vC = new int [k+1];
    for(int i = 0; i <= k; i++)
        vC[i]=0;
    for(int j = 1; j < tam; j++)
        vC[vA[j]] = vC[vA[j]]+1;
    for (int i = 1; i <= k; i++)
        vC[i] = vC[i] + vC[i-1];
    for (int j = tam-1; j > 0; j--){
        vB[vC[vA[j]]]=vA[j];
        vC[vA[j]]=vC[vA[j]]-1;
    }
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

int max(int *v, int tam){
    int max = 0;
    for (int i = 1; i < tam; i++) {
        if(v[i] > max)
            max = v[i];
    }
    return max;
}

int main(){
    int *v = new int [TAM];
    int *v2 = new int [TAM];
    srand(time(NULL));
    startV(v);
    showV(v);
    areSort(v);
    countingSort(v,v2, max(v, TAM), TAM);
    showV(v2);
    areSort(v2);
    return 0;
}
