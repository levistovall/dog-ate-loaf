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

  template<typename U>
  auto getDotProductWith(const AbstractVector<U> &other);

private:
  std::vector<T> content;
  int length;
};

#endif
