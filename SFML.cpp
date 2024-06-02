#include "MSBase/Board.hpp"
#include "SFML/MainMenu.hpp"
#include "SFML/Controller.hpp"
#include "SFML/Display.hpp"

int main() {
  sf::ContextSettings con;
  con.antialiasingLevel = 8;

  ms::Board *board = new ms::Board(ms::Vector2u(10, 10), ms::Board::NORMAL);
  sf::RenderWindow *win = new sf::RenderWindow(
      sf::VideoMode(sfl::DisplayBase::windowSize, sfl::DisplayBase::windowSize),
      "Minesweeper", sf::Style::Close, con);
  sfl::MainMenu(board, *win);
  ms::DisplayBase *display = new sfl::Display(*board, *win);
  ms::ControllerBase *ctrl = new sfl::Controller(*board, *display, *win);

  ctrl->play();

  delete board;
  delete win;
  delete display;
  delete ctrl;
}
