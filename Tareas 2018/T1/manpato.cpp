#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream> 

using namespace std;

int main(){
	int num_adm,din_rep,num_rand1,num_rand2,m,din_rand;
	int *adm;
	int hora = time(NULL);
	  
	while(1){	

		//Primer Valor M, segundo N
		scanf("%d %d",&m,&num_adm);
		//Parar bucle ingresar 0 0
		if(m==0 && num_adm ==0)break;
	
		adm = (int*)calloc(num_adm + 2,sizeof(int)); 									
				
		srand(hora);
	
		int max;
		unsigned t0, t1;
    	t0=clock();	
	 
		for(int j = 0; j < m; j++){ 
			din_rand = rand()%1000 + 1;
			
			num_rand1 = rand()%num_adm + 1; 													
			num_rand2 = rand()%num_adm + 1;
	
			if(num_rand1 > num_rand2){
				swap(num_rand1,num_rand2);
			}
		
			int inter = num_rand2 - num_rand1;
		
			inter = inter + 1;

			if(din_rand < inter){ 
				din_rep = din_rand / din_rand;
			}
			else din_rep = din_rand / inter;

			adm[num_rand1] = adm[num_rand1] + din_rep;
			adm[num_rand2 + 1] = adm[num_rand2 + 1] + (-din_rep);
		}
		int count = 0;
		max = 0;
		for(int i = 1; i <= num_adm; i++){
			count = count + adm[i];
			adm[i] = count;
			if(adm[i]>=max){
				max = adm[i];
			}
		}
		for(int j = 1; j <= num_adm; j++){
			//	printf("adm[%d]= %d\n",j,adm[j]); //Descomentar para imprimir arreglo completo de admiradores
			if(adm[j] == max){
				printf("Admirador: %d, Dinero: %d\n", j, adm[j]);
			}
		}
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "m: "<<m<<" n: "<<num_adm<<" Tiempo de Ejecucion: " << time <<"seg"<< endl;	
	}
	free(adm);
	return 0;
}
