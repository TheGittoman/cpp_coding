#ifndef LCP_HPP
#define LCP_HPP

namespace lcp
{
    // 6.8a Pointer Arithmetic and array indexing
    // question #2
    int *find(int *arr, int *arr_end, int value) // returns int pointer
    {
        while(*arr != value && arr != arr_end)  // as long as value pointed by the arr pointer is not the value
                                                // and arr != arr_end (addresses) are not the same, continue
            ++arr;                              // move arr pointer to the right every loop
        return arr;                             // returns the final pointer or some garbage pointer if not found
        // int *found{ find(std::begin(arr), std::end(arr), 3)}; this function is for this statement
        // find function takes int pointer that points to the begin and end of the array
        // std::begin(arr) == arr
        // std::end(arr) == arr + std::size(arr)
    }
}

#endif