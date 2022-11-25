/* 
Sample Input
5
0 0 4 4 0 4 4 0
5 0 7 6 1 0 2 3
5 0 7 6 3 -6 4 -3
2 0 2 27 1 5 18 5
0 3 4 0 1 2 2 5

Sample Output
INTERSECTING LINES OUTPUT
POINT 2.00 2.00
NONE
Line
POINT 2.00 5.00
POINT 1.07 2.20
END OF OUTPUT*/

#include <bits/stdc++.h>
#include<string>


using namespace std;
double EPSILON = 0.00001;
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
bool parallel(Line l1, Line l2)
{
    return ( (abs(l1.a-l2.a) <= EPSILON) &&
    (abs(l1.b-l2.b) <= EPSILON) );
}

Line points_to_line(Point p1, Point p2){
    Line Line;
    //recordar igualdad entre definiciones de lineas:
    
     // "ax + by + c = 0"  <=>  " - mx + y - n = 0"
     
    //caso linea vertical(evita la división por 0, pendiente infinita)
    // linea vertical: x=c 
    if (p1.x == p2.x) {
        Line.a = 1;
        Line.b = 0; 
        Line.c = -p1.x;
    }
    else {
        Line.b = 1;
        Line.a = -(p1.y-p2.y)/(p1.x-p2.x); // calculo de m: pendiente
        Line.c = -(Line.a * p1.x) - (Line.b * p1.y);
    }
    
    return Line;
}


// chequear q l1 y l2  no sean  colineales paralelas. antes de usarla.
Point intersection_point(Line l1, Line l2)
{
	 Point p;
	// la ecuacion sale de A X + B Y + C de ambas lineas
	p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
	if (abs(l1.b) > EPSILON)// chequea q no sea linea vertical 
		p.y = - (l1.a * (p.x) + l1.c) / l1.b;
	else
		p.y = - (l2.a * (p.x) + l2.c) / l2.b;
	return p;
}

bool same_line(Line l1, Line l2){
	return ( parallel(l1, l2) && ( abs(l1.c - l2.c) <=EPSILON ) );
}


int main(){
    ofstream myfile;
 	myfile.open ("salida.txt");
	Point p1, p2, p3, p4, inter;
	Line l1, l2;
	int TL;
	printf("INTERSECTING LINES OUTPUT\n");
	//myfile << "INTERSECTING LINES OUTPUT" << endl;
	cin >> TL;
	while(TL--){
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
		l1 = points_to_line(p1, p2);
		l2 = points_to_line(p3, p4);
		if( same_line (l1,l2) ){
			printf("LINE\n");
			//myfile << "LINE" << endl;
		}
		else if(parallel(l1, l2) ){
			printf("NONE\n");
			//myfile << "NONE" << endl;
		}
		else{
			inter = intersection_point(l1, l2);
			printf("POINT %.2f %.2f\n", inter.x, inter.y);
			//myfile << "POINT "<< inter.x << " " << inter.y << endl;
		}
	}
	printf("END OF OUTPUT\n");
	//myfile << "END OF OUTPUT" << endl;
	
	//myfile.close();
	return 0;
}

	
