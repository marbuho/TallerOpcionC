#include <bits/stdc++.h>
using namespace std;
int main(){
// el  problema consiste en averiguar cuantos divisores tiene el n que representa la última lampara,
// si tiene par factores, la luz queda apagada (la prende y apaga)
// si tiene impar factores, la luz queda prendida (la prende, la apaga y la prende)
// truco:
// casi todos los enteros tienen un numero par de factores. (minimo siempre el 1 y el mismo)
// ciertos enteros no tienen cantidad par de factores, estos son aquellos que son cuadrados perfectos
// es decir aquellos que puede ser expresados como potencia 2 de otro entero. (4 9 16...)
	//ofstream myfile;
 	//myfile.open ("salida5.txt");
	// en resumen, si es un cuadrado perfecto, tiene una cant impar de divisores, sino tiene una cant par.
	long long root , n_bulb, integer;

	cin >> n_bulb;
	while(n_bulb){
		// determinar si es un numero cuadrador perfecto
		root = sqrt(n_bulb);   // sino es cuadrado perfecto dará un numero que no es entero
		integer = root * root; // si root no es entero el cuadrado tampoco lo sera
		// si ambos son iguales, significa que root^2 dio entero.-> es cuadrado perfecto-> tiene impar divisores
		if ( n_bulb == integer ){
			printf("yes\n");
			//myfile << "yes"<< endl;
		}
		else{
			printf("no\n");
			//myfile << "no"<< endl;
		}
		
		cin >> n_bulb;
	}
	//myfile.close();
    return 0;
}