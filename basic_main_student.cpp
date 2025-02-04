#include <vector>
#include <iostream>

#include "student.h"

int main() {
  student greatStudent = get_student_struct_data();

  output_student_data(greatStudent);

  student otherStudent = greatStudent;

  output_student_data(otherStudent);

  otherStudent.name = "Alanza";
  otherStudent.final = 95; 
  otherStudent.hw_grades[0] = -6;
  otherStudent.hw_grades[1] = -6;
  otherStudent.hw_grades[2] = -6;

  output_student_data(otherStudent);

  cout << "Back to the greatStudent" << endl;

  output_student_data(greatStudent);

  return 0; 
}