/* Sample imput:
	abcd
	acdb
	abcd
	dacb
	#
	
Sample output:
Case #1: you can visit at most 3 cities.
Case #2: you can visit at most 2 cities.
*/




#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int LCS(string s1, string s2);
int main(){
	int a,b;
	printf("run...");
	string s1 = "oasdf";
	string s2 = "hoasdfs";
	int result = LCS(s1, s2);
	printf("Case #: you can visit at most %d cities\n", result);
	
		
	return 0;
}

int LCS(string s1, string s2) {
	int n = s1.length() + 1, m = s2.length() + 1;
	int memoization[n][m], i, j;
		// Creacion de la matriz de calculo, se usara para almacenar resultados 
		// del overlapig subproblem:
		for(i = 0; i <= n; i++) memoization[i][0] = 0;
		for(j = 0; j <= n; j++) memoization[0][j] = 0;
	// caculculo:
	for(i = 1; i < n; i++){
		for(j = 1; j < m; j++)
			if(s1[i-1] == s2[j-1])
				memoization[i][j] = memoization[i-1][j-1] + 1; // si son igulaes se suma 1 a celda diagonal superior izquierda
			else
				memoization[i][j] = max(memoization[i-1][j], memoization[i][j-1]);  // si son != se queda con le maximo (celda de arriba y celda izq)
	}
		
	return memoization[n-1][m-1];
}


    


