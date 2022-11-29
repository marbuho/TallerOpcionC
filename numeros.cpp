#include <bits/stdc++.h>
using namespace std;

vector<int> PRIMOS;

void criba(int n)
{
    bool nprimos[n + 1];
	// a priori, se coloca todos en true (true->es primo, false->no lo es)
    memset(cprimos, true, sizeof(cprimos));
	cprimos[0] = false;
	cprimos[1] = false;
	
	//se requiere iterar hasta que el cuadrado del siguiente número confirmado
	//como primo es mayor que n.
	//equivale a decir que alcanza con calcular entre 2 y sqrt(n)
    for (int p = 2; p * p <= n; p++) {
        //se toma el primer número no rayado ni marcado, como número primo.
		//el 2 se marco true al iniciar
        if (cprime[p] == true) {
            //se tachan todos los múltiplos del número que se acaba de indicar como primo.
            for (int i = p * p; i <= n; i += p)
                cprime[i] = false;
        }
    }
	//Agergo los primos, segun lo que indica la criba boolean
	  for (int i = 0; i <= n; i++){
		  if (cprime[i]){
			  PRIMOS.push_back(i);
		  }
	  }
}
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
// calcular cantidad de divisores de un numero N
// usar la propiedad
//Si un número N = a ^i * b^j * … * c^k,
//entonces N tiene (i+1) *(j+1)* … *(k+1) divisores.

long long cantDiv(long long N){
	// se requiere tener en una var global los primos entre 2 y el N
 long long pf_ind=0,
 long long pf = PRIMOS[pf_ind],
 long long resp = 1;
 while(pf * pf <= N) {
	long long potencia = 0;
	while(N % pf == 0){
		N = N / pf;
		potencia++;
	}
	resp = resp * (potencia +1);
	pf = primos[++pf_ind];
 }
 if(N != 1) resp *= 2;
 
 return resp;
}

 
// Driver Code
int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}