#include "MSBase/Board.hpp"
#include "SFML/Controller.hpp"
#include "SFML/DebugDisplay.hpp"
#include "SFML/MainMenu.hpp"

int main() {
  ms::Board *board;
  sf::RenderWindow *win;
  {
    sf::ContextSettings con;
    con.antialiasingLevel = 8;
    win = new sf::RenderWindow(sf::VideoMode(sfl::DisplayBase::windowSize,
                                             sfl::DisplayBase::windowSize),
                               "Minesweeper", sf::Style::Close, con);
  }
  {
    ms::MenuReturn ret = sfl::MainMenu(*win);
    board = new ms::Board(ret.size, ret.diff);
  }
  ms::DisplayBase *display = new sfl::DebugDisplay(*board, *win);
  ms::ControllerBase *ctrl = new sfl::Controller(*board, *display, *win);

  ctrl->play();

  delete board;
  delete win;
  delete display;
  delete ctrl;
}
