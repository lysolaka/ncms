#include "CLIDebugDisplay.hpp"

int main() {
  ms::Board board(ms::Vector2u<ms::u16>(8, 7), ms::Board::EASY);
  ms::DisplayBase debug = cli::DebugDisplay(board);
  debug.display();
}
