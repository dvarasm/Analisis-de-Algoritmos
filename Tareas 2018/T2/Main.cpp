#include "PQHeap.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
	int hora = time(NULL);
	srand(hora);
	unsigned t0, t1;
	int n,r;
	PQHeap *heap = new PQHeap();
	cout<< "Numero de inserciones"<<endl;
	cin >> n;
	
	t0=clock();

	for(int i=0; i<n; i++){
		r = rand()%n;
		heap->push(r);
	}

	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	
	printf("Tiempo de Ejecucion: %06lfseg\n",time);
	printf("size= %d top= %d\n",heap->size(),heap->top());
	//heap->solucion();
return 0;
}
