#include <iostream>
#include <vector>
#include<algorithm> // para usar funcion min
#include <sstream>

using namespace std;



//globales:
const int MAX_VERTI = 110;
vector<int> grafo[MAX_VERTI]; // Lista de adjacencia. 
bool visit[MAX_VERTI] = {false}; // array de nodos visitados, por default se crea en false
int dfs_orden[MAX_VERTI]; // array se usara para alamacenar el n de orden en que se visitio cada v
int low[MAX_VERTI]; // array para guardar el ancestro mas viejo de cada v
int padre[MAX_VERTI];
vector <int> pts_arti; // para guardar aquellos que son ptos de arti
int dfs_raiz; //para registrar el nodo inicial del reco
int hijos_raiz; //cont la cant de hijos del nodo raiz
void PUNTOS_ART(int);
void BUSCAR_PA(int , int);
int main () {
  	cout<<"Run..."<<endl;
    /*cargar grafo, datos de entrada*/
    
    int n; // n: Cantidad de nodos,
    int v; // vertice v
    int w; // vertice ady (vecino)
    string line;
    scanf("%d", &n);
    while (n != 0){ // leer hasta que recibe un vertice v de valor = 0
	    getline(cin, line);
	    while(line != "0"){
	        stringstream ss(line);
	        ss >> v;
	        while(!ss.eof()){
	            ss >> w;
				grafo[v].push_back(w) ;// arma el grafo
				grafo[w].push_back(v) ;// arma el grafo
	        }
	        getline(cin, line);
	    }
		/*mostrar el grafo
		cout<<"Grafo:"<<endl;
	    for (int v = 0; v <= n; ++v) {
	        cout << "\n lista de ady del vertice " << v
	             << "\n V ";
	        for (auto x : grafo[v])
	            cout << "-> " << x;
	        printf("\n");
	    }*/
	for (int i=0; i<=n;i++){
		pts_arti.push_back(false);
	}
    /*contar puntos de articualcion*/
    	PUNTOS_ART(n);
    
    
	    /*imprimir resultado*/
	    printf("resultado %d", count(pts_arti.begin(), pts_arti.end(), true));
	    printf("%d hijos");
	    
	        cout << "\n ptso de arti \n";
	            
	        for (auto x : pts_arti)
	            cout << "-> " << x;
	        printf("\n");
	
	   /*limpiar para el sig test*/
	    for (auto& v : grafo) {
				v.clear();
			}
		pts_arti.clear();
	
		scanf("%d", &n)	;

	}
    

    return 0;
}

/*grafo: una "lista de vectores" cada i-esima fila rep una lista de vecinos, del nodo i. 
se implementea como un array de vectores, cada elemento del array es un vector de enteros:
*/

void PUNTOS_ART(int n){
    int padre[n]; // para almacenar el v padre de cada v
	int cont = 1;
	
    for (int v = 1; v <= n; v++){
    	if (!visit[v]){
    		dfs_raiz = v;
    		hijos_raiz = 0;
    		BUSCAR_PA(v, cont);
    		if (hijos_raiz > 1){ // es un pto de arti
    			pts_arti.at(dfs_raiz) = true;
			}
		} 
	}
	
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
			if (low[w] >= dfs_orden[v])
				pts_arti.at(v) = true; // es pto de arti
			low[v] = min(low[v], low[w]);
		}
		else if(w != padre[v]){
			low[v] = min(low[v], dfs_orden[w]);
		}
	}
	
}
