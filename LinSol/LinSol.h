#ifndef LINSOL_H
#define LINSOL_H
#include <armadillo>
using namespace arma;

class LinSol {
    public:
    
    LinSol();
    
    double backSub(mat A, vec b);

};

#endif
