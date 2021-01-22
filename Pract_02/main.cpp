#include "src/timer.hpp"
// timer reset elapsed(which returs double value)

#include <fmt/core.h>
#include <fmt/ranges.h>

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
  fmt::print("Program took: {} seconds to run\n", time.elapsed());
  system("pause");
  return 0;
}