#include "bigint.h"
#include <cassert>
#include <iostream>
#include <utility>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using BigInt = bigint;
using BigFraction = std::pair<BigInt, BigInt>;

// Function adds two BigInt fractions a/b + c/d
BigFraction addFractions(const BigFraction& a, const BigFraction& b){
  BigInt a_numerator = a.first;
  BigInt a_denominator = a.second;
  BigInt b_numerator = b.first;
  BigInt b_denominator = b.second;
  BigInt numerator = (a_numerator * b_denominator) + (b_numerator * a_denominator);
  BigInt denominator = a_denominator * b_denominator;
  return {numerator, denominator};
}

// Function multiplies two BigInt fractions a/b * c/d
BigFraction multiplyFractions(const BigFraction& a, const BigFraction& b){
  BigInt a_numerator = a.first;
  BigInt a_denominator = a.second;
  BigInt b_numerator = b.first;
  BigInt b_denominator = b.second;
  BigInt numerator = a_numerator * b_numerator;
  BigInt denominator = a_denominator * b_denominator;
  return {numerator, denominator};
}

TEST_CASE("BigInt Fraction Tests"){
  SUBCASE("fraction addition"){
    BigFraction f1 = {BigInt("1"), BigInt("2")};
    BigFraction f2 = {BigInt("1"), BigInt("3")};
    BigFraction result = addFractions(f1, f2);

    CHECK(result.first == BigInt("5"));
    CHECK(result.second == BigInt("6"));
  }

  SUBCASE("fraction multiplication"){
    BigFraction f1 = {BigInt("1"), BigInt("2")};
    BigFraction f2 = {BigInt("2"), BigInt("3")};
    BigFraction result = multiplyFractions(f1, f2);

    CHECK(result.first == BigInt("2"));
    CHECK(result.second == BigInt("6"));
  }

  SUBCASE("Large fraction addition"){
    BigFraction f1 = {BigInt("123456789"), BigInt("2")};
    BigFraction f2 = {BigInt("987654321"), BigInt("4")};
    BigFraction result = addFractions(f1, f2);

    CHECK(result.first == BigInt("2469135798"));
    CHECK(result.second == BigInt("8"));
  }

  SUBCASE("Large fraction multiplication"){
    BigFraction f1 = {BigInt("12345"), BigInt("67890")};
    BigFraction f2 = {BigInt("54321"), BigInt("98765")};
    BigFraction result = multiplyFractions(f1, f2);

    BigInt expected_num = BigInt("12345") * BigInt("54321");
    BigInt expected_den = BigInt("67890") * BigInt("98765");

    CHECK(result.first == expected_num);
    CHECK(result.second == expected_den);
  }
}