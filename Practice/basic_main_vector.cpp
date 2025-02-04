#include <vector>
#include <iostream>
using namespace std;

vector<int> hw_grades;

int main() {
	hw_grades.push_back(9);
	hw_grades.push_back(8);
	hw_grades.push_back(10);
	
  for (auto grade: hw_grades) {
		cout << grade << endl;
	}
	return 0;
}
