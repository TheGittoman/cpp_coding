#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray
// functio
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>
#include <climits>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main() {
  Timer time;
  // Start timer
  // End timer
  fmt::print("Program has taken: {} seconds to run\n", time.elapsed());
  system("pause");
  return 0;
}