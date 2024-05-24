#include "Concepts.hpp"

#ifndef MSBITS_VECTOR_HPP
#define MSBITS_VECTOR_HPP

namespace ms {

template <UInt T>
struct Vector2u {
  T x;
  T y;

  Vector2u(T _x, T _y) : x(_x), y(_y) {}
};

} // namespace ms

#endif
