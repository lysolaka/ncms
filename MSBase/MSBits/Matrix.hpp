#include "Concepts.hpp"
#include "Defs.hpp"
#include "Vector.hpp"

#ifndef MSBITS_MATRIX_HPP
#define MSBITS_MATRIX_HPP

namespace ms {

template <MatrixValueType V, UInt S = u16> class Matrix {
private:
  V **mtx;

public:
  const Vector2u<S> size;

  Matrix<V, S>() = delete;
  Matrix<V, S>(Vector2u<S> const &_size) : size(_size) {
    mtx = new V *[size.x];

    for (S i = 0; i < size.x; i++) {
      mtx[i] = new V[size.y];
    }
  }

  ~Matrix<V, S>() {
    for (S i = 0; i < size.x; i++) {
      delete[] mtx[i];
    }

    delete[] mtx;
  }

  V &operator[](Vector2u<S> const &pos) { return mtx[pos.x][pos.y]; }
  V &operator[](S x, S y) { return mtx[x][y]; }

  const V &operator[](Vector2u<S> const &pos) const { return mtx[pos.x][pos.y]; }
  const V &operator[](S x, S y) const { return mtx[x][y]; }

  bool isInbound(Vector2u<S> const &pos) const {
    if (pos.x >= size.x || pos.y >= size.y)
      return false;
    else
     return true;
  }
};

} // namespace ms

#endif
