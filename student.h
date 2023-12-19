#pragma once

typedef struct
{
	int id;
	char* name;
	char* tel;
	int birth;
	char gender;
	int height;
	char* email;
}Student;

typedef struct
{
	int id;
	char name[20];
	char tel[20];
	int birth;
	char gender;
	int height;
	char email[30];
}Student_2;