#include <bits/stdc++.h>
using namespace std;

#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */


int crc(string message)
{	
	int g = 8;
    int  resto;	
	int temp;

	/*para cada byte del mesaje calcular el resto*/
    for (int byte_i = 0; byte_i < msj.size(); ++byte_i)
    {	
		resto = resto ^ (msj[byte_i] << 8);
		/**calculuo del resto/
        /*dividir en modulo 2 bit a bit*/
		for (int bit = 0; bit < 8; bit++){
			// si el bit mas signif del resto es 1
			// hacer el xor y desplazar
			// 0x8000 = 10000000 00000000
			if (resto & 0x8000){
                resto = (resto << 1) ^ g;
            }
			// sino, solo desplazar
			else
                resto = (resto << 1);
            }
		}
		
		// el resto que queda al final, es el crc
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return (remainder >> 4);

}   /* crcNaive() */

#define MAX 32
int main() {
	
	
    string msg = "HO"; // en binario es 01001000 01001111 = 72 79
	string msg_bin;
	int q=10; // en binario es 00001010
	int temp = 0;
	
	for(int i=0; i< msg.size();i++){
		cout << "iteracion i= " << i << '\n';
		temp = temp + msg[i];
		cout << "temp bajando sig 8bits " << temp << '\n';
		temp = temp % q;
		cout << "temp= temp mod q " << temp << '\n';
		temp = temp << 8; // desplazo 8bits a la derecha
		cout << "temp desplazado 8 " << temp << '\n';
		
		temp = temp + msg[i]; // bajo los siguientes 8 bits
		
	}
	cout << "result " << temp << '\n';

	
	



    return EXIT_SUCCESS;
}
