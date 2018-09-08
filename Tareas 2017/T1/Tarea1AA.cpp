#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#define VACIO -1

using namespace std;

struct Nodo{
    int val;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(){
        this-> val = VACIO;
        this->izquierda = NULL;
        this->derecha = NULL;
    }
};

bool specified,status;
Nodo* raiz;
int Nodos = 0, inputNodos = 0;
string path;
int Num;



void insertar(Nodo* raiz,int &key, int pos,int size){
    if(pos == size){
        if(raiz->val != VACIO) specified = false;
        raiz->val = key;
    }

    else if( path[pos] == 'L'){
        if(raiz->izquierda == NULL){
            Nodos++;
            Nodo* N= new Nodo;
            raiz->izquierda = N;
            insertar(N, key, pos+1,size);
        }
        else insertar(raiz->izquierda, key, pos+1,size);
    }
    else {
        if(raiz->derecha == NULL){
            Nodos++;
            Nodo* N = new Nodo;
            raiz->derecha = N;
            insertar(N, key, pos+1,size);
        }
        else insertar(raiz->derecha, key, pos+1,size);
    }

}

void limpiar(Nodo* raiz){
    if(raiz == NULL)return;
    limpiar(raiz->izquierda);
    limpiar(raiz->derecha);
    delete raiz;
}


void bfs(){
    unsigned t0, t1;
    t0=clock();

    queue< Nodo* > q;
    q.push(raiz);
    vector < int > ans;
    Nodo* Nodo;
    while(!q.empty()){
        Nodo = q.front();
        q.pop();
        ans.push_back(Nodo->val);
        if(Nodo->izquierda != NULL) q.push(Nodo->izquierda);
        if(Nodo->derecha != NULL) q.push(Nodo->derecha);
    }

    t1 = clock();

    for(int i = 0; i < (int)ans.size()-1; i++)
        cout << ans[i] << " ";
    cout << ans[ans.size()-1] << endl;

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Execution Time: %06lf\n",time);
}

void tipo_arbol(){
    if( specified == false || inputNodos != Nodos){
        cout << "no completo" << endl;
        status = true;
    }
    else bfs();

}
void init(){
    Num = Nodos;
    limpiar(raiz);
    raiz = new Nodo;
    Nodos = 1;
    specified = true;
    inputNodos = 0;
}

void separar(string s){
    int val;
    path = "";
    char n[100];
    int j=0,k=0;
    for(int i=0; i < (int)s.size(); i++){
        if (s[i] >= 65 && s[i] <= 90){
            path[j]=s[i];
            j++;
        }
        if (s[i] >= 48 && s[i] <= 57){
            n[k] = s[i];
            k++;
        }
    }
    val = atoi(n);
    insertar(raiz, val, 0,j);
}

int main(){
    
    string s;
    init();
    while(cin >> s){
        status = false;
        if(s == "()"){
            tipo_arbol();
            init();
            if (status == false){
                cout << "N° Nodos: "<<Num << endl;
            }
        }
        else{
            inputNodos++;
            for(int i = 0; i < (int)s.size(); i++)
                if(s[i] == '(' || s[i] == ')'|| s[i] == ',') s[i] = ' ';
            separar(s);
        }
    }

    return 0;
}
