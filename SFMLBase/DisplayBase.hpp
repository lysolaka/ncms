#include "../MSBase/DisplayBase.hpp"
#include "../MSBase/MSBits/Vector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifndef SFML_DISPLAY_BASE_HPP
#define SFML_DISPLAY_BASE_HPP

namespace sfl {
class DisplayBase : public ms::DisplayBase {
protected:
  sf::RenderWindow &window;

  struct {
    sf::Font textFont;
    sf::Text fieldInfo;
    sf::RectangleShape fieldRect;
  } assets;

  f32 logicalRectSize;
  ms::Vector2<f32> textOffset;

public:
  static const u32 windowSize = 800;

  DisplayBase(ms::Board const &_board, sf::RenderWindow &_window);
};
} // namespace sfl

#endif
