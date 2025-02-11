#include <iostream>
#include <cstdlib>  // for std::rand
#include "fisherYates.h"

using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void show_data(int array[], const int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

// FisherYates shuffle
void fisher_yates(int array[], const int length) {
  for (int i = 0; i < length - 1; i++) {
    int random_pos = std::rand() % (length - i);
    swap(&array[i], &array[random_pos + i]);
  }
}

// prefix sums algorithms
void generate_initial_array(int array[], const int n) {
  for (int i = 0; i < n; i++) {
    array[i] = 1;
  }
  for (int i = n; i < 2 * n; i++) {
    array[i] = -1;
  }
}

bool non_negative_prefix_sum(const int array[], const int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum = sum + array[i];
    if (sum < 0) {
      return false;
    }
  }
  return sum == 0;
}

bool non_positive_prefix_sum(const int array[], const int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum = sum + array[i];
    if (sum > 0) {
      return false;
    }
  }
  return sum == 0;
}

bool is_well_balanced(const int array[], const int length) {
  return non_negative_prefix_sum(array, length) || 
       non_positive_prefix_sum(array, length);
}

double run_simulation(int n, int num_trials) {
  int balanced_count = 0;
  int* current_array = new int[2 * n];
  
  for (int i = 0; i < num_trials; i++) {
    generate_initial_array(current_array, n);
    fisher_yates(current_array, 2 * n);
    
    if (is_well_balanced(current_array, 2 * n)) {
      balanced_count = balanced_count + 1;
    }
  }
  
  delete[] current_array;
  return (double)balanced_count / num_trials;
}