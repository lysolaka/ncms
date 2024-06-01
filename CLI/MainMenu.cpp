#include "MainMenu.hpp"
#include <iostream>

namespace cli {
void MainMenu(ms::Board *board) {
  ms::Vector2u size(10, 10);
  ms::Board::Difficulty diff = ms::Board::NORMAL;

  bool confirmed = false;
  char userInput = 'n';
  std::cout 
#ifdef __USE_COLOR
    << "\e[1;37m"
#endif
    << "Welcome to CLISweeper!\n" 
#ifdef __USE_COLOR
    << "\e[0m"
#endif
    << "Choose your settings:\n";
  while (!confirmed) {
    std::cout << "Current settings:\n"
#ifdef __USE_COLOR
      << "\e[1;36m"
#endif
      << "Columns: " << size.x
#ifdef __USE_COLOR
      << "\e[0m"
#endif
      << ", " 
#ifdef __USE_COLOR
      << "\e[1;36m"
#endif
      << "Rows: " << size.y << '\n'
#ifdef __USE_COLOR
      << "\e[0m"
#endif
      << "Difficulty: ";
    switch (diff) {
    case ms::Board::EASY:
#ifdef __USE_COLOR
      std::cout << "\e[1;32m";
#endif
      std::cout << "Easy";
#ifdef __USE_COLOR
      std::cout << "\e[0m";
#endif
      break;
    case ms::Board::NORMAL:
#ifdef __USE_COLOR
      std::cout << "\e[1;33m";
#endif
      std::cout << "NORMAL";
#ifdef __USE_COLOR
      std::cout << "\e[0m";
#endif
      break;
    case ms::Board::HARD:
#ifdef __USE_COLOR
      std::cout << "\e[1;31m";
#endif
      std::cout << "HARD";
#ifdef __USE_COLOR
      std::cout << "\e[0m";
#endif
      break;
    default:
      break;
    }
    std::cout << "\nDo you confirm these settings? [Y/n]: ";
    std::cin >> userInput;
    if (userInput == 'Y' || userInput == 'y')
      confirmed = true;
    else {
      std::cout << "Which setting to change?\n"
        << "1. Size\n"
        << "2. Difficulty\n"
        << ": ";
      std::cin >> userInput;
      if (userInput == '1') {
        std::cout << "Number of columns: ";
        std::cin >> size.x;
        std::cout << "Number of rows: ";
        std::cin >> size.y;
      } else if (userInput == '2') {
        std::cout << "Available difficulties:\n"
          << "1. EASY\n"
          << "2. NORMAL\n"
          << "3. HARD\n"
          << ": ";
        std::cin >> userInput;
        switch (userInput) {
          case '1':
            diff = ms::Board::EASY;
            break;
          case '2':
            diff = ms::Board::NORMAL;
            break;
          case '3':
            diff = ms::Board::HARD;
            break;
          default:
            break;
        }
      }
    }
  }

  if (board != nullptr)
    delete board;
  board = new ms::Board(size, diff);
}
}
