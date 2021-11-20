#include <iostream>
#include <armadillo>
#include <cmath>
#include "LinSol.h"

using namespace std;
using namespace arma;

int main() {
    LinSol g;
    mat A = {{4, -2, 3},
             {1, 3, -4},
             {3, 1, 2}};

    vec b = {1,-7,5};

    g.backSub(A, b);
    return 0; 
}