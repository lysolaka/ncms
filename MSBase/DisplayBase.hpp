#include "Board.hpp"

#ifndef MS_DISPLAY_HPP
#define MS_DISPLAY_HPP

namespace ms {
class DisplayBase {
  protected:
    const Board &board;
  public:
    DisplayBase(Board const &_board);
    virtual void display() const;
};
}

#endif
