#include "../SFMLBase/ControllerBase.hpp"

#ifndef SFML_CONTROLLER_HPP
#define SFML_CONTROLLER_HPP

namespace sfl {
class Controller : public ControllerBase {
public:
  using ControllerBase::ControllerBase;
  void play();
};
} // namespace sfl

#endif
