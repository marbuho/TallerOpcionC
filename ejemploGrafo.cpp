#include <iostream>
#include<list>
using namespace std;

class graph{
public:
    list< pair<int,int> > *adjlist;
    int n;
    graph(int v){
        adjlist=new list< pair<int,int> > [v];
        n=v;
    }

    void addedge(int u,int v, int p){
        adjlist[u].push_back(make_pair(v, p));
        adjlist[v].push_back(make_pair(u, p));
        
    }

    void print(){
        for(int i=0;i<n;i++){
            cout<<i<<"-->";
            for(auto it:adjlist[i]){
            	int u = it.fisrt;
            	int p = it.second;
                cout<<"("<< u << ","<<p<<")"<< "  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};

int main() {
    graph g(5);
    g.addedge(1,2,true);
    g.addedge(4,2,true);
    g.addedge(1,3,true);
    g.addedge(4,3,true);
    g.addedge(1,4,true);

    g.print();
}