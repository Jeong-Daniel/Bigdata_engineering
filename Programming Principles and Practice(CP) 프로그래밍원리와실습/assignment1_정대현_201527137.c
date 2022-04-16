#include <stdio.h>

int main() {
	int sub_1, sub_2, sub_3, sub_4, sub_5;
	sub_1 = 90, sub_2 = 84, sub_3 = 95, sub_4 = 100, sub_5 = 78;
	int total = sub_1 + sub_2 + sub_3 + sub_4 + sub_5;
	float avg;
	avg = (double)total / 5;
	printf("201527137 님의 성적표는 다음과 같습니다.\n");
	printf("=====================================\n");
	printf("과목 1 : %d\n", sub_1);
	printf("과목 2 : %d\n", sub_2);
	printf("과목 3 : %d\n", sub_3);
	printf("과목 4 : %d\n", sub_4);
	printf("과목 5 : %d\n", sub_5);
	printf("=====================================\n");
	printf("평균 : %.2f\n", avg);
	printf("=====================================\n");
}