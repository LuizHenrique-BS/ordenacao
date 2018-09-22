#include <iostream>
#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
//#include <rand>
#define TAM 10

using namespace std;

void merge(int *v,int p,int q, int r){
    int n1 = q-p+1, n2 = r-q;
    int vL[n1+2], vR[n2+2];
    for(int i = 1; i <= n1; i++)
        vL[i]= v[p+i-1];
    for(int j = 1; j <= n2; j++)
        vR[j] = v[q+j];
    vL[n1+1] = INT_MAX;
    vR[n2+1] = INT_MAX;
    int i = 1;
    int j = 1;
    for(int k = p; k <= r; k++){
        if(vL[i] <= vR[j]){
            v[k] = vL[i];
            i++;
        }
        else{
            v[k] = vR[j];
            j++;
        }
    }
}

void mergeSort(int *v, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergeSort(v, p, q);
        mergeSort(v, q+1, r);
        merge(v, p, q, r);
    }
}

void startV(int *v){
//    srand(time(NULL));
    const int NIL = -1;
    v[0] = NIL;
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
  mergeSort(v, 0, TAM-1);
  showV(v);
  areSort(v);
  return 0;
}
