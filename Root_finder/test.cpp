#include <iostream>
using namespace std;
#include "RootFind.h"
#define LOG(x) std::cout << x << std::endl

int main()
{

     RootFind r;
     int n = 500;
     double a = -1, b = .2, c = 1;

     r.bisection(b,a,c,n); 
     LOG("hi");
     r.secant_method(a,c);
     LOG("hi");
     r.newtonRaphson(12);

    cin.get();
     return 0;
}