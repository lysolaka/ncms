#include "MSBits/Defs.hpp"
#include "MSBits/Vector.hpp"
#include "MSBits/Matrix.hpp"
#include "MSBits/Random.hpp"

#ifndef MS_BOARD_HPP
#define MS_BOARD_HPP

namespace ms {
class Board {
public:
  enum Difficulty { EASY, NORMAL, HARD, DEBUG };
  enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

  struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
    u16 minesAround;

    Field();
  };

private:
  GameState state;
  Difficulty diff;
  Matrix<Field, u16> storage;

  u32 totalMines;
  u32 revealedCount;
  bool firstMoveDone;

public:
  Board();
  Board(Vector2u _size, Difficulty _diff);

  u16 getWidth() const;
  u16 getHeight() const;
  u16 getTotalMines() const;
  Difficulty getDifficulty() const;
  GameState getGameState() const;

  bool hasMine(Vector2u const &pos) const;
  bool hasFlag(Vector2u const &pos) const;
  bool isRevealed(Vector2u const &pos) const;

  u16 countMines(Vector2u const &pos) const;
  char getFieldInfo(Vector2u const &pos) const;

  void toggleFlag(Vector2u const &pos);
  void revealField(Vector2u const &pos);

  void updateGameState();

private:
  void recursiveReveal(Vector2u const &pos);
};
} // namespace ms

#endif
