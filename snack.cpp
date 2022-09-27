
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	double precio[5];

	int C,N;
	double P;
	printf("Ingresa un codigo [1-5] y separado la cantidad: \n");
	scanf("%d", &N); // lee la cantidad de dias
	scanf("%d", &C); //lee la cant de partidos
	
	precio[0] = 4;
	precio[1] = 4.5;
	precio[2] = 5;
	precio[3] = 2;
	precio[4] = 1.5;

	P = precio[N-1] * C;
	printf("Precio %f \n", P);



    


	
	return 0;
}
