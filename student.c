#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "student.h"
#include "exam.h"

void show(student* st, int cnt){
	
	printf("학번\t\t이름\t전화\t생년월일\t\t성별]t키\t이메일\n");
	printf("-----------------------------------------------------------------");

	for (int i = 0; i < cnt; i++){
		printf("%s\t%s\t%s\t%s\t%c\t%d\t%s\n", st[i].id, st[i].name, st[i].tel, st[i].birth, st[i].gender, st[i].height, st[i].email);
	}
}

int add(student* st, int cnt){

	char id[9];
	char name[21];
	char tel[15];
	char birth[9];
	char gender;
	int height;
	char email[31];

	printf("학번: ");
	scanf_s("%s", id, sizeof(id));

	printf("이름: ");
	scanf_s("%s", name, sizeof(name));

	printf("전화: ");
	scanf_s("%s", tel, sizeof(tel));

	printf("생년월일: ");
	scanf_s("%s", birth, sizeof(birth));

	printf("성 (m/f): ");
	scanf_s("%c", &gender, sizeof(gender));

	printf("키: ");
	scanf_s("%d", &height);

	printf("이메일: ");
	scanf_s("%s", email, sizeof(email));

	strcpy_s(st[cnt].id, sizeof(id), id);
	strcpy_s(st[cnt].name, sizeof(name), name);
	strcpy_s(st[cnt].tel, sizeof(tel), tel);
	strcpy_s(st[cnt].birth, sizeof(birth), birth);
	st[cnt].gender = gender;
	st[cnt].height = height;
	strcpy_s(st[cnt].email, sizeof(email), email);

	printf("%s 학생이 추가되었습니다.\n", id);

	return cnt + 1;
}

int del(student* st, int cnt, char* id){
	
	int idx = -1;

	for (int i = 0; i < cnt; i++){
		if(strcmp(st[i].id, id) == 0) {
			idx = i;
			break;
		}
	}

	if (idx >= 0) {
		for (int i = idx; i < cnt - 1; i++) {
			st[i] = st[i + 1];
		}
		cnt--;
		printf("%s 학생을 삭제하였습니다.\n", id);
	} else {
		printf("%s 의 정보가 없습니다.\n", id);
	}
	return cnt;
}

void sort(student* st, int cnt){
	
	student temp;
	student* s_list;
	int sort;

	s_list = (student*) malloc (sizeof(student) * cnt);
	memcpy(s_list, st, sizeof(student) * cnt);
	
	// 자신과 비교한 인덱스 제외
	for (int a = 0; a < cnt - 1; a++){
		sort = a;
		
		// 자신과 비교한 인덱스 제외
		for (int b = a + 1; b < cnt; b++){
			if (s_list[b].height < s_list[sort].height)
				sort = b;

			// 선택정렬
			temp = s_list[a];
			s_list[a] = s_list[sort];
			s_list[sort] = temp;
		}

		show(s_list, cnt);
	}
}

void save_student(student* st, int cnt) {
	
	FILE* fp;
	
	printf("변경 사항을 파일로 저장합니다.\n");
	fopen_s(&fp, "students.txt", "w");

	for(int i = 0; i < cnt; i++){
		fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%d\t%s\n", st[i].id, st[i].name, st[i].tel, st[i].birth, st[i].gender, st[i].height, st[i].email);
	}
	fclose(fp);
}

int memory_expand(student* st, int cnt){
	
	student* buffer;
	
	buffer = st;

	st = (student *)realloc(st, sizeof(student) * (cnt + ADDCNT));
	if(st != NULL)
		printf("메모리 확장.\n");
	else
		printf("메모리 확장 실패.\n");

	return cnt + ADDCNT;
}