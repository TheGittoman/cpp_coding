#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray
// functio
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <algorithm>
#include <chrono>
#include <climits>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct Speed {
  double x{5.0f};
  double y{5.0f};
};

Speed speed;

void getEvent(sf::RenderWindow &window, sf::Event &event) {
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
        case sf::Keyboard::Q:
        case sf::Keyboard::Escape:
          fmt::print("Window closed\n");
          window.close();
          break;
        default:
          break;
      }
    }
  }
}

void gameLoop(sf::RenderWindow &window) {
  //
}

void getMove(sf::CircleShape &circle, bool &h_border_x, bool &h_border_y) {
  //
  sf::Vector2f posVec = circle.getPosition();
  if (posVec.x >= 800 - 50 || posVec.x <= 0 + 50) speed.x = -speed.x;
  if (posVec.y >= 800 - 50 || posVec.y <= 0 + 50) speed.y = -speed.y;

  circle.move(speed.x, speed.y);

  fmt::print("Position is: {}, {}\n", posVec.x, posVec.y);
  fmt::print("speed is: {}, {}\n", speed.x, speed.y);
}

void update(sf::RenderWindow &window, sf::CircleShape &circle, bool &h_border_x,
            bool &h_border_y) {
  //
  window.clear(sf::Color::Black);
  getMove(circle, h_border_x, h_border_y);
  window.draw(circle);
  window.display();
}

int main() {
  Timer time;
  // Start timer
  sf::RenderWindow window(sf::VideoMode(800, 800), "Window");
  window.setFramerateLimit(60);
  sf::CircleShape circle{50.0f};
  circle.setOrigin(50.0f, 50.0f);
  circle.setPosition(200, 300);
  bool h_border_x{false}, h_border_y{false};
  while (window.isOpen()) {
    sf::Event event;
    getEvent(window, event);
    update(window, circle, h_border_x, h_border_y);
  }
  // End timer
  gameLoop(window);
  fmt::print("Program has taken: {} seconds to run\n", time.elapsed());
  // system("pause");
  return 0;
}