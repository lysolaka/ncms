#include "Concepts.hpp"
#include "Defs.hpp"

#ifndef MSBITS_VECTOR_HPP
#define MSBITS_VECTOR_HPP

namespace ms {

template <Integral T>
struct Vector2 {
  T x;
  T y;

  Vector2(T _x, T _y) : x(_x), y(_y) {}
};

typedef Vector2<u16> Vector2u;

} // namespace ms

#endif
