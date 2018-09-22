#include <iostream>
#include <time.h>

#define TAM 10
#define RAND 100
using namespace std;

int particao(int *v, int p, int r){
	int aux, x = v[p], tmp = v[r+1];
	int i = p, j = r + 1;
	v[r+1] = x;
	while(true){
		do{
			i++;
		}while(v[i] < x);
		do{
			j--;
		}while(v[j] > x);
		if(i < j){
			swap(v[i], v[j]);
		}
		else{
			swap(v[j], v[p]);
			v[r+1] = tmp;
			break;
		}
	}
	return j;
}

void quicksort(int *v, int p, int r){
	if(p < r){
		int q;
		q = particao(v, p, r);
		quicksort(v, p, q-1);
		quicksort(v, q+1, r);
	}
}

void startV(int *v){
	for(int i = 0; i < TAM; i++)
		v[i] = rand()%(RAND);
}

void showV(int *v){
	for(int i = 0; i < TAM; i++)
		printf("%3d", v[i]);
	cout << endl;
}

void swap(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int *v = new int [TAM];
	srand(time(NULL));
	startV(v);
	showV(v);
	quicksort(v, 0, TAM-1);
	showV(v);
	return 0;
}
