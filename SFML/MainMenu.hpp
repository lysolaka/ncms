#include "../MSBase/Board.hpp"
#include "../MSBase/MenuReturn.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifndef SFML_MAIN_MENU_HPP
#define SFML_MAIN_MENU_HPP

namespace sfl {
ms::MenuReturn MainMenu(sf::RenderWindow &win);

struct MenuAssets {
  sf::Font textFont;
  sf::RectangleShape bg;
  sf::Texture bgTexture;
  sf::RectangleShape playButton;
  sf::FloatRect playButtonBox;
  sf::Texture minusButton;
  sf::Texture plusButton;
  sf::RectangleShape columnsMinus;
  sf::FloatRect columnsMinusBox;
  sf::RectangleShape columnsPlus;
  sf::FloatRect columnsPlusBox;
  sf::RectangleShape rowsMinus;
  sf::FloatRect rowsMinusBox;
  sf::RectangleShape rowsPlus;
  sf::FloatRect rowsPlusBox;
  sf::RectangleShape diffMinus;
  sf::FloatRect diffMinusBox;
  sf::RectangleShape diffPlus;
  sf::FloatRect diffPlusBox;
  sf::Text sizeColumns;
  sf::Text sizeRows;
  sf::Text diffLabel;
};
} // namespace sfl

#endif
