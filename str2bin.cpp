#include <bits/stdc++.h>
using namespace std;

#define MAX 32
int main() {
	
	
    string msg = "Hola";
	string msg_bin;

	/*// convertir mensj en binario
    for (int i = 0; i < msg.length(); ++i) {
        bitset<8> bin_char(msg[i]);
        cout << bin_char << " ";
		// función to string, convierte la secuencia bin en un string
		msg_bin += bin_char.
		to_string<char,string::traits_type,string::allocator_type>();

        /*if (i % 6 == 0 && i != 0)
            cout << endl;
    }
	
	bitset<MAX> bin_char_msg(msg_bin);
    cout << endl;
	cout << "string del binario " << msg_bin << '\n';
	
	bitset<MAX> prueba;
	cout << "bitset del msj completo " << bin_char_msg << '\n';
	prueba = bin_char_msg << 2;
	cout << "desplazado " << prueba << '\n';*/
	long long int resto = msg[0] % 7; //msg [0]=H=72
	cout << "resto " << resto << '\n';
	resto <<=8;
	cout << "resto dsp de desplazar " << resto << '\n';
	resto += msg[1];//msg [1]=o=111
	cout << "resto dsp sumar 2 letra " << resto << '\n';
	
	



    return EXIT_SUCCESS;
}
