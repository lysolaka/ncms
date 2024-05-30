#include "ControllerBase.hpp"

namespace sfl {
ControllerBase::ControllerBase(ms::Board &_board, sfl::DisplayBase &_display,
                               sf::RenderWindow &_window)
    : ms::ControllerBase(_board, _display), window(_window) {
  u16 boardWidth = board.getWidth();
  u16 boardHeight = board.getHeight();
  u16 bigger = boardWidth > boardHeight ? boardWidth : boardHeight;

  logicalRectSize = (DisplayBase::windowSize - 4.f) / bigger;
}

} // namespace sfl
