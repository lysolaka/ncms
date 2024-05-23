#include "Concepts.hpp"
#include "Defs.hpp"

#ifndef MSBITS_VECTOR_HPP
#define MSBITS_VECTOR_HPP

namespace ms {

template <UInt T = u16>
struct Vector2u {
  T x;
  T y;

  Vector2u<T>(T _x, T _y) : x(_x), y(_y) {}
};

} // namespace ms

#endif
