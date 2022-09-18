//Ejemplo de entrada y Salida tipica
//
//Entrada con cantidad variable, (el primer elemento k indica que tiene k enteros a continuacion)
// 1 1
// 2 3 4
// 3 8 1 1
// 4 7 2 9 3
// 5 1 1 1 1 1
// Salida(la suma):
// 1
// 7
// 10
// 21
// 5

#include<cstdio>
int k, ans, v;
while (scanf("%d", &k) != EOF) {
	ans = 0;
	while (k--) { scanf("%d", &v); ans += v; }
		printf("%d\n", ans);

}
	
	