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
	Point dog_p;
	Point goph_p;
	Point hole_p;
	int n_holes;
	bool escaped_goph = false;
	char msg_ok[100] = "The gopher can escape through the hole at (%.3f,%.3f).";
	printf("ingresar valores Nholes perro y ardilla\n");
	// ingresar coor del punto 1: separados por enter
	while (!cin.eof()){
		cin >> n_holes >> goph_p.x >> goph_p.y >> dog_p.x >> dog_p.y;
		printf("ingresar coor de holes\n");
		while (n_holes-- && !escaped_goph){
			cin >> hole_p.x >> hole_p.y;
			double dis_dog_hol = distancePoint(dog_p, hole_p);
			double dis_goph_hol = distancePoint(goph_p, hole_p);
			
			if (dis_goph_hol < (dis_dog_hol * 0.5) ){
				printf(msg_ok, hole_p.x, hole_p.y);
				escaped_goph = true;
			}
			
		}
		if (!escaped_goph)
			printf("The gopher cannot escape\n");
		
		cin.ignore();// ignorar sig linea
		
		
	}
	return 0;
}

	