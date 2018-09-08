#include <iostream>
#include <vector>
#include <cstdio>

typedef struct{ 
	int Li;
	int Ri;
}segmento; 

using namespace std;

int main(){

int M,tmp;
cout << "M: ";
cin >> M;
cout <<"N° segmentos: ";
cin >> tmp;
cout <<"segmentos: "<< endl;

vector<segmento> S(tmp);
vector<segmento> O;

for(int i=0; i < S.size(); i++){
	scanf("%d %d",&S[i].Li,&S[i].Ri);
}

unsigned t0, t1;
t0=clock();

int s=0;
while (s < M) {
	int max=0;
	int j= -1;
	for (int i=0; i< S.size();i++) {
		if (S[i].Li <= s && S[i].Ri >= max) {
			max = S[i].Ri;
			j=i;
		}
	}
	O.push_back(S[j]);	
	s = S[j].Ri;
	S.erase(S.begin()+j);
}
t1 = clock();
double time = (double(t1-t0)/CLOCKS_PER_SEC);
printf("Execution Time: %06lf\n",time); 

cout <<"Segmentos min [0,"<<M<<"]: "<<O.size() << endl;
for(int i=0; i < O.size(); i++){
	cout <<"("<<O[i].Li<<","<<O[i].Ri<<")";
}
cout <<endl;

return 0;
}
