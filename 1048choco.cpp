/*Sample Input
2
5 2
3 2 3 4
4 5 2 3 1
6 1
4 5 6 7 8

Sample Output
4
0*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC, K, B, N, b;
	long long int acum_r, resul;
	scanf("%d", &TC); //nro de casos
	while(TC--){
		scanf("%d%d", &N, &B); //nro de personas y cajas
		resul = 0;
		while (B--){
			scanf("%d", &K);
			acum_r = 1;
			// acumulo el resto , y se utiliza la propiedad:
			// (A*B)%C = (A%C * B%C) %C
			while (K--) {
				scanf("%d", &b); 
				acum_r = acum_r * b;
				acum_r = acum_r % N;
			}
			
			resul = resul + acum_r; // acumulo y sigo caja la sig caja
			resul = resul % N;		// el % C "de afuera"				
		}
		printf("%d\n", resul);
	}
}
