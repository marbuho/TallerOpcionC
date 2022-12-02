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

// convierte ascii caracter a binario
string char_to_str(char ch)
{
    bitset<8> temp(ch);
    return temp.to_string();
}
// Main function
int main() 
{	int g = 34943;
	string msj = "Abc";
	int resto;
	// A = 01000001 = 65
	int n = 0;
	cout << " n = 0 y desplazado 8 bit"<< (n << 8) <<endl;
	cout << "n= "<< n<< endl;
	int m = msj[0] + (n << 8);
	m = msj[1] + (m << 8);
	cout << " m: "<< m <<endl;
	cout << " resto: "<< m % g <<endl;
	m = msj[2] + (m << 8);
	cout << " m: "<< m <<endl;
	cout << " resto: "<< m % g <<endl;

	int j = 1;
	cout << " desplazo 16 lugares: "<< (j<<16)<<endl;
	
	
	
    cout << "Binary Representation of given number: ";
    // Printing the binary representation of the given decimal number

}
