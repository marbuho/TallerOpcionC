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


#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <queue>
#include <iostream>
#include <fstream>



using namespace std;

//clase para un grafo no dirigido con pesos

class SMTPRed{
	public: //(conviene declararlas publicas, asi se acceden globalmente)
	vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
	int vertices; // cant de servidores

	// consutructor
	SMTPRed(int n){
		vertices = n;
		adya_list = new vector< pair<int,int> >[n]; // n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
		// el vec contiene elementos par, (u, lat) u es el vert de destino, y lat la latencia del cable, (peso de la arista)
		}
		void agregar_conex(int v1,int v2,int lat){
		// conecttar v1 con v2 y viceversa
		adya_list[v1].push_back(make_pair(v2,lat));
		adya_list[v2].push_back(make_pair(v1,lat));
	}

};

int mininoverti_noproce(vector<int> vec, vector<bool> procesados);
int minCostDestino_dijkstra(SMTPRed red, int inicio, int destino);
void show(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q);

int main(){
	//printf("run.....\n");
	//ofstream myfile;
 	//myfile.open ("example2.txt");
    string linea;
    int TC, n,m, origen,desti, v1, v2, lat;
    //leer entrada para armar la red:
    scanf("%d", &TC); // lee la cantidad de test 
    int c = 1;
    while (TC--){
	    scanf("%d%d%d%d", &n, &m, &origen, &desti); // lee 4 numeros por fila, n m S T
	    SMTPRed red(n); // red con n servidores
	    // armar las conexiones
	    for (int i = 0; i< m; i++){
	        scanf("%d%d%d", &v1, &v2, &lat);
	        red.agregar_conex(v1, v2, lat); // conecto los nodos,
	    }
    	
    	// casos extremos: 
        if (n==0 || m==0){
        	//myfile << "Case #"<< c << ": unreachable"<<endl;
			printf("Case #%d: unreachable\n",c++);
			continue; // si no hay nodos o no hay conexiones, saltea el caso
        }
        
        
        int result = minCostDestino_dijkstra(red, origen, desti);
        if (result == INT_MAX){
        	//myfile << "Case #"<< c << ": unreachable" <<endl;
        	printf("Case #%d: unreachable\n",c++);
		}
		else{
			//myfile << "Case #"<< c << ": " << result<<endl;
			printf("Case #%d: %d\n",c++, result);
		}
       
    
    }
    //myfile.close();
    return 0;
}
    //procear la respuesta
int minCostDestino_dijkstra(SMTPRed red, int inicio, int destino) {
	//printf("procesando.....\n");
	int n = red.vertices; 
	
	vector<bool> procesados(n); // (index de los  procesados, poner en true, cuando se visita )
	vector<int> distanciasmin(n);
	typedef pair<int, int> par_int;
	priority_queue<  par_int, vector<par_int>, greater<par_int > > minHeap; // se usa asi para poder definirla como MIN heap
   
	// el primer elemento a procesar sera el inicio, lo agrego ala heap
	minHeap.push(make_pair(0, inicio));
	//show(minHeap);

// poner "infinito" en el vector de distancias min"
	fill(distanciasmin.begin(), distanciasmin.end(), INT_MAX);
	
	
	distanciasmin.at(inicio) = 0; // la distancia min del origen del recorrido es 0
	while (!minHeap.empty() ){ // se repite n veces (n cantidad de nodos)
		//int u = mininoverti_noproce(distanciasmin, procesados); // obtendra el verti tenga menor distancia
		// reemplzar sacadno el top de la min heap (la heap ya no tendra este v)
		int u = minHeap.top().second; // tomo el v de dist min no procesado, (el primero sera v=inicio, xq Dv=0)
		procesados.at(u) = true; // marco el v como procesado. (el index 0 es el v=1)
		minHeap.pop(); //lo elimino de la heap
		//printf("EL minimo no procesado u es %d\n", u);
		
		//printf("se lo marca como procesado\n");
		for(auto it=red.adya_list[u].begin(); it!=red.adya_list[u].end(); it++){
			int w = it->first;
            int lat = it->second;
            	//printf("para el vecino w = %d se fija si tiene que actualizar\n", w);
			if (!procesados[w]){
			//	printf("distanciasmin.at(%d) > distanciasmin.at(%d) + lat ??\n",w ,u);
				if(distanciasmin.at(w) > distanciasmin.at(u) + lat){
				
					//printf("resulto que si tine q actualizar\n");
					distanciasmin.at(w) = distanciasmin.at(u) + lat;
				//	printf("ahora la distancia a w %d es %d \n", w, distanciasmin.at(w) );
					minHeap.push(make_pair(distanciasmin.at(w) ,w));
				}
			}
		}
	}
	
	return distanciasmin.at(destino);
	

}

int mininoverti_noproce(vector<int> vec, vector<bool> procesados){
	int min = INT_MAX;
	int indexmin = -1;
	for (int i = 0; i < vec.size(); i++){
		if (procesados.at(i)) continue;
		if (vec.at(i) < min){
			min = vec.at(i);
			indexmin = i;
		}
	}

	return indexmin;
}

void show(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q)
{
    //Copying the Priority Queue into another to maintain the original Priority Queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh = q;

    while (!mh.empty())
    {
        cout << "valor: " << mh.top().first  << "vertice: "<< mh.top().second << endl ; //printing the top most element
        mh.pop();                 //deleting the top most element to move to the next
    }

    cout << endl;
}
