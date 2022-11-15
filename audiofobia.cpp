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



using namespace std;

//clase para un grafo no dirigido con pesos

class Ciudad{
	public: //(conviene declararlas publicas, asi se acceden globalmente)
	vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
	int vertices; // cant de servidores

	// consutructor
	Ciudad(int n){
		vertices = n;
		adya_list = new vector< pair<int,int> >[n]; // n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
		// el vec contiene elementos par, (u, pol) u es el vert de destino, y pol el nivel de polucion, (peso de la arista)
	}
	void agregar_conex(int v1,int v2,int pol){
		// conecttar v1 con v2 y viceversa
		adya_list[v1].push_back(make_pair(v2,lat));
		adya_list[v2].push_back(make_pair(v1,lat));
	}
	
	int get_cant_aristas{
		int count = 0;
		for (int i = 0 i < vertices){
			count += adya_list[i].size(),
		}
		
		return cout * 0.5; // cada v tiene sus vecinos ( hay una arista doble en grafo no dirigido)
	}

};

int mininoverti_noproce(vector<int> vec, vector<bool> procesados);
int minCostDestino_dijkstra(SMTPRed red, int inicio, int destino);
void show(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q);

int main(){
	//printf("run.....\n");
	//ofstream myfile;
 	//myfile.open ("example2.txt");
    string line;
    int TC, C, S, Q, v1, v2, p, count, origen, destino;
    //leer entrada para armar la red:
    count = 1;
	while(true){
		stringstream ss(line);
		ss >> C;
		ss >> S;
		ss >> Q;
		
		if (C + S + Q == 0) break;
		
		Ciudad ciudad(C);
		stringstream ss(line);
		for (int i = 0; i < S; i++){
			getline(cin, line);
			ss >> v1;
			ss >> v2;
			ss >> p;
			ciuadad.agregar_conex(v1, v2, p);
		}
		
		if (count > 1) cout << endl; // dejar una linea en blanco entre casos
		
		stringstream ss(line);
		printf("Case #%d\n",count++);
		for (int i = 0; i < Q; i++){
			getline(cin, line);
			ss >> origen;
			ss >> destino;
			// calcular respuesta
			result = minMax(ciudad, origen, destino);
			if (result == 0)
				printf("no path\n",count++, result);
			else
				printf("%d\n",count++, result);
		}
		
	}
    //myfile.close();
    return 0;
}

int minMax(Ciudad ciudad, int origen, int destino){
	vec < pair<int, int> >
	//obtener una lista de aristas
	for(auto it=red.adya_list[u].begin(); it!=red.adya_list[u].end(); it++){
		
	}
	
	
	// convertirla a heap (asi se va sacando en orden no decreciente)
	// la min heap por default se ordena por el valor del primer elemento
    // by first element of pair.
    typedef pair<int, int> par_int;
	priority_queue<  par_int, vector<par_int>, greater<par_int > > minHeap; // se usa asi para poder definirla como MIN heap
	for (int i = 0; i < ciudad.get_cant_aristas()){
		
		minHeap.push(make_pair(10, 200));
		
		
	}
	for(auto it=red.adya_list[u].begin(); it!=red.adya_list[u].end(); it++){
		
	}
	
	
	//ordenar de forma no descreciente la lista de aristas
	int costo_mst = 0;
	// inciar conjuntos
	for (e: listaAristas){
		if (! conjunto(e.v1, e.v2)){
			costo_mst = costo_mst + peso de (v1,v2);
			//unir conjunto(v1) y conjunto(v2)
		}
	}
	return costo_mst;
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
