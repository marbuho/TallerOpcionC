#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
class Queue
{
	private:
	 vector<int> vec;
	 
	public:
	void agregar(int numero)
	{
		vec.push_back(numero);
		
	}
    int sacar()
	 {
       	int aux =  vec.front();
       	vec.erase(vec.begin());
		return aux;
	}
	void clear(){
		vec.clear();
	}
	
};
class Heap
{
	private:
	 vector<int> vec;
	 
	public:
	void agregar(int numero)
	{
		vec.push_back(numero);
		
	}
	int sacar()
	{
		int max = -1;
		int j = 0;
		int auxmax;
		for (auto i = vec.begin(); i != vec.end(); ++i){
			if (*i > max){
				max = *i;
				auxmax= j;	
			} 
			j++;
		}
		vec.erase(vec.begin()+auxmax);	
		return max;	
	}	
	void clear(){
		vec.clear();
	}
	
};

class Pila
{
	private:
	 vector<int> vec;
	 
	 
	public:
	 void agregar(int numero)
	{
		vec.push_back(numero);
		
	}
	int sacar(){
		int aux =  vec.back();
       	vec.erase(vec.begin()+vec.size() -1);
		return aux;
	
		
	}	
	void clear(){
		vec.clear();
	}
	
};

int main(){
	Pila p;
	Heap h;
	Queue c;	
	map<string, int>estrd {{"stack",0}, {"queue",0}, {"heap",0}};
	int TC, tipo, valor;
	while (scanf("%d", &TC) != EOF){
		while(TC--){ 
			scanf("%d %d", &tipo, &valor); // 
			if(tipo == 2){
				for (auto it = estrd.begin(); it != estrd.end(); it++){
					
					if (it->second == -1) continue; // su ya se marco -1 se saltea.
					
					if (it->first == "stack"){
							estrd["stack"] = (p.sacar() == valor) ? 1 : -1;
					}
					else if(it->first == "queue"){
							estrd["queue"] = (c.sacar() == valor) ? 1 : -1;
					}
					else if(it->first == "heap") {
						estrd["heap"] = (h.sacar() == valor) ? 1 : -1;
					}
					else{
							estrd["stack"] = -1;
							estrd["heap"] = -1;
							estrd["queue"] = -1;
						
					}			
				}	
			}
			else{
				p.agregar(valor);
				c.agregar(valor);
				h.agregar(valor);
			}
			
		}
		int sum = 0;
			for (auto it = estrd.begin(); it != estrd.end(); it++)	{
				sum += it->second;
			}
			
			switch(sum){
				case -1:
					for (auto it = estrd.begin(); it != estrd.end(); it++)	{
						if (it->second == 1) {cout<< it->first<< endl; break;}
					}
				break;
				case -3:
					printf("imposible");
				break;
				case 1:
					printf("not sure");
				break;
				
			}
			//reinicio
			estrd["stack"] = 0;
			estrd["heap"] = 0;
			estrd["queue"] = 0;
			c.clear();
			p.clear();
			h.clear();
	}
			
		
			
}

		
		