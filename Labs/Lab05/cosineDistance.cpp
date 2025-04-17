#include "cosineDistance.h"
#include <cmath>
#include <vector>

// calculate dot product between two vectors
double dot(const std::vector<double>& a, const std::vector<double>& b){
  double total = 0.0;

  size_t size = (a.size() < b.size()) ? a.size() : b.size();

  for (size_t i = 0; i < size; i++){
    total += a[i] * b[i];
  }

  return total;
}

// calculate vector length
double length(const std::vector<double>& v){
  double sum_squares = 0.0;

  for (double val : v){
    sum_squares += val * val;
  }

  return std::sqrt(sum_squares);
}

// calculate distance between two vectors
double distance(const std::vector<double>& a, const std::vector<double>& b){
  double len_a = length(a);
  double len_b = length(b);

  if (len_a < 1e-10 || len_b < 1e-10){
    return 0.0;
  }

  double cosine = dot(a, b) / (len_a * len_b);

  if (cosine > 1.0) cosine = 1.0;
  if (cosine < -1.0) cosine = -1.0;

  // return distance in radians
  return std::acos(cosine);
}