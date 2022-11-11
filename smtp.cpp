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

using namespace std;

//clase para un grafo no dirigido pesado

class SMTPRed{
public:
vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
int vertices; // cant de servidores


SMTPRed(int n){
vertices=n;
adya_list= new vector< pair<int,int> >[n]; // n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
// el vec contiene elementos par, (u, lat) u es el vert de destino, y lat la latencia del cable, (peso de la arista)
}
void agregar_conex(int v1,int v2,int lat){
// conecttar v1 con v2 y viceversa
adya_list[v1].push_back(make_pair(v2,lat));
adya_list[v2].push_back(make_pair(v1,lat));
}
/*void mostrar_red(){
    int servidor,lat;
//Para cada v, se muestra su lista de ady
for(int i=0;i cout<<"Ady lista del vertice "< // para cada lista, se muestra su contenido
    for(auto it=adya_list[i].begin();it!=adya_list[i].end();it++){
    //setea en servidor como el n de vertice, y lat, como la latencia del cable
    servidor=it->first; // first y second son usados para acceder al primer y al segundo elemento del par respect.
    lat=it->second;
    cout<<"Servidor : "<
    }
    cout< }
}*/
};
int COSTOMIN(SMTPRed red, int inicio, int destino);
int MIN(SMTPRed red, int inicio, int destino, bool visitados[], int min, int costo);

int main(){
    string linea;
    int TC, n,m, origen,desti, v1, v2, lat;
    //leer entrada para armar la red:
    scanf("%d", &TC);
    int c = 1;
    while (TC--){/*
    getline(cin, linea);
    stringstream ss(linea);
    ss >> n;
    //cout<< "n="<< n < ss >> m; // cantidad de aristas
    //cout<< "m="<< m < ss >> origen; // nodo S
    //cout<< "origen="<< origen < ss >> desti; // nodo T
    //cout<< "destino="<< desti < */
    scanf("%d%d%d%d", &n, &m, &origen, &desti);
    SMTPRed smtpr1(n);
    for (int i = 0; i< m; i++){
        scanf("%d%d%d", &v1, &v2, &lat);
        /*getline(cin, linea);
        stringstream ss(linea);
        ss >> v1; // origen del cable
        ss >> v2; // destino del cable
        ss >> lat; // latencia */
        smtpr1.agregar_conex(v1, v2, lat); // conecto los nodos,
        }
    
    
        
        if (n==0 || m==0){
        printf("Case #%d: unreachable\n",c++);
        }
        else{
            int result = COSTOMIN(smtpr1, origen, desti);
        
            if (result == 999999999)
                 printf("Case #%d: unreachable\n", c++);
            else
                printf("Case #%d: %d\n", c++, result);
        }
    
    }
    
    return 0;
}
    //procear la respuesta
    int COSTOMIN(SMTPRed red, int inicio, int destino) {
        printf("procesando.....\n");
        
        bool visitados[red.vertices]; // Vector de nodos visitados
        int costo = 0;
        int min= 999999999; // nunca va a ser mayor a la cant de aristas
        
        min = MIN(red, inicio, destino, visitados, min, costo);
        
        return min;
    }
    int MIN(SMTPRed red, int inicio, int destino, bool visitados[],
        int min, int costo){
        
        for(auto it=red.adya_list[inicio].begin(); it!=red.adya_list[inicio].end(); it++){
            int w = it->first;
            int lat = it->second;
            if (!visitados[w]) {
                visitados[w] = true;
                if (w != destino){
                min = MIN(red, w, destino, visitados, min, costo+lat);
        
                }
                else if(costo + lat < min){
                    min = costo + lat;
                 }
                 
            visitados[w] = false;
        }
    }
        
        return min;
    }
