#include "integrator/simpson.hpp"

#include <cmath>
#include <iostream>

double my_sin(double value){
    return std::sin(value);
}

int main(){
    int nbins = 0;
    std::cout << "Enter n bins: \n";
    std::cin >> nbins;
    std::cout << "integral of sin(x) from 0 to pi = " << integrate(0, M_PI, nbins, my_sin) << std::endl;

    return 0;
}
