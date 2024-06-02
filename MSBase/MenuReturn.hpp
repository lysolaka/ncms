#include "Board.hpp"

#ifndef MS_MENU_RETURN_HPP
#define MS_MENU_RETURN_HPP

namespace ms {
struct MenuReturn {
  ms::Vector2u size;
  ms::Board::Difficulty diff;

  MenuReturn(ms::Vector2u const &_v, ms::Board::Difficulty _d);
};
}

#endif
