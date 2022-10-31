#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODOS = 1000;
/*grafo: una "lista de vectores" cada i-esima fila rep una lista de vecinos, del nodo i. 
se implementea como un array de vectores, cada elemento del array es un vector de enteros:
*/
vector<int> grafo[MAX_NODOS]; // Lista de adjacencia. 
bool visit[MAX_NODOS]; // Vector de nodos visitados

void DFS (int i)
    visit[i] = true;

    for (int w : grafo[i])
        if (!visit[w])
            DFS(w);
}

int main () {
    /*cargar un grafo adecuadamente*/
	int n; // debe tener la can de nodos
	
	// visitar todos los vertices:
    for (int i = 0; i < n; i++)
        if (!visit[i])
            DFS(i);

    return 0;
}