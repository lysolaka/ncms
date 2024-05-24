#include "MSBase/DisplayBase.hpp"

#ifndef CLI_DEBUG_DISPLAY_HPP
#define CLI_DEBUG_DISPLAY_HPP

namespace cli {
class DebugDisplay : public ms::DisplayBase {
public:
  using ms::DisplayBase::DisplayBase;
  void display() const;

private:
  void displayField(ms::Vector2u<ms::u16> const &pos) const;
};
} // namespace cli

#endif
