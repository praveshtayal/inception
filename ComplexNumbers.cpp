#include "ComplexNumbers.h"
#include <iostream>
using namespace std;
ComplexNumbers::ComplexNumbers(int r, int i)
  :re(r),im(i)
{
  /*
  this->re = r;
  this->im = i;
  */
}
void ComplexNumbers::plus(const ComplexNumbers &c)
{
  re += c.re;
  im += c.im;
}

void ComplexNumbers::multiply(const ComplexNumbers &c)
{
  int real = re*c.re - im*c.im;
  im = re*c.im + im*c.re;
  re = real;
}

void ComplexNumbers::print() const
{
  std::cout << re << " + i" << im << std::endl;
}
