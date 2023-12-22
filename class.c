#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "student.h"
#include "exam.h"

int main() {

	FILE* stufp;
	int cnt_student = 0;
	int cur_student = 0;
	student* stu_mem;
	int i, changeTag = 0;
	char command[30];
	char buff[200];
	char* tok;
	char* context;
	char id[9];
	int MaxMember;

	stu_mem = (student*) malloc (sizeof(student) * STUCNT);
	MaxMember = STUCNT;
	fopen_s(&stufp, "students.txt", "r");
	if (stufp == NULL) {
		printf("students.txt 파일이 존재하지 않습니다. txt 파일을 생성합니다.");
		fopen_s(&stufp, "students.txt", "w");
		fclose(stufp);
		cnt_student = 0;
	} else {
		i = 0;
		printf("students.txt 파일이 존재, ");
		while (NULL != fgets(buff, 200, stufp)) {
			tok = strtok_s(buff, "\t", &context);
			strcpy_s(stu_mem[i].id, 9, tok);
			tok = strtok_s(NULL, "\t", &context);
			strcpy_s(stu_mem[i].name, 21, tok);
			tok = strtok_s(NULL, "\t", &context);
			strcpy_s(stu_mem[i].tel, 15, tok);
			tok = strtok_s(NULL, "\t", &context);
			strcpy_s(stu_mem[i].birth, 9, tok);
			tok = strtok_s(NULL, "\t", &context);
			stu_mem[i].gender = tok[0];
			tok = strtok_s(NULL, "\t", &context);
			stu_mem[i].height = atoi(tok);
			tok = strtok_s(NULL, "\t", &context);
			strcpy_s(stu_mem[i].email, 31, tok);

			/*
			fscanf_s(stufp, "%s", stu_mem[i].id, 9);
			fscanf_s(stufp, "%s", stu_mem[i].name, 21);
			fscanf_s(stufp, "%s", stu_mem[i].tel, 15);
			fscanf_s(stufp, "%s", stu_mem[i].birth, 9);
			fscanf_s(stufp, "%c", stu_mem[i].gender);
			fscanf_s(stufp, "%d", stu_mem[i].height);
			fscanf_s(stufp, "%s", stu_mem[i].email, 31);
			*/
			
			i++;
			
			if (i == MaxMember)
					MaxMember = memory_expand(stu_mem, i);
		}
		printf("%d 개의 데이터를 읽었습니다.\n", i);
		fclose(stufp);
		cnt_student = i;
	}

while (1){
	printf("\n");
	printf(">>> ");

	scanf_s("%s", command, sizeof(command));

	if(strcmp(command, "show") == 0) {
		show(stu_mem, cnt_student);
	} else if (strcmp(command, "add") == 0) {
		cnt_student = add(stu_mem, cnt_student);
		changeTag = 1;
		if (cnt_student == MaxMember)
			MaxMember = memory_expand(stu_mem, cnt_student);
	} else if (strcmp(command, "del") == 0) {
		char id[9];
		printf("삭제할 학생의 학번을 입력하세요: ");
		scanf_s("%s", id, sizeof(id));

		cnt_student = del(stu_mem, cnt_student, id);
		changeTag = 1;
	} else if (strcmp(command, "sort") == 0) {
		sort(stu_mem, cnt_student);
	} else if (strcmp(command, "exam") == 0) {
		exam(stu_mem, cnt_student);
	} else if (strcmp(command, "quit") == 0) {
		if (changeTag = 1)
			save_student(stu_mem, cnt_student);
		else
			printf("변경된 내용이 없습니다.\n");
		
		free(stu_mem);
		printf("종료합니다.\n");
		break;
	} else {
		printf("잘못된 명령어입니다.\n");
	}
}
}
