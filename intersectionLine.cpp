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
// Estructura para un punto.
struct Point
{
	double x;
	double y;
};

// Estructura para una linea
struct Line{
    double a; /* x-coefficient */
    double b; /* y-coefficient */
    double c; /* constant term */
};
// funcion para calcuar distancia entre 2 puntos (2D)
double distancePoint(Point p1, Point p2){
	return sqrt(( (p2.x - p1.x) * (p2.x - p1.x) + (p1.y - p2.y) * (p1.y - p2.y) ) );

}

// funcion para detrminar si dos lineas son colineales "identicas"
bool parallelQ(line l1, line l2)
{
    const double EPSILON = 0.0001;
    return ( (abs(l1.a-l2.a) <= EPSILON) &&
    (abs(l1.b-l2.b) <= EPSILON) );
}

Line points_to_line(Point p1, Point p2){
    Line line;
    //recordar igualdad entre definiciones de lineas:
    
     // "ax + by + c = 0"  <=>  " - mx + y - n = 0"
     
    //caso linea vertical(evita la división por 0, pendiente infinita)
    // linea vertical: x=c 
    if (p1.x == p2.x) {
        line.a = 1;
        line.b = 0; 
        line.c = -p1.x;
    }
    else {
        line.b = 1;
        line.a = -(p1.y-p2.y)/(p1.x-p2.x); // calculo de m: pendiente
        line.c = -(line.a * p1.x) - (line.b * p1.y);
    }
    
    return line;
}




int main(){
    //ofstream myfile;
 	//myfile.open ("salida.txt");
	Point dog_p;
	Point goph_p;
	Point hole_p;
	Line line;


	
	//myfile.close();
	return 0;
}

	
