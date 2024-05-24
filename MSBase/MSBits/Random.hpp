#include "Concepts.hpp"
#include <random>

#ifndef MSBITS_RANDOM_HPP
#define MSBITS_RANDOM_HPP

namespace ms {
static std::random_device rd;
static std::mt19937 tw(rd());

template <Randomizable T>
  requires UInt<T>
T randomProvider(T x) {
  std::uniform_int_distribution<T> dist(0, x);
  return dist(tw);
}

template <Randomizable T>
  requires FloatingPoint<T>
T randomProvider(T x) {
  std::uniform_real_distribution<T> dist(0, x);
  return dist(tw);
}
} // namespace ms

#endif
