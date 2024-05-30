#include "MSBase/Board.hpp"
#include "CLI/Display.hpp"
#include "CLI/Controller.hpp"

int main() {
  ms::Board *board = new ms::Board(ms::Vector2u(10, 10), ms::Board::NORMAL);
  ms::DisplayBase *display = new cli::Display(*board);
  ms::ControllerBase *ctrl = new cli::Controller(*board, *display);

  ctrl->play();

  delete board;
  delete display;
  delete ctrl;
}
