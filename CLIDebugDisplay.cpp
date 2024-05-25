#include "CLIDebugDisplay.hpp"
#include <iostream>

namespace cli {
void DebugDisplay::display() const {
  for (u16 i = 0; i < board.getWidth(); i++)
    std::cout << "    " << i;

  std::cout << '\n';

  for (u16 y = 0; y < board.getHeight(); y++) {
    std::cout << y << ' ';
    for (u16 x = 0; x < board.getWidth(); x++) {
      std::cout << '[';
      displayField(ms::Vector2u(x, y));
      std::cout << ']';
    }
    std::cout << '\n';
  }
}

void DebugDisplay::displayField(ms::Vector2u const &pos) const {
  if (board.hasMine(pos)) {
#ifdef __USE_COLOR
    std::cout << "\e[1;35m";
#endif
    std::cout << 'M';
#ifdef __USE_COLOR
    std::cout << "\e[0m";
#endif
  } else {
    std::cout << '.';
  }
  if (board.hasFlag(pos)) {
#ifdef __USE_COLOR
    std::cout << "\e[1;31m";
#endif
    std::cout << 'f';
#ifdef __USE_COLOR
    std::cout << "\e[0m";
#endif
  } else {
    std::cout << '.';
  }
  if (board.isRevealed(pos)) {
#ifdef __USE_COLOR
    std::cout << "\e[1;37m";
#endif
    std::cout << 'r';
#ifdef __USE_COLOR
    std::cout << "\e[0m";
#endif
  } else {
    std::cout << '.';
  }
}
} // namespace cli
