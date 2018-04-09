#include "AbstractVector.h"

template<typename T>
AbstractVector<T>::AbstractVector<T>(int length)
{
  content.resize(length);
}

template<typename T>
int AbstractVector<T>::getLength() const
{
  return this->length;
}

template<typename T>
T &AbstractVector<T>::operator[](int index)
{
  return content[index];
}

template<typename T>
const T &AbstractVector<T>::operator[](int index) const
{
  return content[index];
}

template<typename T, typename U>
auto operator*(const T &t, const AbstractVector<U> &a) -> AbstractVector<decltype(T{} * U{})>
{
  AbstractVector<decltype(T{} * U{})> result(a.getLength());
  for(int i = 0; i < result.getLength(); i++)
  {
    result[i] = a[i] * t;
  }
}
