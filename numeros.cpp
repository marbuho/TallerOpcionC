#include <bits/stdc++.h>
using namespace std;

vector<long int> PRIMOS;

void criba(long int n){
	
	// guarda en la variable gloabl PRIMOS, los numeros primos entre 2 y name
    bool cprimos[n + 1]; // un array para la criba de primos, a priori, se coloca
	// todos en true (true->es primo, false->no lo es)
	if (n == 1) 
    memset(cprimos, true, sizeof(cprimos));
	cprimos[0] = false;
	cprimos[1] = false;
	if (n == 1) return;
	//se requiere iterar hasta que el cuadrado del siguiente número confirmado
	//como primo es mayor que n.
	//equivale a decir que alcanza con calcular entre 2 y sqrt(n)
    for (long int p = 2; p * p <= n; p++) {
        //se toma el primer número no rayado ni marcado, como número primo.
		//el 2 se marco true al iniciar
        if (cprimos[p]) {
            //se tachan todos los múltiplos del número que se acaba de indicar como primo.
            for (long int i = p * p; i <= n; i = i + p){
                cprimos[i] = false;
			}	
        }
    }
	//Agergo los primos, segun lo que indica la criba boolean
	for (long int i = 0; i <= n; i++){
	  if (cprimos[i]){
		  PRIMOS.push_back(i);
	  }
	}
	
}
    


// calcula la cantidad de divisores de un numero N
// usar la igualdad:
//dada la factorización entero N = a ^i * b^j * … * c^k,
//entonces N tiene (i+1) *(j+1)* … *(k+1) divisores.

int CantDiv(int N){
// se requiere tener en un arreglo global los primos entre 2 y el N
	int uno = 1;
	if (N == 1) return uno;
	int cantdiv = 1; // a priori tiene un divisor (1)
	int pf_indx=0; // indice del primer primo
	int pf = PRIMOS[pf_indx]; //primer primo(=2)
	while(pf * pf <= N) {
		int exponente = 0;
		while(N % pf == 0){ // si lo divide exacto es un factor primo
			N = N / pf; // lo divido por ese factor primo
			exponente++; // sumo 1 al exponente
		}
		cantdiv = cantdiv * (exponente +1);  // divisores = (exp_f1+1) *(exp_f2+1)* … *(exp_fk+1)
		pf_indx++;
		pf = PRIMOS[pf_indx]; // tomo el sig primo, (antes muevo el index ++pf_index)
	}
	if(N != 1) cantdiv *= 2;

	return cantdiv;
}

 
// Driver Code
int main()
{
    long int n = 1;
	long int pri;
    cout << "Primos menor o igual a  " << n << endl;

    criba(n);
	
	// Print el vector de primos
    for (long int p = 0; p < PRIMOS.size(); p++){
        pri = PRIMOS[p];
        cout << pri << " ";
	}
	cout << "Cantidad de divisores de " << n << endl;
	cout << CantDiv(n) << endl;
	
    return 0;
}