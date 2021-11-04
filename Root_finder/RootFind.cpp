#include "RootFind.h"
#include <iostream>
#include<bits/stdc++.h>
#define EPSILON 0.0000001

using namespace std;

//default constructor
RootFind::RootFind() {
}

//function to find the root of 
 double RootFind::func(double x) {
    return x*x-2*x;
}

//implementation of bisection method
void RootFind::bisection(double xmid, double xstart, double xend, int n ) {

	for (int i = 0; i < n; i++)
	{
		double fstart = func(xstart);
        double fmid = func(xmid);
        //double fend = func(xend);
        if (func(xmid) == 0) { 
                break;
            }

        if (fstart*fmid < 0) {

            xend = xmid;
            xmid = (xmid + xstart)/2;
            xstart = xstart;

        } else {
            xstart = xmid;
            xmid = (xmid + xend)/2;
            xend = xend;
        }
	}

	cout << "The value of the root is : " << xmid;
    cout << endl;
    cout << "The value of the function at this location is: " << func(xmid);

};

// secant of the target function 
double RootFind::sec(double x0, double x1) {
	
	double secant = (func(x1)-func(x0))/(x1-x0);
	return secant;
}

//implementation of secant method 
void RootFind::secant_method(double x0, double x1) {

    double xold, h, iter = 0;

	while (abs(func(x1)-func(x0)) >= EPSILON)
	{
		h = func(x1)/sec(x0, x1);
		// x(i+1) = x(i) - f(x) / f'(x)
        xold = x1;
		x1 = x1 - h;
        x0 = xold;
        iter++;
	}

	cout << "The value of the root is : " << x1;
    cout << endl;
    cout << "number of iterations is : " << iter;
};

// Derivative of the above function using a central difference approximation (4th order)
double RootFind::derivFunc(double x) {
	double h = 10^-11;
	double deriv = (-func(x+2*h) + 8*func(x+h) - 8*func(x-h) + func(x-2*h))/(12*h);
	return deriv;
};

// Function to find the root using newtons method 
void RootFind::newtonRaphson(double x) {
	double h = func(x) / derivFunc(x);
    int iter = 0;

	while (abs(h) >= EPSILON)
	{
		h = func(x)/derivFunc(x);

		// x(i+1) = x(i) - f(x) / f'(x)
		x = x - h;
        iter++;

	}

	cout << "The value of the root is : " << x;
    cout << endl;
    cout << "number of iterations is : " << iter;
}