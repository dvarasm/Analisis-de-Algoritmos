#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kadane(int* arr, int* inicio, int* final, int n){

    int sum = 0, maxSum = 0, i;
    *final = -1; // Solo un valor inicial para verificar todos los valores negativos 
    int local_inicio = 0; //variable local
 
    for (i = 0; i < n; ++i){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
            local_inicio = i+1;
        }
        else if (sum > maxSum){
            maxSum = sum;
            *inicio = local_inicio;
            *final = i;
        }
    }

    if (*final != -1){ // Hay al menos un número no negativo
        return maxSum;
    }
 
    // Caso especial: Cuando todos los números en arr[] son negativos
    maxSum = arr[0];
    *inicio = *final = 0;
 
    for (i = 1; i < n; i++){ // Encuentra el elemento máximo en la matriz
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *inicio = *final = i;
        }
    }
    return maxSum;
} 

int main(){
	int hora = time(NULL);
	
while(1){
	srand(hora);

	int FILA;
	int COL;

	printf("Matriz:\n");
	printf("Fila: ");
	scanf("%d", &FILA);
	printf("Columna: ");
	scanf("%d",&COL);
	printf("Fila: %d Columna: %d\n",FILA,COL);
	if(FILA == 0 && COL == 0) break;

    int **M;
	int i,j;

	// inicializar matriz dinamicamente
	M = (int**)malloc(FILA*sizeof(int*)); 
	for(i=0;i<FILA; i++) {
		M[i] = (int*)malloc(COL*sizeof(int));
	}

	int n = 10000;
	int m = 20001;

	//printf("---Matriz---\n");
	for(i=0; i<FILA; i++){
		//printf("|");
		for(j=0; j< COL; j++){
			M[i][j] = (rand()%m)-n;
			//printf("%d ",M[i][j]);
		}
		//printf("|\n");
	}
	unsigned t0, t1;
	int maxSum = 0, finalizq, finalder, finalArriba, finalAbajo;
 
    int izq, der;
    int *temp;
    int sum, inicio, final;
 
    t0=clock();

    for (izq = 0; izq < COL; ++izq){ 
        temp = (int*)calloc(FILA,sizeof(int)); // Inicializa todos los elementos de tem en 0
        for (der = izq; der < COL; ++der){
            for (i = 0; i < FILA; ++i){ // Calcula la suma entre la izquierda y la derecha actual para cada fila 'i'
                temp[i] += M[i][der];        
            }
            
            sum = kadane(temp, &inicio, &final, FILA);
 
            // Compara sum con la suma máxima hasta el momento. 
            if (sum > maxSum){
                maxSum = sum;
                finalizq = izq;
                finalder = der;
                finalArriba = inicio;
                finalAbajo = final;
            }
        }
    }
 	t1=clock();
 	double time = ((double)(t1-t0)/CLOCKS_PER_SEC);

    //Resultados
    //printf("(Arriba, izq) (%d, %d)\n", finalArriba, finalizq);
    //printf("(Abajo, der) (%d, %d)\n", finalAbajo, finalder);
    printf("Max sum is: %d\n", maxSum);
    printf("Tiempo de Ejecucion: %06lfseg\n",time);
}
 return 0;
}