//machine epsilon using templates

#include <iostream>
#include <limits>

/*
The bisection method gets the true value of epsilon as
defined in the lecture. Note that this is not the same
as std::numeric_limits<double>::epsilon(). The reason
for this is that we define epsilon as the smallest
number such that 1 + epsilon != 1, whereas numeric_limits
uses the definition that the smallest
number larger than 1 is 1 + epsilon. This is different
because in our definition 1 + epsilon doesn't have to
be representible as a double, it just has to be rounded
(up) to a value other than 1.
*/
template <typename T>
T machine_epsilon_bisection(){
    T lower{0.0};
    T higher{1.0};
    const T one{1.0};
    T old_eps{0.0};
    T eps{1.0};

    while(old_eps != eps){
        old_eps = eps;
        eps = (higher + lower)/static_cast<T>(2.0);
        if(one + eps == one){
            lower = eps;
        } else {
            higher = eps;
        }
    }
    return higher;
}

int main(){
    std::cout << "machine epsilon for float: " << machine_epsilon_bisection<float>() << std::endl;
    std::cout << "machine epsilon for double: " << machine_epsilon_bisection<double>() << std::endl;
    std::cout << "machine epsilon for long double: " << machine_epsilon_bisection<long double>() << std::endl;

}
