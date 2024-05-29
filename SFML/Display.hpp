#include "../SFMLBase/DisplayBase.hpp"

#ifndef SFML_DISPLAY_HPP
#define SFML_DISPLAY_HPP

namespace sfl {
class Display : public DisplayBase {
public:
  using sfl::DisplayBase::DisplayBase;
  void display();
};
} // namespace sfl

#endif
