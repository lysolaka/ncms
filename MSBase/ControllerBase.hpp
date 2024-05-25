#include "Board.hpp"
#include "DisplayBase.hpp"

#ifndef MS_CONTROLLER_HPP
#define MS_CONTROLLER_HPP

namespace ms {
class ControllerBase {
protected:
  Board &board;
  const DisplayBase &display;
public:
  ControllerBase(Board &_board, DisplayBase const &_display);
  virtual void play() = 0;
  ~ControllerBase() = default;
};
}

#endif
