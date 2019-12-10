#include <cmath>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

long double pi = atan(1)*4;

long double df(long double x, long double y, int k){
    //long double derivatives[] = {(0.5*(1+x)*pow(y,2)), (0.5*pow(y,2)*(1+pow(1+x,2)*y))};
    //long double derivatives[] = {sin(5*x), 5*cos(5*x), -25*sin(5*x)};
    long double derivatives[] = { ((x-3)*(y+1))/((x+2)*(y-1)) };
    return derivatives[k-1];
}

int fact(int x){
    int f = 1;
    /*
    for(int i=1; i<=x; i++){
        f = f*i;
    }*/
    return f;
}

void taylor(long double x0, long double y0, long double h, int order, long double xEval){

    long double y = y0;
    long double x = x0;
    long double aux = 0;

    while(x <= xEval+h){
        cout << setprecision(9) << x << " | " << y << " | ";

        aux = y;

        for(int i=1; i <= order; i++){
            cout << df(x, y, i) << " | ";
            aux = aux + ((df(x, y, i)*pow(h,i))/fact(i));
        }

        y = aux;
        cout << endl;

        x = x + h;
    }

}

int main(){

    //taylor(0, 1, 0.1, 2, 0.5);
    //taylor(pi, 1, 0.001, 2, pi+1);
    taylor(0, 0, 0.001, 1, 1.0);

    return 0;
}
