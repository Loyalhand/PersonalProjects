#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
  {
  mat A(4, 5, fill::randu);
  mat B(4, 5, fill::randu);
  
  cout << A*B.t() << endl;
  cin.get();
  return 0;
  }
