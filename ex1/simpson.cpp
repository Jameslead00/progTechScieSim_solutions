//simpson integration of sin(x) from 0 to pi
#include <iostream>
#include <cmath>

double integrate(double a, double b, unsigned int nbins);
double f(double x){
    return std::sin(x);
}

int main(){
    double a = 0;
    double b = M_PI;
    unsigned int nbins = 0;

    std::cout << "Enter n bins: \n";
    std::cin >> nbins;
    std::cout << "integral of sin(x) from 0 to pi = " << integrate(a, b, nbins) << std::endl;

    return 0;
}

//simpson integration
double integrate(double a, double b, unsigned int nbins){
    double dx = (b -a) / nbins;
    double I = 0.0;

    for(int i = 0; i < nbins; i++){
        double x0 = a + i*dx;
        double x1 = a + (i + 1)*dx;
        I += (f(x0) + 4.0 * f((x0+x1)/2.0) + f(x1)) * (dx / 6.0);
    }

    return I;
}
