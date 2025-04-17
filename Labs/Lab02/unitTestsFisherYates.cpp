#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "fisherYates.h"
#include <iostream>

using namespace std;

bool in_list(int list[], const int length, const int value) {
  bool is_in_list = false;
  for (int i = 0; i < length; i++) {
    if (value == list[i]) {
      is_in_list = true;
      break;
    }
  }
  return is_in_list;
}

bool exactly_one_in_list(int list[], const int length, const int value) {
  bool one_in_list = false;
  
  for (int i = 0; i < length; i++) {
    if (value == list[i]) {
      if (one_in_list) {
        one_in_list = false;
        break;
      } else {
        one_in_list = true;
      }
    }
  }
  return one_in_list;
}

// Test arrays
int nums_0[] = {};
int nums_1[] = {1, 2, 3};
int nums_2[] = {1, 1, -1, -1};
int nums_3[] = {-1, -1, 1, 1};

TEST_CASE("Testing well-balanced functions") {
  SUBCASE("in_list test") {
    int lst[] = {1, 2, 3};
    CHECK(in_list(lst, sizeof(lst)/sizeof(lst[0]), lst[0]));
    CHECK(in_list(lst, sizeof(lst)/sizeof(lst[0]), lst[1]));
    CHECK(in_list(lst, sizeof(lst)/sizeof(lst[0]), lst[2]));
    CHECK_FALSE(in_list(lst, sizeof(lst)/sizeof(lst[0]), 0));
    CHECK_FALSE(in_list(lst, sizeof(lst)/sizeof(lst[0]), -55));
  }

  SUBCASE("exactly_one_in_list test") {
    int lst_0[] = {};
    CHECK_FALSE(exactly_one_in_list(lst_0, sizeof(lst_0)/sizeof(lst_0[0]), 0));

    int lst_1[] = {1, 2, 3, 1};
    CHECK_FALSE(exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), lst_1[0])); // lst_1[0] == lst_1[3]
    CHECK(exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), lst_1[1]));
    CHECK(exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), lst_1[2]));
    CHECK_FALSE(exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), 0));
    CHECK_FALSE(exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), -55));
  }
}

// Not random arrays for testing
int not_random_swaps_0[] = {1, 0};
int not_random_swaps_1[] = {3, 2, 1};
int not_random_swaps_2[] = {3, 2, 1};
int init_list_0[] = {5, 40};
int init_list_1[] = {1, 2, 3, 4};
int init_list_2[] = {1, 2, 3, 4, 5};

int r_index = 0;

int NOT_random_0() {
  return not_random_swaps_0[r_index++];
}

int NOT_random_1() {
  return not_random_swaps_1[r_index++];
}

int NOT_random_2() {
  return not_random_swaps_2[r_index++];
}

TEST_CASE("Testing fisher_yates function") {
  SUBCASE("swap test") {
    int a = 8, b = -5;
    swap(&a, &b);
    CHECK(a == -5);

    int nums[] = {1, 2};
    int one_index_save = nums[1];
    int zero_index_save = nums[0];
    
    swap(&nums[0], &nums[1]);
    CHECK(nums[0] == one_index_save);
    CHECK(nums[1] == zero_index_save);
  }

  SUBCASE("well-balanced basic tests") {
    CHECK(is_well_balanced(nums_2, sizeof(nums_2)/sizeof(nums_2[0])));
    CHECK(is_well_balanced(nums_3, sizeof(nums_3)/sizeof(nums_3[0])));
    
    int not_balanced[] = {1, -1, 1, -1};
    CHECK(non_negative_prefix_sum(not_balanced, 4) == true);
    CHECK(non_positive_prefix_sum(not_balanced, 4) == false);
  }

  SUBCASE("prefix sum basic tests") {
    CHECK(non_negative_prefix_sum(nums_2, sizeof(nums_2)/sizeof(nums_2[0])));
    CHECK(non_positive_prefix_sum(nums_3, sizeof(nums_3)/sizeof(nums_3[0])));
    
    int mixed_sum[] = {1, -1, -1, 1};
    CHECK_FALSE(non_negative_prefix_sum(mixed_sum, 4));
    CHECK_FALSE(non_positive_prefix_sum(mixed_sum, 4));
  }

  SUBCASE("simulation basic test") {
    double result = run_simulation(2, 1000);
    CHECK(result >= 0.0);
    CHECK(result <= 1.0);
  }
}