// calculo de CRC código de reduncacia cíclica.

/*input
this is a test

A
#

Sample Output
77 FD
00 00
0C 86
*/

#include <bits/stdc++.h>
using namespace std;


int main() 
{	int Q = 34943; // generador
	char resul[5]; // para formatear la salida
	string msj; // donde se guarda el input (el mensaje m)
	
	getline(cin, msj);
	while (msj != "#"){
		if (msj.size()==0){
			cout << "00 00"<<endl;
			getline(cin, msj);
			continue;
		} 
		
		// se utiliza la propiedad de aritm modular (A+B)%Q = (A % Q + B % Q) %Q
		
		long long int acum_resto = 0;
		for (int i = 0; i< msj.size();i++){
			acum_resto = acum_resto * 256; //antes de sumar hay que correr la posición del byte a la izq
			acum_resto = acum_resto + msj[i];//578->579
			acum_resto = (acum_resto % Q);//2->2
		}
		// el CRC ocupa 16 bits, de desplaza 2 veces a izq 
		acum_resto = (acum_resto * 256 % Q) * 256 % Q;
		
		// para que sea divisible, el resto debe dar 0,=>
		// lo que le falta a 'acum_resto' para llegar al Q (divisor)
		// es el valor que hay que sumar,	
		// ese valor es el CRC
		int CRC = Q - acum_resto;
		
		sprintf (resul, "%04X", CRC); // guarda como un string resul, el formateo
		printf("%c%c %c%c\n", resul[0], resul[1], resul[2], resul[3]);
		
		
		getline(cin, msj);
	}
	return 0;
}
