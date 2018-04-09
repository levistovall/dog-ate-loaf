#ifndef VECTOR_H_
#define VECTOR_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>

template<typename T>
class AbstractVector
{
public:
  virtual AbstractVector(int length);
  virtual ~AbstractVector();

  int getLength() const;

  const T &operator[](int index) const;

  T &operator[](int index);

private:
  std::vector<T> content;
  int length;
};

template<typename T, typename U>
auto operator*(const T &t, const AbstractVector<U> &a) -> AbstractVector<decltype(T{} * U{})>;

template<typename T, typename U>
auto operator*(const AbstractVector<T> &a, const U &u) -> AbstractVector<decltype(T{} * U{})>;

template<typename T, typename U>
auto operator*(const AbstractVector<T> &a, const AbstractVector<U> &b) -> AbstractVector<decltype(T{} * U{})>;

template<typename T, typename U>
auto operator+(const AbstractVector<T> &a, const AbstractVector<U> &b) -> AbstractVector<decltype(T{} + U{})>;

template<typename T, typename U>
auto operator-(const AbstractVector<T> &a, const AbstractVector<U> &b) -> AbstractVector<decltype(T{} - U{})>;


#endif
