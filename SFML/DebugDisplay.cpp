#include "DebugDisplay.hpp"

namespace sfl {
void DebugDisplay::display() {
  char fieldInfo;
  for (u16 y = 0; y < board.getHeight(); y++) {
    for (u16 x = 0; x < board.getWidth(); x++) {
      assets.fieldRect.setPosition(
          sf::Vector2f(4.f + x * logicalRectSize, 4.f + y * logicalRectSize));
      if (board.isRevealed(ms::Vector2u(x, y)))
        assets.fieldRect.setFillColor(sf::Color(181, 181, 181));
      else if (board.hasMine(ms::Vector2u(x, y)))
        assets.fieldRect.setFillColor(sf::Color(181, 97, 97));
      else
        assets.fieldRect.setFillColor(sf::Color(97, 97, 97));
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
          case '1':
            assets.fieldInfo.setFillColor(sf::Color(97, 255, 97));
            break;
          case '2':
            assets.fieldInfo.setFillColor(sf::Color(255, 193, 0));
            break;
          case '3':
            assets.fieldInfo.setFillColor(sf::Color(48, 243, 255));
            break;
          case '4':
            assets.fieldInfo.setFillColor(sf::Color(48, 97, 255));
            break;
          case '5':
            assets.fieldInfo.setFillColor(sf::Color(223, 97, 255));
            break;
          case '6':
            assets.fieldInfo.setFillColor(sf::Color(255, 82, 97));
            break;
          case '7':
            assets.fieldInfo.setFillColor(sf::Color::White);
            break;
          case '8':
            assets.fieldInfo.setFillColor(sf::Color(0, 4, 76));
            break;
          }
        }

        window.draw(assets.fieldInfo);
      }
    }
  }
}
} // namespace sfl
