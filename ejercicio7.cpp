#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

void orden(int* a, int* aux, int ini, int medio, int fin) {
    int i = ini;            
    int j = medio + 1;      
    int k = ini;            

    while (i <= medio && j <= fin) {    
        if (a[i] <= a[j]) {            
            aux[k] = a[i];
            i++;
        } else {                        
            aux[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= medio) {                
        aux[k] = a[i];
        i++;
        k++;
    }
    while (j <= fin) {                  
        aux[k] = a[j];
        j++;
        k++;
    }
    for (k = ini; k <= fin; k++) {      
        a[k] = aux[k];
    }
}


long long checkEnfrentamientos(int* a, int ini, int medio, int fin) {
    long long rems = 0;
    int j = medio + 1; 
    int h = 0;                      
    for (int i = ini; i <= medio; i++) {   
        while (j <= fin && a[i] > 2 * a[j]) {                       
            j++;
            h++;
        }
        rems += h;                      
    }
    return rems;
}

long long divYconq(int* a, int* aux, int ini, int fin) {
    if (ini == fin) {                                           
     return 0;
    }
    int medio = (ini + fin) / 2;                                
    long long izq = divYconq(a, aux, ini, medio);         
    long long der = divYconq(a, aux, medio + 1, fin);     
    long long rems = checkEnfrentamientos(a, ini, medio, fin);        
    orden(a, aux, ini, medio, fin);                           
    return izq + der + rems;
}
int main(){
    int N;
    cin >> N;
    int* a = new int[N];
    int* aux = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << divYconq(a, aux, 0, N - 1) << endl;
}