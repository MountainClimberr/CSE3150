#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"

bool non_negative_prefix_sum(int myArray[], int len) {
  bool value = true;
  int sum = 0; 
  for (int i = 0; i < len; i++) {
      sum += myArray[i];
      if (sum < 0) {
        value = false;
        break;
      }
  } 
}

int factorial(int number) {
  if( number <= 1 ) {
    return 1;
  } else {
    return number * factorial(number - 1);
  }
}
TEST_CASE("testing the factorial function") {
  CHECK(factorial(0) == 1);
  CHECK(factorial(1) == 1);
  CHECK(factorial(2) == 2);
  CHECK(factorial(3) == 6);
  CHECK(factorial(10) == 3628800);
}