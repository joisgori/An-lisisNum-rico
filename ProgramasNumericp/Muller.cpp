/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 16 de mayo de 2019, 05:11 PM
 */

#include <math.h>
#include <iostream>
#include <complex>
#include <iomanip>

using std::cout;	using std::endl;
using std::complex;	using std::pow;
using std::sqrt;	using std::abs;
using std::exp;		using std::cos;
using std::setprecision;
//using std::real;	
//using std::imag;

//Colocar aquí la función
inline complex<double> f(complex<double> x){
	return (pow(x,4.0)-(16.0*pow(x,3.0))+(78.0*pow(x,2.0))-(412.0*x)+624.0);	
}

int main(){
	//------------------ Valores iniciales ------------------
	complex<double> p0(0.0, 2.5);
	complex<double> p1(0.0, 3.0);
	complex<double> p2(0.0, 4.0);
	//------------------ Valores iniciales ------------------		
	
	complex<double> h1 = p1 - p0;
	complex<double> h2 = p2 - p1;
	complex<double> delta1 = (f(p1) - f(p0))/h1;
	complex<double> delta2 = (f(p2) - f(p1))/h2;
	complex<double> d = (delta2 - delta1)/(h2 + h1);
	complex<double> b(0, 0);
	complex<double> D(0, 0);	
	complex<double> E(0, 0);	
	complex<double> h(0, 0);
	complex<double> p(0, 0);	
	
	for(int i = 1; i <= 1000; i++){
		b = delta2 + h2*d;
		D = sqrt( pow(b, 2.0) -4.0*d*f(p2) );
	
		if( abs(b - D) < abs(b + D) ) E = b + D;
		else E = b - D;

		h = (-2.0*f(p2))/E;
		p = p2 + h;
		  
		cout << setprecision(8) << i << ": " << "p0: " << p0 << " p1: " << p1 << " p2: " <<  p2 << " p: " << p << " Eabs: " << abs(h) << endl;
		
                //Tolerancia
		if(abs(h) < abs(pow(10, -6.0))){
			cout << "Luego de " << i <<" iteraciones." << endl;
			break;
		}		

		p0 = p1;
		p1 = p2;
		p2 = p;
		h1 = p1 - p0;
		h2 = p2 - p1;
		delta1 = (f(p1) - f(p0))/h1;
		delta2 = (f(p2) - f(p1))/h2;
		d = (delta2 - delta1)/(h2 + h1);
	}

	//complex<double> mycomplex(1.0, 5.0);
	//	cout << f(mycomplex) << endl;	
}


