//Ejemplo de entrada y Salida tipica
//Entrada
// 1 2
// 5 7
// 6 3
// 0 0
// deja una linea en blanco
// Case 1: 3
//
// Case 2: 12
//
// Case 3: 9
//
//____________

#include<cstdio>
int a, b, c = 1;
while (scanf("%d %d", &a, &b) != EOF)
	//  notar los dos ‘\n’
	printf("Case %d: %d\n\n", c++, a + b);