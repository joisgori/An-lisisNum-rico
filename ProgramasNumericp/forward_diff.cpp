#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;


using namespace std;
//aca va la funcion
long double f(long double x){
	return log(pow(cos(x),2.0));
}

long double forward_diff(long double x, long double h, int k){
	if(k == 0) return f(x);
	else return forward_diff(x+h, h, k-1)- forward_diff(x, h, k-1);
}

long double central_diff(long double x, long double h, int k){
	if(k == 0) return f(x);
	else return central_diff(x+h/2.0, h, k-1) - central_diff(x-h/2.0, h, k-1);
}

int main(){
	// forward_diff(x,h,derivada)/pow(h,derivada) 
    //ejercicio A recorda cambiar la funcion en return sin(x)
	cout << setprecision(10) << forward_diff(M_PI/4, 0.0001, 3)/pow(0.0001,3) << endl;
	//ejercicio B recorda cambiar la funcion en return log(x)
	//cout << setprecision(10) << forward_diff(1.0,0.0001,4)/pow(0.0001,4) << endl;
	
	//---------------
	cout << setprecision(10) << central_diff(M_PI/4, 0.0001, 3)/pow(0.0001,3) << endl;
	
	/*
	Básicamente necesitamos usar pascal según la derivada que nos pidan, y así vamos creando el pol...
	*/
    return 0;
}
