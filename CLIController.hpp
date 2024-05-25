#include "MSBase/ControllerBase.hpp"

#ifndef CLI_CONTROLLER_HPP
#define CLI_CONTROLLER_HPP

namespace cli {
class Controller : public ms::ControllerBase {
public:
  Controller(ms::Board &_board, ms::DisplayBase const &_display);
  void play();

private:
  enum Action { REVEAL, FLAG, HELP, QUIT };
  enum LoopStatus { OK, OUT_OF_RANGE, UNKNOWN_CMD };

  ms::Vector2u pos;
  Action action;
  LoopStatus status;

  void parseMove(std::string const &move);
};
} // namespace cli

#endif
