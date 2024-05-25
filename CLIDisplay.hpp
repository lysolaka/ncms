#include "MSBase/DisplayBase.hpp"

#ifndef CLI_DISPLAY_HPP
#define CLI_DISPLAY_HPP

#ifdef __USE_COLOR
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"
#define RESET "\e[0m"
#endif

namespace cli {
class Display : public ms::DisplayBase {
public:
  using ms::DisplayBase::DisplayBase;
  void display() const;

private:
  void displayField(ms::Vector2u const &pos) const;
};
} // namespace cli

#endif
