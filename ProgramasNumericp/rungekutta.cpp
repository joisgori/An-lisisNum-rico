// Example program
#include <iostream>
#include <string>
#include <cmath>
// C program to implement Runge Kutta method 
#include<stdio.h> 
#include <iomanip> 
using namespace std;
  
// A sample differential equation "dy/dx = (x - y)/2" 
float dydx(float x, float y) 
{ 
	//Acá coloco la función que me den
    return ((5*(pow(x,2)))-y)/exp(x+y); 
} 
  
// Finds value of y for a given x using step size h 
// and initial value y0 at x0. 
float rungeKutta(float x0, float y0, int a,int b, float h) 
{ 
    // Count number of iterations using step size or 
    // step height h 
    int n = (int)((b-a) / h); 
  
    float k1, k2, k3, k4, k5; 
  
    // Iterate for number of iterations 
    float y = y0; 
    for (int i=1; i<=n; i++) 
    { 
		
        cout<<setprecision(10)<<x0<< '\t' <<y<<endl;
        // Apply Runge Kutta Formulas to find 
        // next value of y 
        k1 = h*dydx(x0, y); 
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1); 
        k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2); 
        k4 = h*dydx(x0 + h, y + k3); 
  
        // Update next value of y 
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 
  
        // Update next value of x 
        x0 = x0 + h; 
    } 
    cout<<setprecision(10)<<x0<< '\t' <<y<<endl;
    return y; 
} 
  
// Driver method 
int main() 
{ 
//X0 valor inicial de x, valor inicial en y, límites a y b, y luego el salto(h)
    float x0 = 0, y = 1, a=0,b=1, h = 0.1; 
    printf("\nThe value of y at x is : %f", 
            rungeKutta(x0, y, a, b, h)); 
    return 0; 
} 
