#include "bigint.h"
#include <iostream>
#include <chrono>
#include <utility>

using namespace std;
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

// function measures the time taken to execute a function
template<typename Func>
long long timeFunction(Func f){
  auto start = chrono::high_resolution_clock::now();
  f();
  auto end = chrono::high_resolution_clock::now();
  return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int main(){
  BigFraction f1 = {BigInt("123456789123456789"), BigInt("987654321")};
  BigFraction f2 = {BigInt("112233445566778899"), BigInt("998877665544332211")};

  cout << "Fraction 1: " << f1.first << "/" << f1.second << endl;
  cout << "Fraction 2: " << f2.first << "/" << f2.second << endl << endl;

  // add two fractions and display time it took
  auto duration = timeFunction([&](){
    BigFraction sum = addFractions(f1, f2);
    cout << "Sum: " << sum.first << "/" << sum.second << endl;
  });
  cout << "Addition took " << duration << " microseconds." << endl << endl;

  // multiply two fractions and display time it took
  duration = timeFunction([&](){
    BigFraction product = multiplyFractions(f1, f2);
    cout << "Product: " << product.first << "/" << product.second << endl;
  });
  cout << "Multiplication took " << duration << " microseconds." << endl;

  return 0;
}