/*Sample Input
3
6241
8191
0 (no procesar)

Sample Output
no
yes
no*/

#include <bits/stdc++.h>
using namespace std;

vector<long long int> PRIMOS;

void criba(long long int n){
	// guarda en la variable gloabl PRIMOS, los numeros primos entre 2 y n
    bool cprimos[n + 1]; // un array para la criba de primos, a priori, se coloca
	// todos en true (true->es primo, false->no lo es)
	//cout << "criba boolean linea 21" <<endl;
    memset(cprimos, true, sizeof(cprimos));
	cprimos[0] = false;
	cprimos[1] = false;
	//se requiere iterar hasta que el cuadrado del siguiente número confirmado
	//como primo es mayor que n.
	//equivale a decir que alcanza con calcular entre 2 y sqrt(n)
    for (long long int p = 2; p * p <= n; p++) {
        //se toma el primer número no rayado ni marcado, como número primo.
		//el 2 se marco true al iniciar
        if (cprimos[p]) {
			//cout << "loop linea 32" <<endl;
            //se tachan todos los múltiplos del número que se acaba de indicar como primo.
            for (long long int i = p * p; i <= n; i = i + p){
                cprimos[i] = false;
			}	
        }
    }
	//Agrego los primos, segun lo que indica la criba booleana
	for (long long int i = 0; i <= n; i++){
	  if (cprimos[i]){
		  PRIMOS.push_back(i);
		  //cout << "loop linea 43" <<endl;
	  }
	}
	
}
    
// calcula la cantidad de divisores de un numero N
// usar la igualdad:
//dada la factorización entero N = a ^i * b^j * … * c^k,
//entonces N tiene (i+1) *(j+1)* … *(k+1) divisores.

long long int CantDiv(long long int N){
// se requiere tener en un arreglo global los primos entre 2 y el N
	long long int cantdiv = 1; // a priori tiene un divisor (1)
	long long int pf_indx=0; // indice del primer primo
	long long int pf = PRIMOS[pf_indx]; //primer primo(=2)
	while(pf * pf <= N) {
		//cout << "loop linea 60" <<endl;
		long long int exponente = 0;
		while(N % pf == 0){ // si lo divide exacto es un factor primo
			N = N / pf; // lo divido por ese factor primo
			//cout << "loop linea 64" <<endl;
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
{	ofstream myfile;
 	myfile.open ("salida5.txt");
	
    long long int n ;
	long long int pri;
	long long int res;
	
    cin >> n; // leer entrada
	while (n != 0){
		if (n == 1){cout << "yes" <<endl;
		myfile << "yes" <<endl;}
		else{
			criba(n); // inicializa la criba, que calcula  los primos menores a n
			res = CantDiv(n); // calculo cantidad de divisores 
			
			if(res % 2 == 0){ // si se toco un numero par de veces quedó apagada
				cout << "no" <<endl;
				myfile << "no" <<endl;
			}
			else{// si se toco un numero impar de veces quedó encendida
				cout << "yes" <<endl;
				myfile << "yes" <<endl;
			}
			PRIMOS.clear();
		}
		cin >> n;
	}
	
    return 0;
}