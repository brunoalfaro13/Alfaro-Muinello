#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;


void llenar(int* cant, int N) {
    for (int i = 0; i < N; i++) {
        int placa;
        cin >> placa;       
        cant[placa]++;      
    }
}
int armarMitad(int* cant, int * izq, int & medio){
int tamIzq = 0;
for (int v = 1000; v >= 0; v--) {
      int pares = cant[v] / 2;
        for (int k = 0; k < pares; k++) {
            izq[tamIzq] = v;
            tamIzq++;
        }  
           if (cant[v] % 2 == 1 && medio == -1) {
            medio = v;
        }
    }
    return tamIzq;   
}
void imprimir(int* izq, int tamIzq, int medio){
    for(int i = 0; i<tamIzq;i++){
       cout << izq[i] << " ";      
    }
    if (medio != -1) {
        cout << medio;
        if (tamIzq > 0) {         
            cout << " ";
        }
    }
     for (int i = tamIzq - 1; i >= 0; i--) {
        cout << izq[i];
        if (i > 0) {
            cout << " ";
        }
    }

    cout << endl;
}

int main()
{
      int N;
    cin >> N;                     

    int cant[1001] = {0};          
    int* izq = new int[N];        
    int medio = -1;               

    llenar(cant, N);                             
    int tamIzq = armarMitad(cant, izq, medio);    
    imprimir(izq, tamIzq, medio);                 
              
}