//Lagrange dos
#include <math.h>
#include <iostream>
#include <complex>
#include <iomanip>
using namespace std; 

void lagrange(){
    int n,i,j;
    float mult,sum=0,x[10],f[10],a;

    x[0] = 1950;
    x[1] = 1960;
    x[2] = 1970;
    x[3] = 1980;
    x[4] = 1990;
    x[5] = 2000;

    f[0] = 151326;
    f[1] = 179323;
    f[2] = 203302;
    f[3] = 226542;
    f[4] = 249633;
    f[5] = 281422;

    //IMPORTANTESSSSSSSSSS
    n = 6;

    a = 2020;

    for(i=0;i<=n-1;i++)
    {
        mult=1;
        for(j=0;j<=n-1;j++)
        {
            if(j!=i)
                mult*=(a-x[j])/(x[i]-x[j]);
        }
        sum+=mult*f[i];
    }
    cout<<"\nThe estimated value of f(x) = "<<sum;
}

main(void) {
	
	lagrange();
	// creating an array of 4 known data points 
  
    return 0;
}


