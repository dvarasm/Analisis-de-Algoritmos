#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define INF 1<<30

using namespace std;

int dia[15][15];
int costo[15][15][35];
int distancia[15][1005];

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

int main(){
	int n;
	int k;
	int casos = 0;
	while (true){
		cin >> n;
		cin >> k;
		if ((n == 0) && (k == 0)){
			break;
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (i != j){
					scanf("%d", &dia[i][j]);
					//printf("dia[%d][%d] = %d\n",i,j,dia[i][j]);
					for (int d = 1; d <= dia[i][j]; ++d){
						scanf("%d", &costo[i][j][d]);
						//printf("costo[%d][%d][%d] = %d\n",i,j,d,costo[i][j][d]);
					}
				}
			}
		}

		for (int i = 0; i <= n; ++i){
			for (int d = 0; d <= k; ++d){
				distancia[i][d] = INF;
			}
		}

        	distancia[1][0] = 0;

		for (int d = 1; d <= k; ++d){
			for (int i = 1; i <= n; ++i){
				for (int j = 1; j <= n; ++j){
					if (i != j){
						int q = (d - 1) % dia[j][i] + 1;
						printf("dia[%d][%d] + 1 = %d ## q = %d ## d=%d\n",j,i,dia[j][i]+1,q,d);
						if (costo[j][i][q] && distancia[j][d - 1] != INF){
							distancia[i][d] = min(distancia[i][d], distancia[j][d - 1] + costo[j][i][q]);
							printf("distancia[%d][%d] = %d\n",i,d,distancia[i][d]);
						}
					}
				}
			}
		}
		printf("Scenario #%d\n", ++casos);
		if (distancia[n][k] != INF){
			printf("The best flight costs %d.\n\n", distancia[n][k]);
		}
		else{
			printf("No flight possible.\n\n");
		}
	}
	return 0;
}
