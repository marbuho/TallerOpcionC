#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int lis(vector<int> seq);
vector<int> DP;
vector<int> PREV;

int main(){
	printf("corriend....\n");
	ifstream myfile ("inputTestLis.txt");
  	myfile.is_open();
	int TC,v,c;
	string str;
	getline (myfile,str);
	TC = stoi(str);
	
	c = 1;
	while(TC--){
		if (c++ == 1) getline (myfile, str);  //saltea la 1era linea en blanco (solo en el 1ert Test)
		vector<int> seq;
		while (getline (myfile, str)){ // armado de la secuencia de entrada
			if (str.size() == 0) break;
			v = stoi(str);
			seq.push_back(v);
		}	
		//calcular respuesta:
		int i_max = lis(seq);
		int maxLen = DP.at(i_max);
		//CORREGIR SE ESTA ARMANDO MAL LA SECUENCIA. 
		printf ("Max hits: %d\n", maxLen);
		// armado de la sub secuencia LIS:
		vector<int> sub_seq;
		sub_seq.push_back(seq.at(i_max));
		int aux = maxLen - 1;
		while (aux > 0) { 
			int j = PREV.at(i_max--);
			if (j == -1) continue;
			int val = seq.at(j);
			sub_seq.push_back(val);
			aux--;
		}
		//lectura inversa: (la subsecuencia  creciencte esta armada de derecha a izquierda)
		for (auto itr = sub_seq.end() - 1;itr !=  sub_seq.begin() - 1; itr--)
	        cout << *itr << endl;
	        
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
	// ult_i tendrá la posición (enla secuencia original)
//	del ultimo elemento de la subsecuencia final.
// ejemplo seq = 2 6 3 4 5 1, ult_i = 4 (seq[4] = 5, el maximo de: 2 3 4 5)
// PREV = -1 0 0 2 3 -1 
