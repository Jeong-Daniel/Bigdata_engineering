#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int i, j, temp;
    printf("input 10 numbers: ");
    int array[10];
    // �Ϲ� �迭 �Է�
    for (i = 0; i < 10; i++) {
        scanf_s("%d", &array[i]);
    }

    // ������ �迭 ����
    int* array_p[10];
   
    // ������ �迭 ����
    for (i = 0; i < 10; i++) {
        array_p[i] = &array[i];
    }

    // ������ �迭 �������� ����
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
        printf("�� ��°�� ū ������ ����ұ��?<����=0>: ");
        scanf_s("%d", &num);
        if (num == 0) {
            printf("���α׷��� ����Ǿ����ϴ� �����մϴ�.");
            break;
        }
        else if ((num < 0) || (num > 10)) {
            printf("������ �ʰ��߽��ϴ�.\n");
            continue;
        }
        else {
            num_temp = (10 - num);
            printf("%d ��°�� ū ����: %d", num, *array_p[num_temp]);
            printf("\n");
        }
    }
    return 0;
}