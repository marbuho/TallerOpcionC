/*input:
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1

output

Case #1: 100
Case #2: 150
Case #3: unreachable
*/


#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

//clase para un grafo no dirigido pesado 

class SMTPRed{
public:		
  vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
  int vertices; // cant de servidores
  
  
	SMTPRed(int n){
		vertices=n;
		adya_list= new vector< pair<int,int> >[n]; //  n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
	// el vec contiene elementos par, (u, lat) u es el vert de destino, y lat la latencia del cable, (peso de la arista)
	}
	void agregar_conex(int v1,int v2,int lat){
	// conecttar v1 con v2 y viceversa
	  adya_list[v1].push_back(make_pair(v2,lat));
	  adya_list[v2].push_back(make_pair(v1,lat));
	}
	void mostrar_red(){
  		int servidor,lat;
	  	//Para cada v, se muestra su lista de ady
		for(int i=0;i<vertices;i++){
		  	cout<<"Ady lista del vertice "<<i<<endl;
		// para cada lista,  se muestra su contenido
			for(auto it=adya_list[i].begin();it!=adya_list[i].end();it++){
				  //setea  en servidor como el n de vertice, y lat, como la latencia del cable
				  servidor=it->first; // first y second son usados para acceder al primer y al segundo elemento del par respect.
				  lat=it->second;
				  cout<<"Servidor : "<<servidor<<" Latencia : "<<lat<<endl;
			}
			cout<<endl;
		}
	}
};

int main(){
	string linea; 
	int TC, n,m, origen,desti, v1, v2, lat;	
	//leer entrada para armar la red:	
	scanf("%d", &TC);
	cin.ignore();

	while (TC--){
	  	getline(cin, linea);
	    stringstream ss(linea);
	    ss >> n; // cantidad de nodos
	      cout<< "n="<< n <<endl;
	    ss >> m; // cantidad de aristas
	      cout<< "m="<< m <<endl;
	    ss >> origen; // nodo S
	      cout<< "origen="<< origen <<endl;
	    ss >> desti; // nodo T
	      cout<< "destino="<< desti <<endl;
	      
	    SMTPRed smtpr1(n);  
	    for (int i = 0; i< m; i++){
	        getline(cin, linea);
	        stringstream ss(linea);
	        ss >> v1; // origen del cable
	        ss >> v2; // destino del cable
	        ss >> lat; // latencia 
	        smtpr1.agregar_conex(v1, v2, lat); // conecto los nodos, 
	    }
	    smtpr1.mostrar_red();
	    
	    bool visit[n]; // Vector de nodos visitados
	    int infinito = m + 1;// el camino no puede ser mas largo que la cantidad de cables
	    
	      
	    for(auto it=smtpr1.adya_list[1].begin();it!=smtpr1.adya_list[1].end();it++){
	        int servidor=it->first; // first y second son usados para acceder al primer y al segundo elemento del par respect.
	        int lat=it->second;
	            
	            
	        cout<<"Servidorr : "<<servidor<<" Latenciaa : "<<lat<<endl;
	    }
	}
	
	return 0;
}
    /*
    //procear la respuesta
    DFS(int v) {
    visit[v] = true;    
     if (!visit[w]){
         for(auto it=smtpr1.adya_list[v].begin();it!=smtpr1.adya_list[v].end();it++){//Recorro la lista de adyacentes
            int u=it->first; // first y second son usados para acceder al primer y al segundo elemento del par respect.
            int lat=it->second;
            if (!visit[u])
                DFS(u);
        }
    }*/
    

	
	
	/*
  //graph of five vertices
  SMTPRed smtpr1(5);
  //adding edges
  smtpr1.agregar_conex(0,1,10);
  smtpr1.agregar_conex(1,2,20);
  smtpr1.agregar_conex(2,3,30);
  smtpr1.agregar_conex(1,3,40);
  smtpr1.agregar_conex(2,4,100);
  smtpr1.agregar_conex(4,0,10);
  //displaying the graph
  smtpr1.mostrar_red();*/





