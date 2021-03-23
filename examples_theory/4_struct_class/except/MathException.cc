#include "MathException.h"

const char* MathException::message() const {
  switch ( error ) {
  case divByZero:
    return "division by zero";
    break;
  case sqrNeg:
    return "square-root of negative number";
    break;
  }
  return "";
}

