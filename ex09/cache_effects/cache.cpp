/* Programming Techniques for Scientific Simulations, ETH Zurich
 */

#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>

using array_t = volatile int;
namespace timer = std::chrono;

int main() {
  constexpr size_t elem_size = sizeof(array_t);
  constexpr size_t MINSIZE = 2;
  constexpr size_t MAXSIZE = 2*2*2 * 1024 * 1024;  // 2^23
  constexpr size_t MAXSTEP = 2*2 *1024;            // 2^12
  constexpr size_t NUMOPS  = 20 * MAXSIZE;

  array_t* arr = new array_t[MAXSIZE];
  for(size_t N = MINSIZE; N < MAXSIZE; N *= 2) {
    for(size_t step = 1; step <= std::min(MAXSTEP, N); step *= 2) {

      const size_t num_steps = N / step;
      const size_t num_sweeps = NUMOPS / num_steps;

      for(size_t i = 0; i < N; ++i)
        arr[i] = 0;

      timer::time_point<timer::high_resolution_clock> start , stop;
      start = timer::high_resolution_clock::now();

      for(size_t sweep = 0; sweep < num_sweeps; ++sweep)
          for(size_t i = 0; i < N; i += step)
            arr[i]+= 1;


      stop = timer::high_resolution_clock::now();
      const double time = static_cast<timer::duration<double> >(stop-start).count();
      const double numops = num_steps * num_sweeps;

      std::cout << std::setprecision(12)
                << std::setw(16) << N * elem_size      // array size in bytes
                << std::setw(16) << step * elem_size   // touched bytes
                << std::setw(16) << time
                << std::setw(16) << numops
                << std::endl;
    }
  }

  delete[] arr;

  return 0;
}
