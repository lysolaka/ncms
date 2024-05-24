#include "CLIDebugDisplay.hpp"

int main() {
  ms::Board board(ms::Vector2u(8, 7), ms::Board::HARD);
  cli::DebugDisplay debug(board);
  debug.display();
}
