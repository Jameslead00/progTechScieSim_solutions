//Random library
/* Implement a linear congruential random number generator,
Xn+1 = (aXn+ c) mod m,
where m is the largest number that your generator will output. Xn, a and c are
integers and m > 0, 0 < a < m and 0 ≤c < m are constants. X0 is the initial seed.
You may use the following set of constants:
m = 232
a = 1664525
c = 1013904223
Make sure that the interface of the generator class is consistent with the one used
in the benchmark program.
Use CMake to build and install the random number generator as a library */

#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdint> // for std::uint32_t


class Generator{
    public:
        using result_t = std::uint32_t;

        Generator(result_t x_0 = 42);
        result_t generate();
        result_t max() const;


    private:
    using impl_t = std::uint64_t;

        impl_t x_;
        static impl_t const m_ = 1ull << 31;
        static impl_t const a_ = 1664525ull;
        static impl_t const c_ = 1013904223ull;

        static_assert(sizeof(result_t) <= sizeof(impl_t), "`impl_t` needs to be at least as big as `result_t`");
        static_assert(m_ > 0, "m > 0");
        static_assert(0 < a_ && a_ < m_, "0 < a < m");
        static_assert(0 <= c_ && c_ < m_, "0 <= c < m");
};

#endif