#include "timer.hpp"
#include <chrono>
#include <stdexcept> //for std::runtime_error

Timer::Timer() : started_(false), running_(false) {}

void Timer::start(){
    if(running_){
        throw std::runtime_error("Can't start an already running timer");
    }
    started_ = true;
    running_ = true;
    tstart_ = clock::now();
}

void Timer::stop(){
    if(!running_){
        throw std::runtime_error("Can't stop not running timer");
    }
    tend_ = clock::now();
    running_ = false;
}

double Timer::duration(){
    if(!started_){
        throw std::runtime_error("no duration if not started");
    }
    return std::chrono::duration<double>(tend_ - tstart_).count();
}