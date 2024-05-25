#include "CLIDebugDisplay.hpp"
#include "CLIDisplay.hpp"

int main() {
  ms::Board board;
  cli::Display debug(board);
  debug.display();
}
