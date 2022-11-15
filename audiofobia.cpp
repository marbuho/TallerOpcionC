/*input:
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0

output

Case #1
80
60
60

Case #2
40
no path
80
*/


#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <queue>
#include <iostream>
#include <fstream>

class Grafo{
    public:
    vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
    int vertices; // cant de servidores
    
    
    Grafo(int n){
    vertices=n;
    adya_list= new vector< pair<int,int> >[n]; // n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
    // el vec contiene elementos par, (u, lat) u es el vert de destino, y lat la latencia del cable, (peso de la arista)
    }
    void agregar_conex(int v1,int v2,int lat){
    // conecttar v1 con v2 y viceversa
    adya_list[v1].push_back(make_pair(v2,lat));
    adya_list[v2].push_back(make_pair(v1,lat));
};

struct UFDS {
	vector<int> p, rank; //también pueden usarse arreglos estáticos
	
	UFDS (int size) {
		p.clear(); rank.clear();
		for (int i=0; i<size; i++) {
			p.push_back(i);
			rank.push_back(0);
		}
	}
	
	int find_set (int i) {
		return (i == p[i]) ? i : (p[i] = find_set(p[i]));
	}
	bool same_set (int i, int j) {
		return find_set(i) == find_set(j);
	}
	void union_set (int i, int j) {
		if (!same_set(i, j)) {
			int x = find_set(i);
			int y = find_set(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

using namespace std;



int main(){
	//printf("run.....\n");
	//ofstream myfile;
 	//myfile.open ("example2.txt");
 	
 	
 	
    string line;
    int TC, C, S, Q, v1, v2, p, count, origen, destino;
    //leer entrada para armar la red:
    count = 1;
	while(true){
	    vector<tuple<int, int, int> > aristas;
	    
	   
	    
		stringstream ss(line);
		ss >> C;
		ss >> S;
		ss >> Q;
		
		if (C + S + Q == 0) break;
		
		for (int i = 0; i < S; i++){
			getline(cin, line);
			ss >> v1;
			ss >> v2;
			ss >> p;
			aristas.push_back(make_tuple(p, v1, v2));
			
		}
		sort(aristas.begin(), aristas.end())
		
		if (count > 1) cout << endl; // dejar una linea en blanco entre casos
		
		arbol_mst = Arbol_MST(aristas, C);
		
		printf("Case #%d\n",count++);
		for (int i = 0; i < Q; i++){
			getline(cin, line);
			ss >> origen;
			ss >> destino;
			// calcular respuesta
			result = minMax(arbol_mst, origen, destino);
			if (result == 0)
				printf("no path\n",count++, result);
			else
				printf("%d\n",count++, result);
		}
		
	}
    //myfile.close();
    return 0;
}

Grafo  Arbol_MST(vector< tuple<int,int,int> > aristas, int V){
    int v1, v2, p;
	int costo_mst = 0;
	Grafo arbol_mst  = Grafo(V);
	// inciar conjuntos
	
	UFDS ds = UFDS(V);

	// calcular costo y armar arbol
    for (int i = 0; i < aristas.size(); i++) {
        p  = get<0>(aristas[i]);
        v1 = get<1>(aristas[i]);
        v2 = get<2>(aristas[i]);
        
        if(!ds.same_set(v1, v2)){
            costo_mst += p;
            ds.union_set(v1, v2);
            
            arbol_mst.agregar_conex(v1, v2, p);
        }
    }
	
	return arbol_mst;
}

    //procear la respuesta
int minMax(arbol, int inicio, int destino) {
    int max = -1
    int n = arbol.vertices;
    bool visit[n]; // Vector de nodos visitados
    
    for (auto it=arbol.adya_list[inicio].begin(); it!=arbol.adya_list[inicio].end(); it++)
        int d = it->first;
        int p = it->second;
        if (!visit[d]){
            if (p > max){
                max = p;
            } 
            
            if (d == destino){
                return max; 
            }
            else{
                DFS(d);
            }
}
void DFS (int i)
    visit[i] = true;
    
    for (int w : grafo[i])
        if (!visit[w])
            
            DFS(w);
}


