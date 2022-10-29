/* Strategic Defense Inisiative
Sample Input:
1
1
6
2
3
5
Sample Output:
Max hits: 4
1
2
3
5*/

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> seq);
vector<int> DP; // variables globales, DP es donde se hace memoization
vector<int> PREV; // se almacena el previo, para poder reconstruir la subseq resultado

int main(){
	//printf("corriend....\n");
	int TC,v,c;
	string str;
	scanf("%d", &TC);
	getline (cin, str);
	while(TC--){
		getline (cin, str);  //saltea linea en blanco (solo en el 1ert Test)
		vector<int> seq;
		while (getline (cin, str)){ // armado de la secuencia de entrada
			if (str.size() == 0) break;
			v = stoi(str);
			seq.push_back(v);
		}	
		//calcular secuencia:
		int i_max = lis(seq); // la funcion devuelve el indice, no el valor
		int maxLen = DP.at(i_max); 
		if (c++ > 1) printf("\n"); // para que deje lineas en blanco solo entre test
		printf ("Max hits: %d\n", maxLen);
		
		// armado de la sub secuencia LIS: 
		vector<int> sub_seq; // aca se guarda la subsecuencia LIS
		
		// se arma desde el mayor al menor.
		sub_seq.push_back(seq.at(i_max));
		int j = i_max;
		int ant;
		for (int k = 1; k < maxLen; k++){ 
			ant = PREV[j];
		    int valor = seq[ant];
			sub_seq.push_back(valor);
			j = ant;
		}
		//lectura inversa: (la subsecuencia  creciencte esta armada de derecha a izquierda)
		for (auto itr = sub_seq.end() - 1; itr !=  sub_seq.begin() - 1; itr--)
	        cout << *itr << endl;
	    
		//limpiar para el prox TC
	    DP.clear();
	    PREV.clear();
	}
	
    return 0;
}


int lis(vector<int> seq){
	for(int i = 0; i < seq.size(); i++){
	    PREV.push_back(-1);
	}
	for(int i = 0; i < seq.size(); i++){
	    DP.push_back(1);
	}
	int ult_i = 0;
	for (int i=0; i < seq.size(); i++) {
		DP[i] = 1; // Mínimo LIS = 1
		for (int j=0; j < i; j++) {
			if ((seq[j] < seq[i]) && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1; PREV[i] = j;
			}
		}
		
		if (DP[ult_i] < DP[i]) ult_i = i;
	}
	return ult_i; 
}
/*  ult_i tendrá la posición (de la secuencia original)
	del ultimo elemento de la subsecuencia final.
	ejemplo seq = 2 6 3 4 5 1, -> ult_i = 4 donde seq[4] = 5, el maximo de: 2 3 4 5
	PREV = -1 0 0 2 3 -1
 */
