#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int lis(vector<int> seq);
vector<int> DP;
vector<int> PREV;

int main(){
	
	vector<int> seq = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

	//calcular respuesta:
		
	int resul = lis(seq);
	
	
	printf ("lIS %d\n",DP.at(resul));
	printf ("i:     ");
	for (int i=0; i< seq.size();i++) {
    cout << i << " ";
	}
	cout << "\n";
	printf ("seq:   ");
	for (int i : seq) {
    cout << i << " ";
	}
		cout << "\n";
	printf ("DP:    ");
	for (int i : DP) {
    cout << i << " ";
	}
	cout << "\n";
	printf ("Prev: ");
	for (int i : PREV) {
    cout << i << " ";
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
