#ifndef COSINE_DISTANCE_H
#define COSINE_DISTANCE_H

#include <vector>

struct Vec{
  int id;
  std::vector<double> components;
};

struct Result{
  int first_id;
  int second_id;
  double angle;

  Result(int id1, int id2, double a) 
    : first_id(id1), second_id(id2), angle(a) {}
};

double dot(const std::vector<double>& a, const std::vector<double>& b);
double length(const std::vector<double>& v);
double distance(const std::vector<double>& a, const std::vector<double>& b);

#endif