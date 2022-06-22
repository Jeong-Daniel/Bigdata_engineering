#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int** arr;
	//더블포인터 선언
	int height, width;

	printf("세로 가로 입력 : ");
	scanf("%d %d", &height, &width);

	arr = (int**)malloc(sizeof(int) * height);
	for (int i = 0; i < height; i++) {
		arr[i] = (int*)malloc(sizeof(int) * width);
		for (int j = 0; j < width; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}