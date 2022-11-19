#include <bits/stdc++.h>

using namespace std;

#define MAX_CROSSINGS 110
int maxG;

struct UFDS {
  vector<int> p; //también pueden usarse arreglos estáticos

  UFDS (int size) {
    p.clear();
    for (int i=0; i<size; i++) {
      p.push_back(i);
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
      p[y] = x;
    }
  }
};

class Grafo{
    public:
    list < pair<int,int> > * adya_list; // un puntero a una lista de pares

    Grafo(int n){
      adya_list= new list< pair<int,int> >[MAX_CROSSINGS]; // n listas, (1 para cada vertice, cada lista rep la lista de adyacencia,
        // los elementos de la lista son del tipo par, (u, p) u es el vert de destino, y p peso de la arista)
    }
    void agregar_conex(int v1,int v2,int lat){
      // conecttar v1 con v2 y viceversa
      adya_list[v1].push_back(make_pair(v2,lat));
      adya_list[v2].push_back(make_pair(v1,lat));
    }
};

Grafo  Arbol_MST(vector< tuple<int,int,int> > aristas, int V){
    int v1, v2, p;
    Grafo arbol_mst  = Grafo(MAX_CROSSINGS);
    // inciar conjuntos
    UFDS ds = UFDS(MAX_CROSSINGS);
    // armar arbol MST
    for (int i = 0; i < aristas.size(); i++) {
        p  = get<0>(aristas[i]);
        v1 = get<1>(aristas[i]);
        v2 = get<2>(aristas[i]);

        if(!ds.same_set(v1, v2)){
            ds.union_set(v1, v2);
            arbol_mst.agregar_conex(v1, v2, p);
        }
    }

    return arbol_mst;
}

void dfs(Grafo arbol, int inicio, int destino, bool visit[], int max_edge) {
  visit[inicio] = true;

  if (inicio == destino) {
    maxG = max_edge;
  }
  else {
    for ( auto it: arbol.adya_list[inicio] ){
      int w = it.first;
      int peso = it.second;

      if (!visit[w]){
        dfs(arbol, w, destino, visit, max(max_edge, peso));
      }
    }
  }
}

/*int DFS_MaxEnElCamino(Grafo arbol, int inicio, int destino, bool visit[], int maximo_ini){
  visit[inicio] = true;

  if (inicio == destino){
    return 0;
  }

  int maximo = -1;
  for (auto it: arbol.adya_list[inicio]){
    int w = it.first;
    int peso = it.second;

    if (!visit[w]){
      maximo = max(maximo, DFS_MaxEnElCamino(arbol, w, destino, visit, maximo));
      if (maximo >= 0 ){
        maximo = max(maximo, peso);
        break;
      }
    }
  }

  return maximo;
}*/

int MaxEnElCamino(Grafo arbol, int inicio, int destino) {
    bool visit[MAX_CROSSINGS] = { false }; // Vector de nodos visitados
    
    maxG = -1;
    /* int resu = DFS_MaxEnElCamino(arbol, inicio, destino, visit, maximo_ini); */
    dfs(arbol, inicio, destino, visit, -999);

    return maxG;
}

int main(){
  //ofstream myfile;
 // myfile.open ("exampleV2.txt");
  int C, S, Q, v1, v2, p, q, origen, destino;
  //leer entrada para armar la red:
  q = 0;

  cin >> C >> S >> Q;

  while(C && S && Q){
    vector<tuple<int, int, int> > aristas;

    for (int i = 0; i < S; i++){
      cin >> v1 >> v2 >> p;
      aristas.push_back(make_tuple(p, v1, v2));
    }

    sort(aristas.begin(), aristas.end());

    Grafo arbol_mst = Arbol_MST(aristas, C);

    if (q >= 1){  // dejar una linea en blanco entre casos
      //myfile << endl; 
      cout << endl;
    }
	
   // myfile << "Case #"<< ++q <<endl;
    cout << "Case #"<< ++q <<endl;
	// En cada Case, se calcula el resultado para c/ query
    for (int i = 0; i < Q; i++){
      cin >> origen >> destino;

      int result = MaxEnElCamino(arbol_mst, origen, destino);
      if (result == -1){
        cout << "no path" <<endl;
       // myfile << "no path" <<endl;
	  }
      else{
        cout << result <<endl;
        //myfile << result <<endl;
      }
    }

    cin >> C >> S >> Q;
  }
  //myfile.close();
  return 0;
}