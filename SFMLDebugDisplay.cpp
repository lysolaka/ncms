#include "SFMLDebugDisplay.hpp"

namespace sfl {
void DebugDisplay::display() {
  window.clear(sf::Color::Black);

  char fieldInfo;
  for (u16 y = 0; y < board.getHeight(); y++) {
    for (u16 x = 0; x < board.getWidth(); x++) {
      assets.fieldRect.setPosition(
          sf::Vector2f(4.f + x * logicalRectSize, 4.f + y * logicalRectSize));
      /* TODO: colour */
      window.draw(assets.fieldRect);

      fieldInfo = board.getFieldInfo(ms::Vector2u(x, y));
      if (fieldInfo != '_' && fieldInfo != ' ') {
        assets.fieldInfo.setPosition(
            sf::Vector2f(4.f + x * logicalRectSize + textOffset.x,
                         4.f + y * logicalRectSize - textOffset.y));
        assets.fieldInfo.setString(fieldInfo);
        if (fieldInfo == 'F') {
          assets.fieldInfo.setFillColor(sf::Color::Red);
        } else if (fieldInfo == 'x') {
          assets.fieldInfo.setFillColor(sf::Color::Black);
        } else if (fieldInfo >= '1' && fieldInfo <= '8') {
          switch (fieldInfo) {
          /* TODO: colour */
          }
        }

        window.draw(assets.fieldInfo);
      }
    }
  }

  window.display();
}
} // namespace sfl
