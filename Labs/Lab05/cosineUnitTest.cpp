#include "cosineDistance.h"
#include <iostream>
#include <cassert>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

TEST_CASE("vector cosine distance tests"){
  std::vector<double> v0 = {1.0, 0.0, 0.0};
  std::vector<double> v1 = {1.0, 1.0, 0.0};
  std::vector<double> v2 = {1.0, 1.0, 1.0};
  std::vector<double> v3 = {0.0, 0.0, 0.0};
  std::vector<double> v4 = {1.0, 2.0, 3.0};
  std::vector<double> v5 = {4.0, 5.5, 6.0};
  std::vector<double> v6 = {4.3, 3.2, 2.1};
  std::vector<double> v7 = {6.8, 3.6, 1.4};
  std::vector<double> v8 = {5.7, 6.3, 2.7};
  std::vector<double> v9 = {0.0, 7.4, 2.0};

  // calculate cosine distances
  double a1 = distance(v0, v1);  // (1,0,0) & (1,1,0)
  double a2 = distance(v1, v2);  // (1,1,0) & (1,1,1)
  double a3 = distance(v4, v5);  // (1,2,3) & (4,5.5,6)
  double a4 = distance(v6, v7);  // (4.3,3.2,2.1) & (6.8,3.6,1.4)
  double a5 = distance(v8, v9);  // (5.7,6.3,2.7) & (0,7.4,2)

  // check the results with expected values
  CHECK(a1 == doctest::Approx(0.785398).epsilon(0.00001));
  CHECK(a2 == doctest::Approx(0.615480).epsilon(0.00001)); 
  CHECK(a3 == doctest::Approx(0.235135).epsilon(0.00001));
  CHECK(a4 == doctest::Approx(0.2427962).epsilon(0.00001));
  CHECK(a5 == doctest::Approx(0.705556).epsilon(0.00001));

  // test zero vector
  CHECK(distance(v0, v3) == 0.0);
  // test same vector
  CHECK(distance(v0, v0) == 0.0);
}