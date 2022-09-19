//LIS
//input:
//2
//5 1 2 3 4 5
//7 1 6 3 4 4 7 5


#include<cstdio>
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void print(vector<int> const &input);
int LISDP(vector<int> seq, int n);

const int MAXINPUT=100;

vector<int> MEMO(MAXINPUT, -1); // aca se almacena los calculos del sub-problema para no repetirlos. Es global

int main(){
	int TC, v, k, c;
	scanf("%d", &TC); //nro de casos
	c = 1;
	while(TC--){ //repite hasta 0	
		scanf("%d", &k); // tam de la secuencia de entrada
		vector<int> seq;	//aca se almacena la secuencia de entrada a analizar.
		if (c > 1) fill(MEMO.begin(), MEMO.end(), -1);// limpiar MEMO solo cuando hay mas de 1 secuencia de entrada
		
		MEMO[0] = 1;// el primer elemento siempre es 1
		//armar la secuencia de entrada:
		while (k--) { 
			scanf("%d", &v);
			seq.push_back(v);
		}
		//calcular la respuesta:
			
		int resul = LISDP(seq, seq.size());
		
		//Mostrar resultado y el vector memorizado (MEMO):
		printf("%d \n", resul);
		print(MEMO);
		
		//aumentar el numero de caso(solo se usa para saber si es necesario reiniciar el vector MEMO
		c++;
		
	}
		return 0;
}


int LISDP(vector<int> seq, int n){
	//casosbase:
	if (n == 1) return MEMO[0]; // siempre es 1
	//chequear si existe un calculo anterior almacenado en memo
	if (MEMO[n-1] != -1) return MEMO[n-1]; 
	MEMO[n - 1] = 1; // maxima longitud a priori es 1
	for (int j = 1; j < n; j++){
		if ((seq[j-1] < seq[n-1])){
			if (LISDP(seq, j) + 1 > MEMO[n-1] ) //¿Es mas larga? Si lo es necesito actualizar el MEMO.
				MEMO[n-1] = LISDP(seq, j) +1;
		}
	}
		
	
	return MEMO[n-1];
}

//int LISDPR(vector<int> seq, int n){
//	//casosbase:
//	if (n == 1) return 1; // siempre es 1
//	//chequear si existe un calculo anterior almacenado en memo
//	
//	for (int j = 1; j < n; j++){
//		if ((seq[j-1] < seq[n-1])
//		
//			if (MEMO[j-1] < LISDP(seq,j) + 1) 
//				MEMO[j-1] = LISDP(seq, j) + 1;
//		}
//	}
//	return MEMO[n-1];
//}
void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
    std::cout << "\n";
}
