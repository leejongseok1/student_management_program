#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void show();
void add(Student* students, int* num);
void del();
void sort(Student list[], int* n);
void bubble_Sort(Student list[], int n);




void show() {

	char str[200];
	FILE* fp;
	errno_t err;
	
	err = fopen_s(&fp, "students.txt", "rt");

	if (NULL != fp) {
		printf("학번\t\t이름\t전화\t\t생년월일\t성별\t키\t이메일\n");
		
		while (NULL != fgets(str, sizeof(str), fp))
		{
			printf("%s", str);
		}
		fclose(fp);
	}
	else
		printf("파일 열기 실패\n");

	return 0;
}



void add(Student *students, int* num) {

	//FILE* file = fopen("student.txt", "a");

	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, "students.txt", "a");

	if (NULL != fp) {
		printf("학번 : ");
		scanf_s("%d", &students[*num].id);

		while (getchar() != '\n');

		printf("이름 : ");
		fgets(students[*num].name, sizeof(students[*num].name), stdin);
		students[*num].name[strcspn(students[*num].name, "\n")] = 0;

		printf("전화 : ");
		fgets(students[*num].tel, sizeof(students[*num].tel), stdin);
		students[*num].tel[strcspn(students[*num].tel, "\n")] = 0;

		printf("생년월일 : ");
		scanf_s("%d", &students[*num].birth);

		while (getchar() != '\n');

		printf("성 : ");
		scanf_s("%c", &students[*num].gender, 1);

		while (getchar() != '\n');

		printf("키 : ");
		scanf_s("%d", &students[*num].height);

		printf("이메일 : ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		fgets(students[*num].email, sizeof(students[*num].email), stdin);
		students[*num].email[strcspn(students[*num].email, "\n")] = '\0';

		printf("\n %s 의 정보가 추가되었습니다.\n", students[*num].name);

		fprintf(fp, "%d\t", students[*num].id);
		fprintf(fp, "%s\t", students[*num].name);
		fprintf(fp, "%s\t", students[*num].tel);
		fprintf(fp, "%d\t", students[*num].birth);
		fprintf(fp, "%c\t", students[*num].gender);
		fprintf(fp, "%d\t", students[*num].height);
		fprintf(fp, "%s\n", students[*num].email);

		fclose(fp);
		(*num)++;
	} else {
		printf("File Open Error...\n");
	}
}

/*
void del() {

	int idToDel;
	printf("학번 : ");
	scanf_s("%d", &idToDel);

	FILE* fp;
	FILE* temp;
	errno_t err1;
	errno_t err2;

	err1 = fopen_s(&fp, "students.txt", "r");
	err2 = fopen_s(&temp, "temp.txt", "w");

	if (fp == NULL || temp == NULL || err1 != 0 || err2 != 0) {
		printf("File Open Error...\n");
		exit(1);
	}

	Student student;
	int found = 0;

	while (fread(&student, sizeof(Student), 1, fp)) {
		if (student.id != idToDel) {
			fwrite(&student, sizeof(Student), 1, temp);
		}
		else {
			found = 1;
		}
	}
	fclose(fp);
	fclose(temp);

	if (!found) {
		remove("temp.txt");
		printf("해당 학생의 정보를 찾을 수 없습니다.\n");
	}
	else {
		remove("students.txt");
		rename("temp.txt", "students.txt");
		printf("%s의 정보가 삭제되었습니다.\n", student.name);
	}
} */

void del() {

	int studentId;
	printf("학번 : ");
	scanf_s("%d", &studentId);


	FILE* fileIn, * fileOut;
	Student student;

	if (fopen_s(&fileIn, "students.txt", "r") != 0) {
		perror("File Open Error...");
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&fileOut, "temp.txt", "w") != 0) {
		perror("File Open Error...");
		fclose(fileIn);
		exit(EXIT_FAILURE);
	}

	int found = 0;

	while (fscanf_s(fileIn, "%d %s %s %d %c %d %s",
		&student.id,
		student.name,
		student.tel,
		&student.birth,
		&student.gender,
		&student.height,
		student.email) != EOF) {

		if (student.id != studentId) {
			found = 1;
		} else {
			fprintf(fileOut, "%d %s %s %d %c %d %s\n",
				student.id,
				student.name,
				student.tel,
				student.birth,
				student.gender,
				student.height,
				student.email);
		}
	}

	fclose(fileIn);
	fclose(fileOut);

	if (!found) {
		printf("해당 학생의 정보를 찾을 수 없습니다.\n");
		remove("temp.txt");
	}
	else {
		if (remove("students.txt") != 0) {
			perror("Error deleting file...");
			exit(EXIT_FAILURE);
		}
		if (rename("temp.txt", "students.txt") != 0) {
			perror("Error renaming file...");
			exit(EXIT_FAILURE);
		}

		printf("%d 학생의 정보가 삭제되었습니다.\n", studentId);
	}
}

void sort(Student list[], int* n) {

	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, "students.txt", "r");

	int i = 0;
	int height[20];
	int temp = 0;

	if (err == 0 && NULL != fp) {
		while (fscanf_s(fp, "%d %s %s %d %c %d %s", &list[i].id, list[i].name, sizeof(list[i].name),
																	list[i].tel, sizeof(list[i].tel), &list[i].birth,
																	&list[i].gender, sizeof(list[i].gender), &list[i].height,
																	list[i].email, sizeof(list[i].email)) == 7) 
		{
			height[i] = list[i].height;
			i++;
		}
		*n = i;
		fclose(fp);

		bubble_Sort(list, *n);

		printf("학번\t\t이름\t전화\t\t생년월일\t성별\t키\t이메일\n");
		
		for (i = 0; i < *n; i++) {
			printf("%d\t%s\t%s\t%d\t%c\t%d\t%s\n",list[i].id, list[i].name, list[i].tel, list[i].birth, list[i].gender,  list[i].height, list[i].email);
		}
		

		} else {
		printf("File Open Error...\n");
	}

}

void bubble_Sort(Student list[], int n) {
	// 키를 기준으로 오름차순 정렬
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {

			if (list[j].height > list[j + 1].height) {

				Student temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			// 키가 같다면 name ㄱㄴㄷ 순으로 정렬
			else if (list[j].height == list[j + 1].height && strcmp(list[j].name, list[j + 1].name) > 0) {
				Student temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}


