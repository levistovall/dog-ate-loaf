#ifndef VECTOR_H_
#define VECTOR_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>

template<typename T>
class AbstractVector
{
public:
  virtual AbstractVector(int length);
  virtual ~AbstractVector();
private:
  std::vector<T> content;
  int length;
};
