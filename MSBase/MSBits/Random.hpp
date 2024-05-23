#include "Concepts.hpp"
#include <random>

#ifndef MSBITS_RANDOM_HPP
#define MSBITS_RANDOM_HPP

namespace ms {
static std::random_device rd;
static std::mt19937 tw(rd());

template <Randomizable T> T randomProvider(T x) {
  if (std::is_integral_v<T>) {
    std::uniform_int_distribution<T> dist(0, x);
    return dist(tw);
  } else if (std::is_floating_point_v<T>) {
    std::uniform_real_distribution<T> dist(0, x);
    return dist(tw);
  } else {
    throw "Unknown type in MSBits/Random.hpp";
  }
}
} // namespace ms

#endif
