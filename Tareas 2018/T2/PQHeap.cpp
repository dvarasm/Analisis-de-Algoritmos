#include "PQHeap.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

PQHeap::PQHeap(){
	num =10;
	a= (int *)malloc(num*sizeof(int));
	index=1;
	count=0;
}

bool PQHeap::empty(){
	if(count==0)return true;
	else return false;
}
int PQHeap::size(){
	return count;
}
int PQHeap::top(){
	if(count!=0)return a[1];
}
void PQHeap::push(int n){
	if(index >= num-1){
        	int tmp = num;
        	num = tmp*2;
        	a = (int *)realloc(a,num*sizeof(int));
	}
	a[index]=n;
	//UpHeap
	int tmp = index;
	while(tmp > 1 && a[tmp]< a[tmp/2]){ 
		swap(a[tmp], a[tmp/2]);
		tmp =tmp/2;
	}		
    	index++;
	count++;
}
void PQHeap::solucion(){
	for(int i=1; i<=count; i++)
		printf("a[%d]= %d\n",i,a[i]);
}

PQHeap::~PQHeap(){
	free(a);
}
