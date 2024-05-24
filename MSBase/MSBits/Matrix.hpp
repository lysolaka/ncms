#include "Concepts.hpp"
#include "Vector.hpp"

#ifndef MSBITS_MATRIX_HPP
#define MSBITS_MATRIX_HPP

namespace ms {

template <MatrixValueType V, UInt S> class Matrix {
private:
  V **mtx;

public:
  const Vector2<S> size;

  Matrix() = delete;
  Matrix(Vector2<S> const &_size) : size(_size) {
    mtx = new V *[size.x];

    for (S i = 0; i < size.x; i++) {
      mtx[i] = new V[size.y];
    }
  }

  ~Matrix() {
    for (S i = 0; i < size.x; i++) {
      delete[] mtx[i];
    }

    delete[] mtx;
  }

  V &operator[](Vector2<S> const &pos) { return mtx[pos.x][pos.y]; }
  V &operator[](S x, S y) { return mtx[x][y]; }

  const V &operator[](Vector2<S> const &pos) const { return mtx[pos.x][pos.y]; }
  const V &operator[](S x, S y) const { return mtx[x][y]; }

  bool isInbound(Vector2<S> const &pos) const {
    if (pos.x >= size.x || pos.y >= size.y)
      return false;
    else
     return true;
  }
};

} // namespace ms

#endif
