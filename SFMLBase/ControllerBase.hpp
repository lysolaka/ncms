#include "../MSBase/ControllerBase.hpp"
#include "DisplayBase.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifndef SFML_CONTROLLER_BASE_HPP
#define SFML_CONTROLLER_BASE_HPP

namespace sfl {
class ControllerBase : public ms::ControllerBase {
protected:
  sf::RenderWindow &window;
  f32 logicalRectSize;

public:
  ControllerBase(ms::Board &_board, sfl::DisplayBase &_display,
                 sf::RenderWindow &_window);
};
} // namespace sfl

#endif
