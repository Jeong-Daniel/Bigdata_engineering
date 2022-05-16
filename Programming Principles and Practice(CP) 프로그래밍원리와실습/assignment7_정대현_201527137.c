#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    //quit를 받기 전까지는 무한루프
    while (1) {
        char str[30];
        char* str2 = NULL;

        printf("input String > ");
        //중간에 공백이 들어오더라도 문장을 입력받을 수 있게 설정
        scanf("%[^\n]s", str);
        //scanf_s("%[^\n]s", str);

        //quit가 들어오면 return으로 프로그램 종료
        if ((strcmp(str, "quit") == 0)) {
            return 0;
        }

        char lineFeed[30] = ". \n";
        char* ptr = strchr(str, '.');
        if (ptr != NULL) {
            char* temp = strtok_r(str, ".", &str2);
            //char* temp = strtok_s(str, ".", &str2);
            //컴파일에 따라서 strtok_r일때도 strtok_s로 써야할때가 다른거 같다.
            //이유는 모르겠으나 temp부터 앞에서 붙이니 str2가 다음줄에서 사라짐
            strcat(lineFeed, str2);
            strcat(temp, lineFeed);
            printf("%s\n", temp);
        }
        else {
            char* temp = strtok_r(str, ",", &str2);
            strcat(str2, ", ");
            strcat(str2, temp);
            printf("%s\n", str2);
        }
        //다음 명령어 시작전 버퍼초기화
        getchar();
    }
}