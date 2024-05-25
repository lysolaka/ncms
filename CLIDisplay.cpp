#include "CLIDisplay.hpp"
#include <iostream>

namespace cli {
void Display::display() const {
  std::cout << ' ';
  for (u16 i = 0; i < board.getWidth(); i++)
    std::cout << "  " << i;
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

void Display::displayField(ms::Vector2u const &pos) const {
#ifdef __USE_COLOR
  char fieldInfo = board.getFieldInfo(pos);
  switch (fieldInfo) {
    case 'x':
      std::cout << RED << 'x' << RESET;
      break;
    case '1':
      std::cout << GREEN << '1' << RESET;
      break;
    case '2':
      std::cout << YELLOW << '2' << RESET;
      break;
    case '3':
      std::cout << CYAN << '3' << RESET;
      break;
    case '4':
      std::cout << BLUE << '4' << RESET;
      break;
    case '5':
      std::cout << MAGENTA << '5' << RESET;
      break;
    case '6':
      std::cout << RED << '6' << RESET;
      break;
    case '7':
      std::cout << WHITE << '7' << RESET;
      break;
    case '8':
      std::cout << BLACK << '8' << RESET;
      break;
    case 'F':
      std::cout << RED << 'F' << RESET;
      break;
    default:
      std::cout << fieldInfo;
      break;
  }
#else
  std::cout << board.getFieldInfo(pos);
#endif
}
} // namespace cli
