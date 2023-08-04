//simpson library implementation

#include "simpson.hpp"
#include <iostream>
#include <cmath>


//simpson integration
double integrate(double a, double b, unsigned int nbins, double (*function) (double)){
    double dx = (b -a) / nbins;
    double I = 0.0;

    for(unsigned int i = 0; i < nbins; i++){
        double x0 = a + i*dx;
        double x1 = a + (i + 1)*dx;
        I += (function(x0) + 4.0 * function((x0+x1)/2.0) + function(x1)) * (dx / 6.0);
    }

    return I;
}