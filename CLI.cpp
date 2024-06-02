#include "CLI/Controller.hpp"
#include "CLI/Display.hpp"
#include "CLI/MainMenu.hpp"
#include "MSBase/Board.hpp"

int main() {
  ms::Board *board;
  {
    ms::MenuReturn ret = cli::MainMenu();
    board = new ms::Board(ret.size, ret.diff);
  }
  ms::DisplayBase *display = new cli::Display(*board);
  ms::ControllerBase *ctrl = new cli::Controller(*board, *display);

  ctrl->play();

  delete board;
  delete display;
  delete ctrl;
}
