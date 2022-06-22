#include <stdio.h>
#include <math.h>
# define _CRT_SECURE_NO_WARNINGS

struct student{
	int std_num;
	char name[10];
	int age;
};

int main() {
	struct student s;
	struct student* sp;

	printf("학번 입력 : ");
	scanf_s("%d", &s.std_num);

	printf("이름 입력 : ");
	scanf_s("%s", s.name);

	printf("나이 입력 : ");
	scanf_s("%d", &s.age);

	sp = &s;

	printf("\n");
	printf("학번 : %d", sp->std_num);
	//printf("학번 : %d", (*sp).std_num);
	printf("이름 : %s", sp->name);
	printf("나이 : %d", sp->age);

	return 0;
}