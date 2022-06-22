#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char* str;
	int len;

	printf("문자열의 길이 : ");
	scanf("%d", &len);

	str = (char*)malloc(sizeof(char) * len);
	printf("문자열 입력 : ");
	scanf("%s", str);
	printf("입력받은 문자열 %s\n", str);

	return 0;
}