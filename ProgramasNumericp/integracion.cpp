#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

inline long double f (long double x){
    return (sqrt(2.0)*pow(0.99501247919268,(pow(x-50.0,2.0)))) / (20.0 * sqrt(M_PI)); //return (sqrt(2)*pow(0.99501247919268,(pow(x-50,2)))) / (20 * sqrt(M_PI))
    //pow(x,5.0/2.0) * exp(-x);
}

long double ctrapezlum(long double a, long double b, int n){
    long double h=(b-a)/n;
    long double sum = 0.0;
    for (int i =1; i<n; i++) sum += f(a+i*h);
    return(f(a)+2.0*sum+f(b))*(h/2.0);
}

long double csimpson(long double a, long double b, int n){
    long double h=(b-a)/n;
    long double sum1 = 0.0;
    long double sum2 = 0.0;
    for (int i =1; i<n/2; i++) sum1 += f(a+2.0*i*h);
    for (int i =1; i<=n/2; i++) sum2 += f(a+(2.0*i-1)*h);
    return(h/3.0)*(f(a)+2.0*sum1+4.0*sum2+f(b));
}

int main(){
    
	cout << setprecision(10) << csimpson(45,62,500) << endl;
    //cout << setprecision(10) << ctrapezlum(0,3,6) << endl;
}
