#ifndef _STUDENT_H
#define _STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct student {
  string name;
  int final;
  int midterm;
  vector<int> hw_grades;
};

student get_student_struct_data();
void output_student_data(student st);

#endif