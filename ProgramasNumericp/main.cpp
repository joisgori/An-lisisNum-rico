#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double dydx (double x, double y)
    {
        double f = ((x-3)*(y+1))/((x+2)*(y-1));
        return f;
    }
int main()
{
    double a,b,alpha,h,z;
    cout<<"\nEnter the value of endpoint a: \n";
    cin>>a;
    cout<<"\nEnter the value of endpoint b: \n";
    cin>>b;
    cout<<"\nEnter the y value of the initial condition: \n";
    cin>>alpha;
    /*
     * Obtains step size from number on steps
     * h = 0.1 for [a; b] = [0; 8] can be given by n = 80
    */
    int n = 0;
    cout<<"\nEnter the number of steps, n: \n";
    cin>>n;
    h = (b - a) / n;
    //------
    cout<<"\n";
    //-- Replaced 0.0000001 by h / 2.0 --
    while((b-a)> h / 2.0)
    {
        z=alpha+(h*dydx(a,alpha));
        alpha=z;
        a=a+h;
        /* 
         * z - function value in next point, 
         * so to output correct point a need to be incremented before this.   
        */
        cout<<"z("<<a<<")="<<z<<endl;
    }
    cout<<"\nThe approximate solution of y("<<b<<") is "<<z<<"."<<endl;
    return 0;
}
