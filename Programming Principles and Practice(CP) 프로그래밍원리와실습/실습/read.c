#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	FILE* fp;
	int menu;
	char title[100];
	char content[200];

	while (1) {
		printf("�޴��� �����ϼ��� <1:�޸��߰� 2: �޸��б� 0: ����> ");
		scanf("%d",&menu);
		getchar();
		if (menu == 0)
			break;
		else if (menu == 1){
			printf("�߰��� �޸��� ���� �Է� : ");
			gets_s(title, sizeof(title));
			printf("�߰��� �޸��� ���� �Է� : ");
			gets_s(content, sizeof(content));

			strcat(title, ".txt");
			fp = fopen(title, 'a');
			fputs(content, fp);

			fclose(fp);
		}
		else if (menu == 2){
			printf("���� �޸��� ���� : ");
			gets_s(title, sizeof(title));

			strcat(title, ".txt");
			fp = fopen(title, 'r');
			fgets(content, sizeof(content), fp);
			printf("���� �޸��� ���� : %s\n", content);
			fclose(fp);
		}
		else {
			continue;
		}
	}
	return 0;
}