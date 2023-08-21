/* This is a warmup exercise where we calculate the factorial n! = n·(n−1) ·(n−2) ...3 ·2 ·1
(note that 0! = 1) at compile time. Use class templates to implement the loop through
recursion and realize the ending condition through specialization. */
#include <iostream>

template<size_t N>
struct factorial{
    enum{value = N * factorial<N-1>::value};
};

template<>
struct factorial<0>{
    enum{value = 1};
};

int main(){
    std::cout << "Factorial:" << std::endl;
    std::cout << "    5!=" << factorial<5>::value << std::endl;
    std::cout << "    20!=" << factorial<20>::value << std::endl;
    std::cout << "    21!=" << factorial<21>::value << std::endl;
    std::cout << "    70!=" << factorial<70>::value << std::endl;
    return 0;
}

