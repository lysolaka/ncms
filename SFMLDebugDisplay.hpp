#include "SFMLBase/DisplayBase.hpp"

#ifndef SFML_DEBUG_DISPLAY_HPP
#define SFML_DEBUG_DISPLAY_HPP

namespace sfl {
class DebugDisplay : public DisplayBase {
public:
  using sfl::DisplayBase::DisplayBase;
  void display();
};
} // namespace sfl

#endif
