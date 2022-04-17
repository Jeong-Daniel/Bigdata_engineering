#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//소수를 판별하는 재귀함수
int recursive(int num, int i)
{
    int result = 0;

    if (i <= 0) return 0;

    if (num % i == 0) result = 1;
    else result = 0;

    result += recursive(num, i - 1);

    return result;
}

int main(void)
{
    int num, cnt = 0;
    int check = 1;

    printf("정수 입력 : ");
    scanf_s("%d", &num);
    //scanf("%d", &num); scanf보안에러

    cnt = recursive(num, num);
    if (cnt == 2) printf("%d는 소수입니다. \n", num);
    else {
        printf("%d = ", num);
        for (int i = 2;i <= num;i++) {
            if (num % i == 0) {
                num /= i;
                printf("%d", i);
                i = 1;
                if (check != num) printf("*");
            };
        };
        return 0;
    };
}