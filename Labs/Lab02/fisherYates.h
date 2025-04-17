#ifndef _FISHER_YATES_H
#define _FISHER_YATES_H


void swap(int* x, int* y);
void show_data(int array[], const int length);

// Fisher-Yates shuffle
void fisher_yates(int array[], const int length);

// Create array of 1s and -1s
void generate_initial_array(int array[], const int n);

// Check prefix sums
bool non_negative_prefix_sum(const int array[], const int length);
bool non_positive_prefix_sum(const int array[], const int length);

// Check if array is well-balanced
bool is_well_balanced(const int array[], const int length);

// Run simulation
double run_simulation(int n, int num_trials);

#endif