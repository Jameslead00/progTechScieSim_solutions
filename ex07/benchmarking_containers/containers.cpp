#include "timer/timer.hpp"
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <set>
#include <iostream>

using test_type = unsigned long;

template<class C>
void fill_container(const size_t & num_ops, C & container){
    typename C::iterator it;

    for(size_t i = 0; i < num_ops; i++){
        it = container.insert(container.begin(), 0);
        container.erase(it);
    }
}

template<typename C>
double measure_container(const size_t& num_ops, const std::vector<test_type>& input){
    Timer t;

    C container(input.cbegin(), input.cend());

    t.start();
    fill_container(num_ops, container);
    t.stop();

    //output in nanoseconds
    return 1e9 * t.duration() / num_ops;
}

int main(){
    const size_t num_ops = 4e06;

    std::cout
        << std::right << "# "
        << std::setw(4)  << "N" << ' '
        << std::setw(13) << "Vector[ns/op]" << ' '
        << std::setw(13) << "List[ns/op]"   << ' '
        << std::setw(13) << "Set[ns/op]"    << '\n'
    ;
    for(unsigned i = 4; i < 14; i++){
    const size_t size = 1ul << i; // == std::pow(2, i)

        std::vector<test_type> input(size);
        for(size_t i=0; i < input.size(); ++i) {
            input[i] = i+1;
        }

        std::cout
            << std::right << std::fixed << std::setprecision(6) << "  "
            << std::setw(4) << size << ' '
            << std::setw(13)
            << measure_container<std::vector<test_type>>(num_ops, input) << ' '
            << std::setw(13)
            << measure_container<std::list<test_type>>(num_ops, input) << ' '
            << std::setw(13)
            << measure_container<std::set<test_type>>(num_ops, input) << '\n'
        ;
    }

    return 0;
}