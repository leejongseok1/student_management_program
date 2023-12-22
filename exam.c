#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "student.h"
#include "exam.h"

const char* grade(float avg){

	if (avg >= 95) {
		return "A+";
	} else if (avg >= 90){
		return "A";
	} else if (avg >= 85){
		return "B+";
	} else if (avg >= 80){
		return "B";
	} else if (avg >= 75){
		return "C+";
	} else if (avg >= 70){
		return "C";
	} else if (avg >= 65){
		return "D+";
	} else if (avg >= 60){
		return "D";
	} else {
		return "F";
	}

}

void exam(student* st, int cnt){
	
	FILE* examfp;
	char buff[200];
	char* tok;
	char* context;
	EXAM* exam_mem;
	int cntexam = 0;
	float avg;
	int i, findex;

	exam_mem = (EXAM*)malloc(sizeof(EXAM) * STUCNT);

	fopen_s(&examfp, "exam.txt", "r");
	if(examfp == NULL) {
		printf("exam.txt 파일이 존재하지 않습니다.\n");
	} else {
		i = 0;
		printf("exam.txt 파일이 존재합니다. ");
		while (NULL != fgets(buff, 200, examfp)) {
			tok = strtok_s(buff, "\t", &context);
			strcpy_s(exam_mem[i].id, 9, tok);
			tok = strtok_s(NULL, "\t", &context);
			strcpy_s(exam_mem[i].name, 21, tok);
			tok = strtok_s(NULL, "\t", &context);
			if (tok != NULL)
				exam_mem[i].mid = atoi(tok);
			else
				exam_mem[i].mid = 0;
			
			tok = strtok_s(NULL, "\t\n", &context);
			if (tok != NULL)
				exam_mem[i].final = atoi(tok);
			else
				exam_mem[i].final = 0;
			
			i++;
		}

		printf("%d 개의 데이터를 읽었습니다.\n", i);
		fclose(examfp);
		cntexam = i;
	}

	printf("학번\t\t이름\t중간\t기말\t평균\t학점\n");
	printf("-------------------------------------------------------------\n");
	for (i = 0; i < cnt; i++){
		findex = find_student(exam_mem, cntexam, st[i].id);
		if (findex >= 0){
			avg = (float)(exam_mem[findex].mid + exam_mem[findex].final / 2.0);
			
			printf("%s\t%s\t%d\t%d\t%.2f\t%s\n", exam_mem[findex].id, exam_mem[findex].name, exam_mem[findex].mid, exam_mem[findex].final, avg, grade(avg));
		}
		else {
			avg = 0.0;
			printf("%s\t%s\t%d\t%d\t%.2f\t%s\n", st[i].id, st[i].name, 0, 0, avg, grade(avg));
		}
	}
	free(exam_mem);
}

int find_student(EXAM* ex, int excnt, char* id){
	int i;
	int idx = -1;
	for (i = 0; i < excnt; i++){
		if (strcmp(ex[i].id, id) == 0){
			idx = i;
			break;
		}
	}
	return idx;
}
