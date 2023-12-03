#include <stdio.h>
#include "exam.h"

void exam(Exam list[], int* n);
char* grades(double avg);

void exam(Exam list[], int* n) {

	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, "exam.txt", "r");

	int i = 0;
	double avg[20];

	if (err == 0 && NULL != fp) {
		while (fscanf_s(fp, "%d %s %d %d", &list[i].id, list[i].name, sizeof(list[i].name), &list[i].mid_score, &list[i].final_score) == 4) {
			avg[i] = (list[i].mid_score + list[i].final_score) / 2.0;
			i++;
		}
		*n = i;
		fclose(fp);

		printf("학번\t\t이름\t중간\t기말\t평균\t학점\n");
		for (int i = 0; i < *n; i++) {
			printf("%d\t%5s\t%d\t%d\t%.1f\t%s\n", list[i].id, list[i].name, list[i].mid_score, list[i].final_score, avg[i], grades(avg[i]));
		}
	}
	else {
		printf("File Open Error...\n");
	}
}

char* grades(double avg) {
	
	if (avg >= 95) {
		return "A+";
	}
	else if (avg >= 90) {
		return "A";
	}
	else if (avg >= 85) {
		return "B+";
	}
	else if (avg >= 80) {
		return "B";
	}
	else if (avg >= 75) {
		return "C+";
	}
	else if (avg >= 70) {
		return "C";
	}
	else if (avg >= 65) {
		return "D+";
	}
	else if (avg >= 60) {
		return "D";
	}
	else
		return "F";
	}