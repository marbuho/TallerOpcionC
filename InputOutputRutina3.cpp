//Ejemplo de entrada y Salida tipica
//Entrada
// 1 2
// 5 7
// 6 3
// 0 0
//Salida
// 3
// 12
// 9
#include<cstdio>
int a, b;
// scanf retorna el numero de elementos leido
while (scanf("%d %d", &a, &b) == 2)
// o chequear que no sea el fin de linea, es decir:
//while (scanf("%d %d", &a, &b) != EOF)
	printf("%d\n", a + b); // calcular salida