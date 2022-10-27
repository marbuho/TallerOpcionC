//Input
/*
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567
*/
// outuput
/*
NO
YES
NO
YES
*/
#include <array>
#include <algorithm.h>
bool mochilabarras(int ldese, int cant, barras[]);
int main():
	int TC, a, b;
	scanf("%d", &TC); //nro de cas
	
	barras<int, 55>;
	
	while(TC--){ //repite hasta 0
		scanf("%d", &ldese);// longitud deseada
		scanf("%d", &TB); //nro de barras
		cant = 0;
		while(TB--){ //repite TB veces
			scanf("%d", &barra);
			barras[i] = barra;
			cant++;
		}
		result = mochilabarras(ldese, cant, barras)
		barras.fill(0)	
		
		
		
		}
	}
}

bool mochilabarras(int ldese, int cant, barras[]){
	int N = cant;
	int K = ldese; 
	int elem[N][2];
	int DP[N+1][K+1];

	for (int i=0; i<=N; i++) DP[i][0] = 0;
	for (int j=0; j<=K; j++) DP[0][j] = 0;
	
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=K; j++) {
			if (elem[i-1][0] > j) DP[i][j] = DP[i-1][j];
			else DP[i][j] = max(DP[i-1][j], DP[i-1][j-elem[i-1][0]] + elem[i-1][1]);
		}
	}
	
	int maximo = DP[N][K];
	
	return (ldese == maximo) ;
	
}