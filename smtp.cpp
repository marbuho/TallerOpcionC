#include <bits/stdc++.h>
using namespace std;

//clase para un grafo no dirigido pesado 

class SMTPRed
{
  vector< pair<int,int> > * adya_list; // un puntero a un vector que almacena pares
  int vertices; // cant de servidores
  public:
  SMTPRed(int n)
  {
    vertices=n;
    adya_list=new vector< pair<int,int> >[n]; //  n vectores, (1 para cada vertice, cada vector rep la lista de adyacencia,
    // el vec contiene elementos par, (u, lat) u es el vert de destino, y lat la latencia del cable, (peso de la arista)
  }
  void agregar_conex(int v1,int v2,int lat);
  void mostrar_red();
};

int main()
{
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
  smtpr1.mostrar_red();
  return 0;
}
//definición de metodos

void SMTPRed::agregar_conex(int v1,int v2,int lat)
{
  // conecttar v1 con v2 y viceversa
  adya_list[v1].push_back(make_pair(v2,lat));
  adya_list[v2].push_back(make_pair(v1,lat));
}

void SMTPRed::mostrar_red()
{
  int servidor,lat;
  //Para cada v, se muestra su lista de ady
  for(int i=0;i<vertices;i++)
  {
      cout<<"Ady lista del vertice "<<i<<endl;
    // para cada lista,  se muestra su contenido
    for(auto it=adya_list[i].begin();it!=adya_list[i].end();it++)
    {
      //setea  en servidor como el n de vertice, y lat, como la latencia del cable
      servidor=it->first; // first y second son usados para acceder al primer y al segundo elemento del par respect.
      lat=it->second;
      cout<<"Servidor : "<<servidor<<" Latencia : "<<lat<<endl;
    }
    cout<<endl;
  }
}
