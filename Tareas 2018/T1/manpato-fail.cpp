#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream> 
#include <vector>

using namespace std;

int main(){
	int num_adm,din_rep,num_rand1,num_rand2,m,din_rand;
	int *adm, tmp = 0,k;
	int hora = time(NULL);
	srand(hora);

while(1){	

	//printf("M: ");
	scanf("%d %d",&m,&num_adm);
	//printf("N: ");
	//scanf("%d",&num_adm);

	if(m==0 && num_adm ==0)break;

	adm = (int*)calloc(num_adm + 1,sizeof(int)); 
	vector<int> max(num_adm + 1); 

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

		
		//printf("rand1: %d rand2: %d inter: %d Dinero a repartir: %d\n",num_rand1,num_rand2,inter,din_rep);
 				 	
		k = 0;
		for(int i=num_rand1; i <= num_rand2; i++){ 												
			if((din_rand - din_rep) >= 0){												
				din_rand = din_rand - din_rep;
				adm[i] = adm[i] + din_rep; 
				if(adm[i] >= tmp){
					tmp = adm[i];
					max[k]=i;
					//cout << "k: "<<k<<" i: "<<i<<endl;
					k++;
				} 										
			} 
		}
	}
	t1 = clock();
	

/*
	for(int i=0;i<=num_adm;i++)printf("adm[%d]=%d\n",i,adm[i] );
	cout << "max: " << max.size()<<endl;
*/
	for(int h=0; h < max.size(); h++){
		//printf("adm[max[%d]] = %d\n",h,adm[max[h]]);
		if(adm[max[h]] == tmp){
			cout<< "Valor Maximo: "<< tmp<<" Admirador: "<<max[h] <<endl;
			adm[max[h]] = 0;
		} 
    }
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "m: "<<m<<" n: "<<num_adm<<" Execution Time: " << time << endl;
}
    free(adm);
	return 0;

}