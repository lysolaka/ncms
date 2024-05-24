#include "Board.hpp"

namespace ms {

Board::Board()
    : storage(Vector2u<u16>(6, 7)), diff(DEBUG), totalMines(2),
      firstMoveDone(false), state(RUNNING), revealedCount(1) {
  storage[0, 0].hasMine = true;

  storage[1, 1].isRevealed = true;

  storage[2, 0].hasMine = true;
  storage[2, 0].hasFlag = true;
}

Board::Board(Vector2u<u16> _size, Difficulty _diff)
    : storage(_size), diff(_diff), firstMoveDone(false), state(RUNNING),
      totalMines(0), revealedCount(0) {

  auto roundUp = [](f32 x) -> u32 {
    u32 result = x;
    return (x < result) ? (result + 1) : (result);
  };

  switch (diff) {
  case EASY:
    totalMines = roundUp(0.1f * storage.size.x * storage.size.x);
    break;
  case NORMAL:
    totalMines = roundUp(0.2f * storage.size.x * storage.size.x);
    break;
  case HARD:
    totalMines = roundUp(0.3f * storage.size.x * storage.size.x);
    break;
  case DEBUG:
    for (u16 i = 0; i < storage.size.x; i++) {
      storage[i, 0].hasMine = true;
      totalMines++;
    }
    u16 diagonal =
        storage.size.x < storage.size.y ? storage.size.x : storage.size.y;
    for (u16 i = 0; i < diagonal; i++) {
      storage[i, i].hasMine = true;
      totalMines++;
    }
    for (u16 i; i < storage.size.y; i += 2) {
      storage[0, i].hasMine = true;
      totalMines++;
    }
    return;
  }

  for (u32 i = 0; i < totalMines; i++) {
    bool placed = false;
    do {
      Vector2u<u16> pos(randomProvider<u16>(storage.size.x - 1),
                        randomProvider<u16>(storage.size.y - 1));
      if (!hasMine(pos)) {
        storage[pos].hasMine = true;
        placed = true;
      }
    } while (!placed);
  }

  for (u16 x = 0; x < storage.size.x; x++) {
    for (u16 y = 0; y < storage.size.y; y++) {
      storage[x, y].minesAround = countMines(Vector2u<u16>(x, y));
    }
  }
}

u16 Board::getWidth() const { return storage.size.x; }
u16 Board::getHeight() const { return storage.size.y; }
u16 Board::getTotalMines() const { return totalMines; }
Board::Difficulty Board::getDifficulty() const { return diff; }
Board::GameState Board::getGameState() const { return state; }

bool Board::hasMine(Vector2u<u16> const &pos) const {
  return storage[pos].hasMine;
}
bool Board::hasFlag(Vector2u<u16> const &pos) const {
  return storage[pos].hasFlag;
}
bool Board::isRevealed(Vector2u<u16> const &pos) const {
  return storage[pos].isRevealed;
}

u16 Board::countMines(Vector2u<u16> const &pos) const {
  u16 counter = 0;
  for (i16 x : {-1, 0, 1}) {
    for (i16 y : {-1, 0, 1}) {
      if (storage.isInbound(Vector2u<u16>(pos.x + x, pos.y + y)) &&
          (x != 0 && y != 0)) {
        if (hasMine(Vector2u<u16>(pos.x + x, pos.y + y)))
          counter++;
      }
    }
  }
  return counter;
}

char Board::getFieldInfo(Vector2u<u16> const &pos) const {
  if (!storage.isInbound(pos))
    return '#';
  if (!isRevealed(pos)) {
    if (hasFlag(pos))
      return 'F';
    else
      return '_';
  } else {
    if (hasMine(pos))
      return 'x';
    if (storage[pos].minesAround == 0)
      return ' ';
    else
      return '0' + storage[pos].minesAround;
  }
}

void Board::toggleFlag(Vector2u<u16> const &pos) {
  storage[pos].hasFlag = !storage[pos].hasFlag;
}

void Board::revealField(Vector2u<u16> const &pos) {
  if (isRevealed(pos) || !storage.isInbound(pos) || state != RUNNING ||
      hasFlag(pos))
    return;

  if (!hasMine(pos)) {
    firstMoveDone = true;
    recursiveReveal(pos);
  } else if (firstMoveDone == false) {
    firstMoveDone = true;
    bool placed = false;
    do {
      Vector2u<u16> tempPos(randomProvider<u16>(storage.size.x - 1),
                            randomProvider<u16>(storage.size.y - 1));
      if (!hasMine(tempPos)) {
        storage[tempPos].hasMine = true;
        placed = true;
      }
    } while (!placed);
    storage[pos].hasMine = false;
    recursiveReveal(pos);
  } else {
    storage[pos].isRevealed = true;
    state = FINISHED_LOSS;
  }
}

void Board::recursiveReveal(Vector2u<u16> const &pos) {
  if (isRevealed(pos))
    return;
  if (hasMine(pos))
    return;
  if (hasFlag(pos))
    return;

  storage[pos].isRevealed = true;
  revealedCount++;
  if (storage[pos].minesAround != 0)
    return;

  if (storage.isInbound(Vector2u<u16>(pos.x - 1, pos.y)))
    recursiveReveal(Vector2u<u16>(pos.x - 1, pos.y));
  if (storage.isInbound(Vector2u<u16>(pos.x + 1, pos.y)))
    recursiveReveal(Vector2u<u16>(pos.x + 1, pos.y));
  if (storage.isInbound(Vector2u<u16>(pos.x, pos.y - 1)))
    recursiveReveal(Vector2u<u16>(pos.x, pos.y - 1));
  if (storage.isInbound(Vector2u<u16>(pos.x, pos.y + 1)))
    recursiveReveal(Vector2u<u16>(pos.x, pos.y + 1));
}

void Board::updateGameState() {
  if (totalMines + revealedCount == storage.size.y * storage.size.x)
    state = FINISHED_WIN;
}
} // namespace ms
