//Ejemplo de entrada y Salida tipica
//Entrada
// 3
// 1 2
// 5 7
// 6 3
//Salida
// 3
// 12
// 9

#include<cstdio>
int TC, a, b;
scanf("%d", &TC); //nro de casos

while(TC--){ //repite hasta 0
	scanf("%d%d", &a, &b);
	//calcular la resp
	printf("%d \n", a + b);
}