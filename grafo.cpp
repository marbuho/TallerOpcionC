/*input
5
5 
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
#include <string>
#include <sstream>

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
    string line;
    scanf("%d", &n);
    while (n != 0){ // leer hasta que recibe un vertice v de valor = 0
		cout<< "n="<< n <<endl;
		
	    getline(cin, line);
	    while(line != "0"){
	        stringstream ss(line);
	        ss >> v;
	        while(!ss.eof()){
	            ss >> w;
	            cout<< "v="<< v <<endl;
    			cout<< "w="<< w <<endl;
    			cout<<"se hace el push en grafo:"<< v <<" push_back(w=" <<w <<")"<<endl;
				grafo[v].push_back(w) ;// arma el grafo
				cout<<"se hace el push en grafo:"<< w <<" push_back(w=" <<v <<")"<<endl;
				grafo[w].push_back(v) ;// arma el grafo
	        }
	         getline(cin, line);
	    }

		//mostrar el grafo
		cout<<"Grafo:"<<endl;
	

	    for (int v = 0; v <= n; ++v) {
	        cout << "\n lista de ady del vertice " << v
	             << "\n V ";
	        for (auto x : grafo[v])
	            cout << "-> " << x;
	        printf("\n");
	    }
	    
	    for (auto& v : grafo) {
			v.clear();
		}
		
		scanf("%d", &n)	;

	}
    	
			 
    return 0;
}


