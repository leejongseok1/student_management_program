#include <stdio.h>
#include "student.h"
#include "exam.h"

void bubble_Sort(Student_2 list[], int n);
void sort(Student_2 list[], int* n);
//void del();
void show();



int main() {

	Student students[20];
	Exam examArr[20];
	Student_2 students_2[20]; // sort 용

	int n = 0;

	show();
	//add(students, &n);
	//del();
	//exam(examArr, &n);
	//sort(students_2, &n);

	return 0;
}
