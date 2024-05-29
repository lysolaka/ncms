#include "Controller.hpp"
#include <iostream>

namespace cli {
Controller::Controller(ms::Board &_board, ms::DisplayBase &_display)
    : ms::ControllerBase(_board, _display), action(HELP), status(OK),
      pos(-1, -1) {}

void Controller::play() {
  std::string move;
  while (board.getGameState() == ms::Board::RUNNING) {
    std::cout << '\n';

    display.display();

    switch (status) {
    case OUT_OF_RANGE:
      std::cout
          << "Specified position was outside the board, nothing changed.\n";
      break;
    case UNKNOWN_CMD:
      std::cout << "Unknown command! Displaying help.\n";
      break;
    default:
      break;
    }

    if (action == HELP) {
      std::cout << "Syntax: <command> [column] [row]\n"
                << "Commands:\nr - Reveal field,\n"
                << "f - Flag field,\n"
                << "h - Display help,\n"
                << "q - Force quit.\n";
    }

    std::cout << "\nMove (h - help): ";
    std::getline(std::cin >> std::ws, move);
    parseMove(move);
    move.clear();

    if (status == OK) {
      switch (action) {
      case REVEAL:
        board.revealField(pos);
        break;
      case FLAG:
        board.toggleFlag(pos);
        break;
      default:
        break;
      }
      board.updateGameState();
    }

    if (action == QUIT)
      board.forceEndGame();
  }

  switch (board.getGameState()) {
  case ms::Board::FINISHED_WIN:
    std::cout << "You won, NICE!\n";
    break;
  case ms::Board::FINISHED_LOSS:
    board.revealAllMines();
    display.display();
    std::cout << "You lost, better luck next time!\n";
    break;
  default:
    std::cout << "You shouldn't be here...\n";
    break;
  }
}

void Controller::parseMove(std::string const &move) {
  if (move.length() == 0) {
    action = HELP;
    status = UNKNOWN_CMD;
    return;
  }
  switch (move[0]) {
  case 'r':
    action = REVEAL;
    status = OK;
    break;
  case 'f':
    action = FLAG;
    status = OK;
    break;
  case 'h':
    action = HELP;
    status = OK;
    return;
    break;
  case 'q':
    action = QUIT;
    status = OK;
    return;
    break;
  default:
    action = HELP;
    status = UNKNOWN_CMD;
    return;
    break;
  }

  if (move[1] != ' ') {
    action = HELP;
    status = UNKNOWN_CMD;
    return;
  }

  u32 len = 0;
  while (move[2 + len] != ' ' && move[2 + len] != '\0')
    len++;

  if (move[2 + len] == '\0') {
    action = HELP;
    status = UNKNOWN_CMD;
    return;
  }

  u32 off = len + 1;
  u32 pow = len - 1;
  u16 x = 0;

  for (u32 i = 0; i < len; i++) {
    x += (move[2 + i] - '0') * std::pow(10, pow);
    pow--;
  }

  len = 0;
  while (move[2 + off + len] != ' ' && move[2 + off + len] != '\0')
    len++;

  if (move[2 + off + len] == ' ') {
    action = HELP;
    status = UNKNOWN_CMD;
    return;
  }

  pow = len - 1;
  u16 y = 0;

  for (u32 i = 0; i < len; i++) {
    y += (move[2 + off + i] - '0') * std::pow(10, pow);
    pow--;
  }

  pos.x = x;
  pos.y = y;
  if (!board.isInbound(pos))
    status = OUT_OF_RANGE;
}
} // namespace cli
