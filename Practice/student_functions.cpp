#include "student.h"
#include <iostream>

student get_student_struct_data() {
  student s;

  cout << "Enter the student's name: ";
  cin >> s.name;

  cout << "Enter the student's final: ";
  cin >> s.final;

  cout << "Enter homework scores: ";

  int score;

  while(cin >> score) {
    cout << "Enter a homework score (^D to exit): ";
    s.hw_grades.push_back(score);
  }
  return s;
}

void output_student_data(student st) {
  cout << st.name << endl;
  cout << "Final: " << st.final << endl;
  cout << "Midterm: " << st.midterm << endl;
  cout << "Homework scores: " << endl;

  for (auto grade : st.hw_grades) {
    cout << grade << endl;
  }
}