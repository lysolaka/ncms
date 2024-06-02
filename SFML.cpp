#include "MSBase/Board.hpp"
#include "SFML/Controller.hpp"
#include "SFML/Display.hpp"
#include "SFML/MainMenu.hpp"

int main() {
  sf::ContextSettings con;
  con.antialiasingLevel = 8;

  ms::Board *board;
  sf::RenderWindow *win = new sf::RenderWindow(
      sf::VideoMode(sfl::DisplayBase::windowSize, sfl::DisplayBase::windowSize),
      "Minesweeper", sf::Style::Close, con);
  {
    ms::MenuReturn ret = sfl::MainMenu(*win);
    board = new ms::Board(ret.size, ret.diff);
  }
  ms::DisplayBase *display = new sfl::Display(*board, *win);
  ms::ControllerBase *ctrl = new sfl::Controller(*board, *display, *win);

  ctrl->play();

  delete board;
  delete win;
  delete display;
  delete ctrl;
}
