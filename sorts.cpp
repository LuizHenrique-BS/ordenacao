#include <iostream>
#include <ctime>
#define TAM 10
#define MAX_RAN 100
//#define RAND_MAX 2147483647
using namespace std;

void bubblesort(int item[TAM]){
	int aux = 0;
	for (int i = TAM-1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(item[j] > item[j+1]){
				aux = item[j];
				item[j] = item [j+1];
				item[j+1] = aux;
			}
		}
	}
}

void selectionsort(int vet[TAM]){
	int aux = 0;
	int min = 0;
	for (int i = 0; i < TAM; i++){
		min = i;
		for (int j = i+1; j < TAM; j++){
			if (vet[j] < vet[min]) min = j;
		}
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}
void insertionsort(int vet[TAM+1]){
	int x, j;
	for (int i = 1; i < TAM+1; i++){
		x = vet[i];
		j = i - 1;
		vet[0] = x; //sentinela
		while(x < vet[j]){
			vet[j+1] = vet[j];
			j -= 1;
		}
		vet[j+1] = x;
	}
}
//inicia o vetor com valores aleatorios
void startVet(int v[TAM]){
	for (int i = 0; i < TAM; i++){
		v[i] = rand()%(MAX_RAN);
	}
}
//mostra o vetor
void showVet(int v[TAM]){
	for (int i = 0; i < TAM; i++){
		printf("%3d", v[i]);
	}
	printf("\n");
}
//verifica se esta ordenado
void areSort(int v[TAM]){
bool sort = true;
int i = 0;
	while((sort) && (i < TAM - 1)){
		if(v[i] > v[i+1])
			sort = false;
		else{
			i++;
		}
	}
	cout << "Ordenado?: " << (sort?"Sim":"Nao") << endl;
}

int main(){
	int v[TAM];
//	int v2[TAM+1];
	srand(time(NULL));
	startVet(v);
//	startVet(v2);
	showVet(v);
//	showVet(v2);
	areSort(v);
	bubblesort(v);
//	selectionsort(v);
//	insertionsort(v2);
	showVet(v);
	areSort(v);
	return 0;
}
