#include <libTimer.a>
#include <libRandom.a>

#include <iostream> // for std::cout
#include <cstddef> // for std::size_t

int main() {
    std::size_t const N = 1000000000;
    int const seed = 42;

    Timer t;
    Generator rng(seed);
    double s = 0.0;

    t.start();
    for (std::size_t n = 0; n < N; ++n) {
        s += static_cast<double>(rng.generate()) / rng.max();
    }
    t.stop();

    s /= N;

    std::cout
        << "Mean of the random number engine is: " << s << ".\n"
        << "Computed " << N << " iterations in " << t.duration() << " seconds." << std::endl;
}
