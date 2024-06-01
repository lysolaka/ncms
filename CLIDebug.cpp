#include "MSBase/Board.hpp"
#include "CLI/DebugDisplay.hpp"
#include "CLI/Controller.hpp"
#include "CLI/MainMenu.hpp"

int main() {
  ms::Board *board = new ms::Board(ms::Vector2u(10, 10), ms::Board::NORMAL);
  cli::MainMenu(board);
  ms::DisplayBase *display = new cli::DebugDisplay(*board);
  ms::ControllerBase *ctrl = new cli::Controller(*board, *display);

  ctrl->play();

  delete board;
  delete display;
  delete ctrl;
}
