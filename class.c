#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "exam.h"

void show();
void add(Student* students, int* num);
void sort(Student_2 list[], int* n);
void bubble_Sort(Student_2 list[], int* n);

void exam(Exam list[], int* n);
char* grades(double avg);

int main(int argc, char *argv[]) {

	Student students[20];
	Exam examArr[20];
	Student_2 students_2[20]; // sort 용
	int n = 0; // 포인터를 사용해 n 값을 update 함 - 학생 수

	if (argc < 2) {
		return 1;
	}

	if (strcmp(argv[1], "show") == 0) {
		show();
	}
	else if (strcmp(argv[1], "add") == 0) {
		add(students, &n);
	}
	else if (strcmp(argv[1], "exam") == 0) {
		exam(examArr, &n);
	}
	else if (strcmp(argv[1], "sort") == 0) {
		sort(students_2, &n);
	}
	return 0;
}
