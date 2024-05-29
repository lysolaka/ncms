#include "Board.hpp"
#include "DisplayBase.hpp"

#ifndef MS_CONTROLLER_BASE_HPP
#define MS_CONTROLLER_BASE_HPP

namespace ms {
class ControllerBase {
protected:
  Board &board;
  DisplayBase &display;

public:
  ControllerBase(Board &_board, DisplayBase &_display);
  virtual void play() = 0;
  virtual ~ControllerBase() = default;
};
} // namespace ms

#endif
