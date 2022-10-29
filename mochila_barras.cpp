//Input
/*
1 
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
#include <stdio.h>
#include <iostream>

bool mochilabarras(int ldese, int cant, int barras[]);
int main(){
//	printf("run..\n");
	int TC, TB, a, b, ldese, longi;
	scanf("%d", &TC); //nro de casos
	
	int barras[55]; // las barras a lo sumo mide 50
	
	while(TC--){ //repite TC veces
		scanf("%d", &ldese);// lee longitud deseada
		scanf("%d", &TB); //lee nro de barras elemento
		int cant = 0;
		// se arma el vector que contiene la long de cada barra
		while(TB--){ //repite TB veces
			scanf("%d", &longi);
			barras[cant++] = longi;
		}
		bool result = mochilabarras(ldese, cant, barras);
		if (result) printf("YES\n");
		else printf("NO\n");	
	}
}


bool mochilabarras(int ldese, int cant,int barras[]){
	int N = cant;
	int K = ldese; 
	bool DP[N+20][K+20];
	

	for (int i=0; i<=N; i++) DP[i][0] = true;// completo primera columna
	for (int j=0; j<=K; j++) DP[0][j] = false;// completo primera fila
	DP[0][0] = true; // una mochila de tam = 0 se puede armar con 0 elementos
//	printf("Declaro el array\n");
	for (int i=1; i<=N+1; i++) {
//		printf("For del iiiiiii=%d\n", i);
		for (int j=1; j<=K; j++) {
//			printf("For del j=%d\n", j);
			/* si la barra elemento, mide mas del tam max de la mochila (para esta columna)
			el resultado es que no se puede incorporar a la misma, y se toma el result
			de la fila de arriba */
			if (barras[i-1]> j) DP[i][j] = DP[i-1][j];
			/* Si la barra elemento mide menos, tengo 2 opciones o tomarla o dejarla*/
			else{/* si con las barras anteriories ya arme la mochile de tam = J entonces sigue siendo posible
				armarla sin tomar esta barra*/
				if (DP[i-1][j]) DP[i][j] = true;
				else
				/*si con las barras anteriores aun no se puede armar la mochila de tam = j,
				me fijo si se podia armar cuando la mochi era de tam igual a 
				la dife entre el tam de la mochila actual (j) y la barra  actual */
				if ( DP[i-1][j-barras[i-1]] ){
//					printf("DP[%d - 1][%d-barras[%d - 1]]\n", i,j,i);
				 	DP[i][j] = true;
				 }
				
				else DP[i][j] = false;				 
			}		
		}
	}
//	printf("calculo la mochila...\n");
	/*Al finalizar se debe buscar si hubo algun true en la ulitma columna
	correspodiente a la mochila = al tam de la barra deseada*/
	bool result = false;
	for(int k = 0; k <= cant; k++){
//		printf("entro a buscar en la ultima columna...\n");
		if (DP[k][ldese]){
			result = true;
			break;
		}
	}

	/* imprimir matriz:
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << DP[i][j] << ' ';
        }
        std::cout << std::endl;
    }*/
//	printf("termino de buscar\n");
	return result;
	
}
/* Algoritmo mochila clasica: 
			if (elem[i-1][0] > j) DP[i][j] = DP[i-1][j];
			else DP[i][j] = max(DP[i-1][j], DP[i-1][j-elem[i-1][0]] + elem[i-1][1]);*/