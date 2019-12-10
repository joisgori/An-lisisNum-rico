// C++ program for implementation of Lagrange's Interpolation 
#include<bits/stdc++.h> 
using namespace std; 
  
// To represent a data point corresponding to x and y = f(x) 
struct Data 
{ 
    int x, y; 
};

// function to interpolate the given data points using Lagrange's formula 
// xi corresponds to the new data point whose value is to be obtained 
// n represents the number of known data points 
double interpolate(Data f[], int xi, int n) 
{ 
    double result = 0.0; // Initialize result 
  	
    for (int i=0; i<n; i++) 
    { 
        // Compute individual terms of above formula 
        double term = f[i].y;
        for (int j=0;j<n;j++) 
        { 
            if (j!=i) 
                term = term*(xi - f[j].x)/double(f[i].x - f[j].x); 
        } 
  
        // Add current term to result 
        result += term;
    } 
  
    return result; 
} 

main(void) {
	// creating an array of 4 known data points 
    Data f[] = {{1950, 151326}, {1960, 179323}, {1970, 203302}, {1980, 226542}, {1990, 249633}, {2000, 281422}}; 
  
    // Using the interpolate function to obtain a data point 
    // corresponding to x=3 
    cout << "Value of f(3) is : " << interpolate(f, 2020, 6); 
  
    return 0;
}


