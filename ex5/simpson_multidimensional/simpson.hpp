//simpson integration with function objects

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cassert>

template<typename F, typename T>
T simpson(const T a, const T b, const unsigned nbins, const F& func){
    assert(nbins > 0);

    const T dr = (b - a) / (2.0 * nbins);
    T I2(0), I4(0);
    T pos = a;

    for(unsigned int i = 0; i < nbins; i++){
        pos += dr;
        I4 += func(pos);
        pos += dr;
        I2 += func(pos);
    }
    return (func(a) + 2.0 * I2 + 4.0 * I4 - func(b)) * (dr / 3.0);
}



#endif