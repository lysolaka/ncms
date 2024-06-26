#include "DisplayBase.hpp"
#include <cassert>

namespace sfl {
DisplayBase::DisplayBase(ms::Board const &_board, sf::RenderWindow &_window)
    : ms::DisplayBase(_board), window(_window) {
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  assert(("Font file missing!",
          assets.textFont.loadFromFile("assets/MSFont.ttf")));
  assets.fieldInfo.setFont(assets.textFont);

  u16 boardWidth = board.getWidth();
  u16 boardHeight = board.getHeight();
  u16 bigger = boardWidth > boardHeight ? boardWidth : boardHeight;

  logicalRectSize = (windowSize - 4.f) / bigger;
  assets.fieldRect.setSize(
      sf::Vector2f(logicalRectSize - 4.f, logicalRectSize - 4.f));
  assets.fieldInfo.setCharacterSize(logicalRectSize - 4);
  textOffset.x = (logicalRectSize - 4.f) / 5;
  textOffset.y = (logicalRectSize - 4.f) / 7;
}
} // namespace sfl
