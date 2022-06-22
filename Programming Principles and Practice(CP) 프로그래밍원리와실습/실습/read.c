#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	FILE* fp;
	int menu;
	char title[100];
	char content[200];

	while (1) {
		printf("메뉴를 선택하세요 <1:메모추가 2: 메모읽기 0: 종료> ");
		scanf("%d",&menu);
		getchar();
		if (menu == 0)
			break;
		else if (menu == 1){
			printf("추가할 메모의 제목 입력 : ");
			gets_s(title, sizeof(title));
			printf("추가할 메모의 내용 입력 : ");
			gets_s(content, sizeof(content));

			strcat(title, ".txt");
			fp = fopen(title, 'a');
			fputs(content, fp);

			fclose(fp);
		}
		else if (menu == 2){
			printf("읽을 메모의 제목 : ");
			gets_s(title, sizeof(title));

			strcat(title, ".txt");
			fp = fopen(title, 'r');
			fgets(content, sizeof(content), fp);
			printf("읽은 메모의 내용 : %s\n", content);
			fclose(fp);
		}
		else {
			continue;
		}
	}
	return 0;
}