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

}

#endif
