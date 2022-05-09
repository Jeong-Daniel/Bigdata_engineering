#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int i, j, temp;
    printf("input 10 numbers: ");
    int array[10];
    // 일반 배열 입력
    for (i = 0; i < 10; i++) {
        scanf_s("%d", &array[i]);
    }

    // 포인터 배열 선언
    int* array_p[10];
   
    // 포인터 배열 지정
    for (i = 0; i < 10; i++) {
        array_p[i] = &array[i];
    }

    // 포인터 배열 오름차순 정렬
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (*array_p[i] > *array_p[j]) {
                temp = *array_p[i];
                *array_p[i] = *array_p[j];
                *array_p[j] = temp;
            }
        }
    }

    int num, num_temp;
    while (1) {
        printf("몇 번째로 큰 정수를 출력할까요?<종료=0>: ");
        scanf_s("%d", &num);
        if (num == 0) {
            printf("프로그램이 종료되었습니다 감사합니다.");
            break;
        }
        else if ((num < 0) || (num > 10)) {
            printf("범위를 초과했습니다.\n");
            continue;
        }
        else {
            num_temp = (10 - num);
            printf("%d 번째로 큰 정수: %d", num, *array_p[num_temp]);
            printf("\n");
        }
    }
    return 0;
}