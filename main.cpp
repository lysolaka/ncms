#include "CLIDebugDisplay.hpp"
#include "CLIDisplay.hpp"
#include "CLIController.hpp"

int main() {
  ms::Board board;
  cli::Display debug(board);
  cli::Controller ctrl(board, debug);
  ctrl.play();
}
