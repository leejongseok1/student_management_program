#pragma once

#ifndef EXAM_H
#define EXAM_H

struct exam {
	char id[9];
	char name[21];
	int mid; // 중간
	int final; // 기말
};

typedef struct exam EXAM;

void exam_student(student* st, int cnt);
int find_student(EXAM* ex, int excnt, char* id);

#endif
