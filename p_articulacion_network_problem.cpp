#include <iostream>
#include <vector>
#include<alogithm> // para usar funcion min

using namespace std;



//globales:
const int MAX_VERTI = 1000;
vector<int> grafo[MAX_VERTI]; // Lista de adjacencia. 
bool visit[MAX_VERTI]; // array de nodos visitados, por default se crea en false
int dfs_orden[MAX_VERTI]; // array se usara para alamacenar el n de orden en que se visitio cada v
int low[MAX_VERTI]; // array para guardar el ancestro mas viejo de cada v
vector <int> pts_arti; // para guardar aquellos que son ptos de arti
int dfs_raiz; //para registrar el nodo inicial del reco
int hijos_raiz; //cont la cant de hijos del nodo raiz

int main () {
    int n, m; // n: Cantidad de nodos, m: Cantidad de aristas
    
    cin >> n >> m;
    /*cargar grafo, datos de entrada*/
    
	
    
    /*contar puntos de articualcion*/
    int result = PUNTOS_ART(n)
    
    /*imprimir resultados*/

   /*limpiar para el sig test*/

    return 0;
}

/*grafo: una "lista de vectores" cada i-esima fila rep una lista de vecinos, del nodo i. 
se implementea como un array de vectores, cada elemento del array es un vector de enteros:
*/

int CONT_PUNTOS_ART(int n){
    int padre[n] // para almacenar el v padre de cada v
	int cont = 1;
	int cant = 0;
    for (int v = 0; v < n){
    	if (!visit[v]){
    		dfs_raiz = v;
    		hijos_raiz = 0;
    		BUSCAR_PA(v, cont);
    		if (hijos_raiz > 1){ // es un pto de arti
    			pts_arti.push_back(dfs_raiz)
			}
		} 
	}
	return cant;
}
void BUSCAR_PA(int v, int cont){
	visit[v] = true;
	dfs_orden[v] = cont++;
	low[v] = dfs_orden[v];
	for (int w : grafo[v]){
		if (!visit[w]){
			padre[w] = v;
			if (v == dfs_raiz)
				hijos_raiz++;
			BUSCAR_PA(w ,cont);
			if low[w] >= dfs_orden[v];
				pts_arti.push_back(w) // es pto de arti
			low[v] = min(low[v], low[w]);
		}
		else if(w != padre[w]){
			low[v] = min(low[v], dfs_orde[w]);
		}
	}
	
}
