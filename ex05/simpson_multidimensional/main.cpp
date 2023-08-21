//simpso integration in 2d using Fubini's theorem

#include "simpson.hpp"
#include <iostream>
#include <cmath>

double unit_disk(const double x, const double y){
    return static_cast<double>(x*x+y*y <= 1);
}

double phi(const double x, const double y){
    return std::exp(-(x*x + y*y));
}

//funciton object for support domain
struct phi_wrapper{
    public:
        phi_wrapper(double R) : R2_(R*R){}
        double operator()(const double x, const double y) const{
            if(x*x+y*y <= R2_){ return phi(x,y);}
            return 0;
        }
        private:
            const double R2_;
};

template<typename T, typename F2D>
T integrate2d(T a, T b, const unsigned int nx, T c, T d, const unsigned ny, const F2D& f2d){
    auto F = [&] (T x) {
        return simpson(c, d, ny, [&] (T y) {return f2d(x, y); });
    };
    T I = simpson(a, b, nx, F);
  return I;
}

int main(){
    const double R = 1.7606;
    const unsigned int nbins = 1024;
    std::cout.precision(15);
    //check implementation by calculating pi
    std::cout << integrate2d(-1., 1., nbins, -1., 1., nbins, &unit_disk) << std::endl;

    //solve the problem without changing the 1d library
    auto phiR = phi_wrapper(R);
    std::cout << integrate2d(-R, R, nbins, -R, R, nbins, phiR) << std::endl;

    return 0;
}