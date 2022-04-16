#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
int add(int param1, int param2) {
    return param1 + param2;
}
int min(int param1, int param2) {
    return param1 - param2;
}
int multi(int param1, int param2) {
    return param1 * param2;
}
float div(float param1, float param2) {
    return param1 / param2;
}

int main() {
    while (1) {
        printf("연산자를 입력해주세요: ");
        char oper = getchar();

        if (oper == 'q') {
            printf("eixt. \n");
            break;
        }

        if (oper != '+' && oper != '-' && oper != '*' && oper != '/' && oper != '!') {
            printf("연산자를 다시 입력해주세요\n");
            scanf("%*c", oper);
            continue;
        }

        if (oper == '+' || oper == '-' || oper == '*') {
            int i, k;
            printf("두 정수를 입력해주세요 : ");
            scanf("%d%d", &i, &k);
            if (oper == '+') {
                int num = add(i, k);
                printf("%d\n", num);
                scanf("%*c", oper);
                continue;
            }
            else if (oper == '-') {
                int num = min(i, k);
                printf("%d\n", num);
                scanf("%*c", oper);
                continue;
            }
            else {
                int num = multi(i, k);
                printf("%d\n", num);
                scanf("%*c", oper);
                continue;
            }
        }
        else if (oper == '/') {
            float i, k;
            printf("두 정수를 입력해주세요 : ");
            scanf("%f%f", &i, &k);
            if (k == 0) {
                printf("0으로는 나눌 수 없습니다\n");
                scanf("%*c", oper);
                continue;
            }
            float num = div(i, k);
            printf("%.4f\n", num);
            scanf("%*c", oper);
            continue;
        }
        else {
            while (1) {
                int j = 0;
                printf("정수를 하나 입력해주세요 : ");
                scanf("%d", &j);
                if (j < 1) {
                    printf("양수만 입력이 가능합니다.\n");
                    continue;
                }
                int num = factorial(j);
                printf("%d\n", num);
                scanf("%*c", oper);
                break;
            }
        }
    }
    return 0;
}