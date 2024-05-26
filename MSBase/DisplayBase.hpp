#include "Board.hpp"

#ifndef MS_DISPLAY_BASE_HPP
#define MS_DISPLAY_BASE_HPP

namespace ms {
class DisplayBase {
  protected:
    const Board &board;
  public:
    DisplayBase(Board const &_board);
    virtual void display() = 0;
    virtual ~DisplayBase() = default;
};
}

#endif
