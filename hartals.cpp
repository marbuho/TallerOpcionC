#include<cstdio>
#include <bitset>
#include<iostream>
using namespace std;
bool es_viernes(int dia);
int main(){
	int TC, N, P,resul, AUX1, CANT, h, m;
	scanf("%d", &TC); //nro de casos

	while(TC--){ //repite hasta 0
		scanf("%d", &N); // lee la cantidad de dias
		scanf("%d", &P); //lee la cant de partidos
		bitset <3000> dias; // crea un arreglo de tam CANT con bit en 0 == false;
		AUX1 = P;// una copia de P, (no es una ref)
		while (AUX1--) { // cada iteracion recorre los dias para 1 partido.
			scanf("%d", &h);
			for (int i = h;i <= N; i = i + h){
				if (dias[i] || es_viernes(i)) continue; // Si ya se marco con una huelga o
													//si cae un viernes (multiplo de 6) no hay huelgas.
				dias[i] = true; // hubo una huelga
				
			}
		}
		//calcular el resultado
		resul = dias.count(); // cuenta la cantidad de true;
		printf("%d \n", resul);
	
	}
	
	return 0;
}
bool es_viernes(int dia){
	if ((dia + 1) % 7 == 0) return true;
	return false;
}