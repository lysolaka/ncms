#include "Concepts.hpp"
#include "Defs.hpp"

#ifndef MSBITS_VECTOR_HPP
#define MSBITS_VECTOR_HPP

namespace ms {

template <Fundamental T>
struct Vector2 {
  T x;
  T y;

  Vector2() = default;
  Vector2(T _x, T _y) : x(_x), y(_y) {}
  Vector2(Vector2 const &_V) : x(_V.x), y(_V.y) {}
};

typedef Vector2<u16> Vector2u;

} // namespace ms

#endif
