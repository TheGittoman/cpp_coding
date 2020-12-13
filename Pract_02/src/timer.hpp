#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <chrono>

using namespace std::chrono;
class Timer
{
private:
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
public:
    Timer()
    {
        t1 = high_resolution_clock::now();
    }
    void clear()
    {
        t1 = high_resolution_clock::now();
    }
    void stop()
    {
        t2 = high_resolution_clock::now();
        duration<long double> time_span = duration_cast<duration<long double>>(t2 - t1);
        std::cout << "Time took to run the function/program: " << time_span.count() << " seconds.";
        std::cout << std::endl;
    }
};


#endif