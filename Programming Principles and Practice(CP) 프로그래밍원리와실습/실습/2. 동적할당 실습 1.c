#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char* str;
	int len;

	printf("���ڿ��� ���� : ");
	scanf("%d", &len);

	str = (char*)malloc(sizeof(char) * len);
	printf("���ڿ� �Է� : ");
	scanf("%s", str);
	printf("�Է¹��� ���ڿ� %s\n", str);

	return 0;
}