/*input
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
output
1
2
*/

#include <iostream>
#include <vector>
#include <algorithm>  // para usar funcion min

using namespace std;

//globales:
const int MAX_VERTI = 110;
vector<int> grafo[MAX_VERTI]; // Lista de adjacencia. 

int main () {
	cout<<"Run..."<<endl;
    /*cargar grafo, datos de entrada*/
    int n; // n: Cantidad de nodos,
    int v; // vertice v
    int w; // vertice ady (vecino)
    while (scanf("%d", &n), (n != 0) ){  // leer hasta que recibe un vertice v de valor = 0
    		cout<< "n="<< n <<endl;
    		scanf("%d", &v);
    		while (scanf("%d", &w)){
    				cout<< "v="<< v <<endl;
	    			cout<< "w="<< w <<endl;
	    			cout<<"se hace el push en grafo:"<< v <<" push_back(w=" <<w <<")"<<endl;
					grafo[v].push_back(w) ;// arma el grafo
			}
    		cout<<"estoy aca"<<endl;
		
    		
    		
	}
		
		
		//mostrar el grafo
		cout<<"Grafo:"<<endl;
    	for (int i = 0; i <= n; i++) {
       	 //Traversing of vectors vec to print the elements stored in it
			for (auto itr : grafo[i]){
				cout<<itr<<" ";
			}
			cout<<" - "<<endl;
		}
		for (auto& v : grafo) {
   			v.clear();
		}
				 
    return 0;
}



