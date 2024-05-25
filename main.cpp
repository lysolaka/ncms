#include "CLIDebugDisplay.hpp"
#include "CLIDisplay.hpp"
#include "CLIController.hpp"

int main() {
  ms::Board board(ms::Vector2u(8, 9), ms::Board::NORMAL);
  cli::Display debug(board);
  cli::Controller ctrl(board, debug);
  ctrl.play();
}
