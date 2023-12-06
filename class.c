#include <stdio.h>
#include "student.h"
#include "exam.h"

void bubble_Sort(Student list[], int n);
void sort(Student list[], int* n);
//void del();
void show();

//int compareStudents(const void* a, const void* b);
//void sortStudentsFromFile(const char* filename);

int main() {

	Student studentsArr[20];
	Exam examArr[20];

	int numberOfStudents = 0;
	int n;

	//show();
	//add(studentsArr, &numberOfStudents);
	//del();
	//show1();
	//exam(examArr, &numberOfStudents);
	sort(studentsArr, &n);

	//sortStudentsFromFile("students.txt");

	return 0;
}
