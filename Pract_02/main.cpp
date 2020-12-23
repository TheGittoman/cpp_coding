#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/leetcode.hpp"
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include "src/test_arr.hpp"
// two arrays array and array_small accessable by Test:: namespace small is -9 - 9 array is 0 - 5000
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <chrono>

int main()
{
    using namespace LC;
    Timer time;
    LC::Head head;
    // 1 2 3 4 6
    head.addAtHead(100);
    head.addAtHead(1100);
    head.addAtHead(1600);
    head.addAtHead(1200);
    head.addAtHead(1500);
    head.addAtTail(2);
    head.addAtTail(5);
    head.printList();
    head.recRevPrint(head.getNode());
    std::cout << std::endl;
    head.recForwPrint(head.getNode());
    std::cout << std::endl;
    head.reverseRec(head.getNode());
    head.printList();

    std::cout
        << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
    system("pause");
    return 0;
}

// arr[i] = *(arr + i)
// *arr[i] = **(arr + i)