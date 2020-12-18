#include "lcp.hpp"
#include <iostream>

namespace lcp
{

    int *find(int *arr, int *arr_end, int value) // returns int pointer
    {
        while (*arr != value && arr != arr_end) // as long as value pointed by the arr pointer is not the value
                                                // and arr != arr_end (addresses) are not the same, continue
            ++arr;                              // move arr pointer to the right every loop
        return arr;                             // returns the final pointer or some garbage pointer if not found
        // int *found{ find(std::begin(arr), std::end(arr), 3)}; this function is for this statement
        // find function takes int pointer that points to the begin and end of the array
        // std::begin(arr) == arr
        // std::end(arr) == arr + std::size(arr)
    }

    void Point2d::print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
    }

    int run() // For running the test code
    {
        Point2d first{};
        Point2d second{3.0, 4.0};
        std::cout << std::endl;
        first.print();
        second.print();
        return 0;
    }

} // namespace lcp