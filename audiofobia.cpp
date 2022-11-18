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


#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <climits>
#include <iostream>
#include <fstream>
#include <tuple>


using namespace std;

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

class Grafo{
    public:
    vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
    int vertices; // cant de servidores
    
    
    Grafo(int n){
	    vertices=n;
	    adya_list= new vector< pair<int,int> >[n+1]; // n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
    // el vec contiene elementos par, (u, lat) u es el vert de destino, y lat la latencia del cable, (peso de la arista)
    }
    void agregar_conex(int v1,int v2,int lat){
    // conecttar v1 con v2 y viceversa
    	
	    adya_list[v1].push_back(make_pair(v2,lat));
	    
	    adya_list[v2].push_back(make_pair(v1,lat));
	   
	}
};

Grafo  Arbol_MST(vector< tuple<int,int,int> > aristas, int V){
    int v1, v2, p;
	Grafo arbol_mst  = Grafo(V);
	// inciar conjuntos
	UFDS ds = UFDS(V+1);
	// armar arbol MST
    for (int i = 0; i < aristas.size(); i++) {
        p  = get<0>(aristas[i]);
        v1 = get<1>(aristas[i]);
        v2 = get<2>(aristas[i]);
        //printf("se accede a la tupla\n");
        if(!ds.same_set(v1, v2)){
            ds.union_set(v1, v2);
            //printf("toca unir el v1=%d y v2=%d peso=%d\n", v1, v2, p);
            arbol_mst.agregar_conex(v1, v2, p);
            //printf("OKconexion\n");
        }
    }
	return arbol_mst;
}



int DFS_MaxEnElCamino(Grafo arbol, int v, int destino, bool visit[], int maximo_ini);
int MaxEnElCamino(Grafo arbol, int inicio, int destino);

int main(){
	//printf("runnn...\n");
	ofstream myfile;
 	myfile.open ("example2.txt");
    string line;
    int C, S, Q, v1, v2, p, count, origen, destino;
    //leer entrada para armar la red:
    count = 1;
	while(true){
	    vector<tuple<int, int, int> > aristas;
	    getline(cin, line);
		stringstream ss(line);
		ss >> C;
		ss >> S;
		ss >> Q;
	//	cout<< "C="<< C <<endl; 
    //	cout<< "S="<< S << endl; 
    //	cout<< "Q="<< Q << endl;
		
		if (C + S + Q == 0) break;
		
		for (int i = 0; i < S; i++){
			getline(cin, line);
			stringstream ss(line);
			ss >> v1;
			ss >> v2;
			ss >> p;
			//cout<< "v1="<< v1 <<endl; 
	    	//cout<< "v2="<< v2 << endl; 
	    	//cout<< "p="<< p << endl;
			aristas.push_back(make_tuple(p, v1, v2));
		}
		sort(aristas.begin(), aristas.end());
		//printf("se ordeno el sort\n");
		
		
		Grafo arbol_mst = Arbol_MST(aristas, C);
		//printf("OK calculo el mst\n");
		
		//printf("Case #%d\n",count++);
		if (count > 1){  // dejar una linea en blanco entre casos
			myfile << endl; 
		} 
		myfile << "Case #"<< count++ <<endl;
		/*if (count == 60){  // dejar una linea en blanco entre casos
			cout<< "C="<< C <<endl; 
    	cout<< "S="<< S << endl; 
    	cout<< "Q="<< Q << endl;
			return 0; 
		}*/
		for (int i = 0; i < Q; i++){
			getline(cin, line);
			stringstream ss(line);
			ss >> origen;
			ss >> destino;
			//cout<< "origen="<< origen <<endl; 
    		//cout<< "destino="<< destino << endl; 
    	
			// calcular respuesta
			int result = MaxEnElCamino(arbol_mst, origen, destino);
			if (result == -1)
				myfile << "no path"<<endl;
				//printf("no path\n");
			else{
				myfile << result <<endl;
				//printf("%d\n",result);
			}
				
		}
		
	}
	myfile.close();
    return 0;
}


int MaxEnElCamino(Grafo arbol, int inicio, int destino) {
    int n = arbol.vertices;
    bool visit[n+1]; // Vector de nodos visitados
    int maximo_ini = -1;
    int resu = DFS_MaxEnElCamino(arbol, inicio, destino, visit, maximo_ini);
	
	return resu;
            
}
int DFS_MaxEnElCamino(Grafo arbol, int inicio, int destino, bool visit[], int maximo_ini){
	visit[inicio] = true;
	if (inicio == destino){
		return 0;
	}
	int maximo = -1;
    for (auto it=arbol.adya_list[inicio].begin(); it!=arbol.adya_list[inicio].end(); it++){
    	int w = it->first;
        int peso = it->second;
        //printf("vecino adyacente w=%d\n", w);
    	if (!visit[w]){
        	//	printf("como no es igual al destino, se mete en la recursion\n", w);
            	maximo = max(maximo, DFS_MaxEnElCamino(arbol, w, destino, visit, maximo));
            if (maximo >= 0 ){
            	//printf("llego al destino %d\n", w);
            	maximo = max(maximo, peso);
            	break;
			}
                
        }
	}
	return maximo;			
}

