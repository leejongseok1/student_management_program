#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#define STUCNT 20
#define ADDCNT 10
#define MAXEXAM 10

struct student
{
	int id[9];
	char name[21];
	char tel[15];
	int birth[9];
	char gender;
	int height;
	char email[31];
};

typedef struct student student;
void show(student* st, int cnt);
int add(student* st, int cnt);
void save(student* st, int cnt);
int del(student* st, int cnt, char* id);
void sort(student* st, int cnt);
int memory_expand(student* st, int cnt);

#endif

