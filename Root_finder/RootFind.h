// the root find class is class of functions that compiles methods of root finding into one class
#ifndef ROOTFIND_H
#define ROOTFIND_H

class RootFind {
    public:
        double func(double x);

        double sec(double x0, double x1);

        RootFind();
        
        void bisection(double xmid, double xstart, double xend, int n);

        void secant_method(double x0, double x1);

        double derivFunc(double x);

        void newtonRaphson(double x);
};


#endif