#include <type_traits>

#ifndef MSBITS_CONCEPTS_HPP
#define MSBITS_CONCEPTS_HPP

namespace ms {

template <typename T>
concept UInt = std::is_unsigned_v<T>;

template <class T>
concept MatrixValueType = std::is_default_constructible_v<T> && std::is_object_v<T>;

template <typename T>
concept Randomizable = std::is_arithmetic_v<T>;

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template <typename T>
concept Fundamental = Integral<T> || FloatingPoint<T>;
}

#endif
