#include <iostream>
#include <limits>

double get_epsilon();

int main(){
    std::cout << "Machine epsilon with bisection method: " << get_epsilon() << std::endl;
    std::cout << "Built in method: " << std::numeric_limits<double>::epsilon() << std::endl;
    return 0;
}

double get_epsilon(){
    const double one = 1;
    const double half = 0.5;
    double lower = 0;
    double upper = 1;
    double avg = 1;
    double avg_old = 0;

    while(avg_old != avg){
        avg_old = avg;
        avg = half * (upper + lower);
        if(one + avg == one){
            lower = avg;
        } else {
            upper = avg;
        }
    }
    return upper;
}