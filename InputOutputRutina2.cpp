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
// Lee hasta que ambos son 0
int a,b;
while (scanf("%d %d", &a, &b), (a || b))
	printf("%d\n", a + b);

