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
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  // End timer
  fmt::print("Program has taken: {} seconds to run\n", time.elapsed());
  system("pause");
  return 0;
}