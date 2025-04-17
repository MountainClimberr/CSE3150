#include "bigint.h"
#include <iostream>
#include <chrono>
#include <utility>

using namespace std;
using namespace std::chrono;
using BigInt = bigint;
using BigFraction = std::pair<BigInt, BigInt>;

// function adds two BigInt fractions a/b + c/d
BigFraction addFractions(const BigFraction& a, const BigFraction& b){
  BigInt a_numerator = a.first;
  BigInt a_denominator = a.second;
  BigInt b_numerator = b.first;
  BigInt b_denominator = b.second;

  BigInt numerator = (a_numerator * b_denominator) + (b_numerator * a_denominator);
  BigInt denominator = a_denominator * b_denominator;
  return {numerator, denominator};
}

// function multiplies two BigInt fractions a/b * c/d
BigFraction multiplyFractions(const BigFraction& a, const BigFraction& b){
  BigInt a_numerator = a.first;
  BigInt a_denominator = a.second;
  BigInt b_numerator = b.first;
  BigInt b_denominator = b.second;

  BigInt numerator = a_numerator * b_numerator;
  BigInt denominator = a_denominator * b_denominator;
  return {numerator, denominator};
}

int main(){
  cout << "Performance Comparison: int vs. long int vs. BigInt\n\n";

  //  int addition timing
  auto start = high_resolution_clock::now();
  int sum_int = 0;
  for (int i = 0; i < 10000000; i++){
    sum_int += i;
  }
  auto end = high_resolution_clock::now();
  auto int_add_time = duration_cast<microseconds>(end - start).count();
  cout << "Int addition time: " << int_add_time << " microseconds\n";

  // long int addition timing
  start = high_resolution_clock::now();
  long long sum_long = 0;
  for (long long i = 0; i < 10000000; i++){
    sum_long += i;
  }
  end = high_resolution_clock::now();
  auto long_add_time = duration_cast<microseconds>(end - start).count();
  cout << "Long int addition time: " << long_add_time << " microseconds\n";

  // bigInt addition timing
  start = high_resolution_clock::now();
  BigInt sum_big = BigInt("0");
  for (int i = 0; i < 10000; i++){
    sum_big = sum_big + BigInt(std::to_string(i));
  }
  end = high_resolution_clock::now();
  auto bigint_add_time = duration_cast<microseconds>(end - start).count();
  cout << "BigInt addition time: " << bigint_add_time << " microseconds\n\n";

  // int multiplication timing
  start = high_resolution_clock::now();
  int prod_int = 1;
  for (int i = 1; i <= 12; i++){
    prod_int *= i;
  }
  end = high_resolution_clock::now();
  auto int_mul_time = duration_cast<microseconds>(end - start).count();
  cout << "Int multiplication time: " << int_mul_time << " microseconds\n";

  // long int multiplication timing
  start = high_resolution_clock::now();
  long long prod_long = 1;
  for (long long i = 1; i <= 20; i++){
    prod_long *= i;
  }
  end = high_resolution_clock::now();
  auto long_mul_time = duration_cast<microseconds>(end - start).count();
  cout << "Long int multiplication time: " << long_mul_time << " microseconds\n";

  // bigInt multiplication timing
  start = high_resolution_clock::now();
  BigInt prod_big = BigInt("1");
  for (int i = 1; i <= 25; i++){
    prod_big = prod_big * BigInt(std::to_string(i));
  }
  end = high_resolution_clock::now();
  auto bigint_mul_time = duration_cast<microseconds>(end - start).count();
  cout << "BigInt multiplication time: " << bigint_mul_time << " microseconds\n";

  return 0;
}