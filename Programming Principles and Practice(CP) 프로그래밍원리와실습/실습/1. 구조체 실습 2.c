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

	printf("�й� �Է� : ");
	scanf_s("%d", &s.std_num);

	printf("�̸� �Է� : ");
	scanf_s("%s", s.name);

	printf("���� �Է� : ");
	scanf_s("%d", &s.age);

	sp = &s;

	printf("\n");
	printf("�й� : %d", sp->std_num);
	//printf("�й� : %d", (*sp).std_num);
	printf("�̸� : %s", sp->name);
	printf("���� : %d", sp->age);

	return 0;
}