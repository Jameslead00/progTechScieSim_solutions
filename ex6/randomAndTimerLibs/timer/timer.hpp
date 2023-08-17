// TASK: Timer library
/* Create a Timer class that has three methods start, stop and duration. The
duration method should return the elapsed time (in seconds) between the calls to
start and stop. Throw an exception when the user misuses the library. Make
sure that the interface of the class is consistent with the one used in the benchmark
program. Document your code.
Use CMake to build and install the timer as a library. */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer{
    public:
        Timer();
        void start();
        void stop();
        double duration();
    
    private:
        using clock = std::chrono::high_resolution_clock;
        using time_point = clock::time_point;
        bool started_;
        bool running_;
        time_point tstart_;
        time_point tend_;


};



#endif
