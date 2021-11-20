#include <iostream>
#include <armadillo>
#include <cmath>
#include "LinSol.h"

using namespace std;
using namespace arma;

LinSol::LinSol() { 

}

double LinSol::backSub(mat A, vec b) {

    int ii, jj, kk, n = A.n_cols;

    int k = 0, p = 0;

    double sum, dummy, factor, big = abs(A(k, k));

    double *ptr = &dummy, *f = &factor;

    vec x(n);

    cout << "The 'A' matrix is:" <<endl;
    cout << A << endl;
    cout << "The 'b' vector is:" << endl << b << endl;

   for (int ii = 0; ii < n; ii++) {
       *ptr = abs(A(ii,k));
       if (*ptr>big) {
           big = *ptr;
           p = ii;
       }
   }
    if (p!=k) {
        for (int jj = k; jj<n; jj++) {
            *ptr = A(p,jj);
            A(p,jj) = A(k,jj);
            A(k,jj) = *ptr;
        }
        *ptr = b(p);
        b(p) = b(k);
        b(k) = *ptr;
    }
    for (int ii = 0; ii<n; ii++) {
        for (int jj = ii+1; jj<n; jj++) {
            *f = A(jj,ii)/A(ii,ii);
            for (int kk = 1; kk<n; kk++) {
                A(jj,kk)=A(jj,kk)-*f*A(ii,kk);
            }
            b(jj)=b(jj)-*f*b(ii);
        }
    }
    x(n-1) = b(n-1)/A(n-1,n-1);
    for (int ii=(n-2); ii>=0; ii--) {
        sum = b(ii);
        for (int jj=ii+1; jj<n; jj++) {
            sum = sum - A(ii,jj)*x(jj);
        }
        x(ii)=sum/A(ii,ii);
    }
    
    cout << "The solution vector is:" << endl << x << endl;

    return 0;
    // return x by turning x into an array and return pointer
}
