#include "src/timer.hpp"
// timer reset elapsed(which returs double value)

#include <fmt/core.h>
#include <fmt/ranges.h>

int main() {
  Timer time;
  // Start timer

  // End timer
  fmt::print("Program took: {} seconds to run\n", time.elapsed());
  system("pause");
  return 0;
}