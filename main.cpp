#include "MSBase/Board.hpp"
#include "SFML/Controller.hpp"
#include "SFML/Display.hpp"
#include "SFML/DebugDisplay.hpp"

int main() {
  ms::Board *board = new ms::Board(ms::Vector2u(8, 9), ms::Board::NORMAL);
  sf::RenderWindow *win = new sf::RenderWindow(
      sf::VideoMode(sfl::DisplayBase::windowSize, sfl::DisplayBase::windowSize),
      "Minesweeper", sf::Style::Close);
  ms::DisplayBase *display = new sfl::DebugDisplay(*board, *win);
  ms::ControllerBase *ctrl = new sfl::Controller(*board, *display, *win);

  ctrl->play();

  delete board;
  delete win;
  delete display;
  delete ctrl;
}
