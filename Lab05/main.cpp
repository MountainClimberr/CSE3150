#include "cosineDistance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main(){
  // open vectors.txt
  std::ifstream input("vectors.txt");
  if (!input){
    std::cout << "Error: Cannot open vectors.txt\n";
    return 1;
  }

  std::vector<Vec> all_vectors;
  int count = 0;
  double x;

  // Read the file
  while (input.good()){
    Vec current;
    current.id = count++;

    while (input >> x){
      current.components.push_back(x);
      if (input.peek() == '\n' || input.peek() == EOF)
        break;
    }

    // check if vector is empty
    if (!current.components.empty()){
      all_vectors.push_back(current);
    }
  }

  std::vector<Result> angle_pairs;

  // calculate cosine distance
  for (int i = 0; i < all_vectors.size(); i++){
    for (int j = i + 1; j < all_vectors.size(); j++){
      double theta = distance(
        all_vectors[i].components,
        all_vectors[j].components
      );

      // save the result
      angle_pairs.push_back(Result(
        all_vectors[i].id,
        all_vectors[j].id,
        theta
      ));
    }
  }

  // display results
  std::cout << "Cosine Distance:\n\n";

  for (const auto& result : angle_pairs){
    std::cout << "vectors: " << result.first_id << "  " << result.second_id
      << "    cosine distance: " << result.angle << std::endl;
  }

  return 0;
}
