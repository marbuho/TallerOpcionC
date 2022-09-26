#include<cstdio>
#include <bitset>
#include<iostream>
//#include <fstream> Solo para volcar la salida en un txt

using namespace std;
bool es_viernes(int dia);
bool es_sabado(int dia);
int main(){
	int TC, N, P,resul, AUX1, CANT, h, m;
//	ofstream myfile; //Solo para volcar la salida en un txt
//	myfile.open ("example.txt");

	scanf("%d", &TC); //nro de casos
	while(TC--){ //repite hasta 0
		scanf("%d", &N); // lee la cantidad de dias
		scanf("%d", &P); //lee la cant de partidos
		bitset <4000> dias; // crea un arreglo de tam CANT con bit en 0 == false;
		AUX1 = P;// una copia de P, (no es una ref)
		while (AUX1--) { // cada iteracion recorre los dias para 1 partido.
			scanf("%d", &h);
			for (int i = h;i <= N; i = i + h){
				if (dias[i] || es_viernes(i) || es_sabado(i)) continue; // Si ya se marco con una huelga o
													//si cae un viernes o sabado no hay huelgas.
				dias[i] = true; // hubo una huelga
				
			}
		}
		//calcular el resultado
		resul = dias.count(); // cuenta la cantidad de true;
//		myfile << resul << endl; //solo para volcar la salida en un txt
		printf("%d \n", resul);
	
	}
//	myfile.close();
	return 0;
}
bool es_viernes(int dia){
	if ((dia) % 7 == 6) return true;
	return false;
}
bool es_sabado(int dia){
	if ((dia) % 7 == 0) return true;
	return false;
}