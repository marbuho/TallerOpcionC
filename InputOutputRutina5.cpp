//Ejemplo de entrada y Salida tipica
//Entrada
// 1 2
// 5 7
// 6 3
// 0 0
// deja una linea en blanco, pero evita la linea en blanco para el ultimo caso,
// Case 1: 3
//
// Case 2: 12
//
// Case 3: 9
//___________

#include<cstdio>
int a, b, c = 1;
while (scanf("%d %d", &a, &b) != EOF)
	if (c > 1) printf("\n"); // 2do y n-simo casos
		//  notar el ‘\n’
	printf("Case %d: %d\n", c++, a + b);
	
	