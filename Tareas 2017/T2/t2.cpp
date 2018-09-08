#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define INF 1<<30 ////// Valor Gigante que sirve de Infinito

using namespace std;

//////////// Variables que almacenan el imput//////////

int dia[11][11];
int costo_vuelo[11][11][31];
int costo_min[11][1001];

int main(){
	int n;
	int k;
	while (true){

		////////// Guardar Imput /////////

		cin >> n; // 2<= n <=10
		cin >> k; // 1<= k <= 1000
		if ((n == 0) && (k == 0)){
			break;
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i != j){
					cin >> dia[i][j];
					for (int d = 1; d <= dia[i][j]; ++d){
						cin >> costo_vuelo[i][j][d];
					}
				}
			}

		}

		///////////////////////////////////

		////// Inicializar Matriz Costo Minimo en Infinito

		for (int i = 0; i <= n; ++i){
			for (int dia = 0; dia <= k; ++dia){
				costo_min[i][dia] = INF;
			}
		}
	
		////// Costo de llegar de la Ciudad 1 a si misma es 0 		
	
        	costo_min[1][0] = 0;
		
		unsigned t0, t1;
		t0=clock();
		
		///////////// Algoritmo Bellman Ford ///////////////
		
		for (int d = 1; d <= k; ++d){
			
			for (int i = 1; i <= n; ++i){
				for (int j = 1; j <= n; ++j){
					if (i != j){
						int q = (d - 1) % dia[j][i] + 1;
						if (costo_vuelo[j][i][q] && costo_min[j][d - 1] != INF){
							if(costo_min[i][d] > costo_min[j][d - 1] + costo_vuelo[j][i][q]){
								costo_min[i][d] = costo_min[j][d - 1] + costo_vuelo[j][i][q];
							}
						}
					}
				}
			}
		}
		////////////////////////////////////////////////////
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		printf("Execution Time: %06lf\n",time);


		////////////// Impresion Resultados

		if (costo_min[n][k] != INF){
			printf("Costo Minimo para Llegar: %d.\n\n", costo_min[n][k]);
		}
		else{
			printf("No hay Forma de Llegar.\n\n");
		}
	}
	return 0;
}
