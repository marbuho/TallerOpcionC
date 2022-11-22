/* 
Input
1 1.000 1.000 2.000 2.000
1.500 1.500

2 2.000 2.000 1.000 1.000
1.500 1.500
2.500 2.500
output:

The gopher cannot escape.
The gopher can escape through the hole at (2.500,2.500)*/


#include <bits/stdc++.h>
#include<string>

using namespace std;

struct Point
{
	double x;
	double y;
};

double distancePoint(Point p1, Point p2){
	return sqrt(( (p2.x - p1.x) * (p2.x - p1.x) + (p1.y - p2.y) * (p1.y - p2.y) ) );

}



int main(){
    //ofstream myfile;
 	//myfile.open ("salida.txt");
	Point dog_p;
	Point goph_p;
	Point hole_p;
	int n_holes;
	double x_holeOK;
	double y_holeOK;
	bool escaped_goph = false;
	char msg_ok[100] = "The gopher can escape through the hole at (%.3f,%.3f).\n";
	//printf("ingresar valores Nholes perro y ardilla\n");
	
	while (cin >> n_holes){
		cin >> goph_p.x >> goph_p.y >> dog_p.x >> dog_p.y;
		//printf("ingresar coor de holes\n");
		while (n_holes--){
			cin >> hole_p.x >> hole_p.y;
			// calculo distancia de c/u al hole
			double dis_dog_hol = distancePoint(dog_p, hole_p);
			double dis_goph_hol = distancePoint(goph_p, hole_p);
			
			if (!escaped_goph && dis_goph_hol  <= (dis_dog_hol * 0.5) ){
			    x_holeOK = hole_p.x;
			    y_holeOK = hole_p.y;
				escaped_goph = true; // ya no vuelve a entrar al if se queda con el 
				                     //primer hole que cumple
			}
		}
		    
		if (!escaped_goph){
		    //myfile << "The gopher cannot escape." <<endl;
			printf("The gopher cannot escape.\n");
		}
		else{
		    //myfile << "The gopher can escape through the hole at ("
		     //       <<x_holeOK<<","<<y_holeOK<< ")"<<endl;
			printf(msg_ok, x_holeOK, y_holeOK);
		}
			
	    escaped_goph = false;
		//cin.ignore();// ignorar sig linea en blanco
		
		
	}
	//myfile.close();
	return 0;
}

	
