#include "ControllerBase.hpp"

namespace ms {
ControllerBase::ControllerBase(Board &_board, DisplayBase &_display)
    : board(_board), display(_display) {}
} // namespace ms
