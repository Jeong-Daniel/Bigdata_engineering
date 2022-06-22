#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

// 이미 있는 파일이 아닌 여기서 만들어진 파일만 가능
// 개행문자 처리 때문

typedef struct student {
	char name[10];
	char ID[20];
	char phone[10];
	char address[10];
}STUDENT;

int main() {
	char fname[] = "student.txt";
	FILE* fp;
	STUDENT s;
	int select = 0;

	//파일을 열어서 파일이 없다면 student.txt파일 생성
	if (fopen_s(&fp, fname,"r")!=NULL){
		fopen_s(&fp, fname, "w+");
		printf("%s 파일을 생성하였습니다.\n",fname);
	}
	fclose(fp);

	while (1) {
		printf("관리 옵션을 선택해 주세요(1. 정보 입력 | 2. 전체 학생 출력 | 3. 끝내기) : ");
		scanf_s("%d", &select);
		//구조체에 이름과 학번, 번호, 주소를 입력받고 이를 바로 txt파일에 쓰기
		if (select==1) {
			printf("이름 : ");
			scanf("%s", s.name);
			getchar();
			printf("학번 : ");
			scanf("%s", s.ID);
			getchar();
			printf("번호 : ");
			scanf("%s", s.phone);
			getchar();
			printf("주소 : ");
			scanf("%s", s.address);
			getchar();

			fopen_s(&fp, fname, "a");
			fprintf(fp, "%s %s %s %s\n", s.name, s.ID, s.phone, s.address);
			fclose(fp);
		}
		else if (select==2){
			//개행문자때문에 마지막 출력이 매끄럽지 않아 몇줄인지 확인
			fopen_s(&fp, fname, "r");
			int line = 0;
			char c;
			while ((c = fgetc(fp)) != EOF){
				if (c == '\n') {
					line++;
				}
			}
			fclose(fp);


			fopen_s(&fp, fname, "r");
			int check = 0;
			if (fp != NULL) {
				char buffer[256];
				while (!feof(fp)){
					check++;
					//버퍼에 한 라인씩 입력 그리고 몇번째 줄인지 확인하면서 마지막줄(개행)은 출력 안함
					if (check > line) {
						break;
					}
					// 한줄씩 읽으면서 문자열 토큰화로 출력(나누는 기준은 공백)
					fgets(buffer, sizeof(buffer), fp);
					char* ptr = strtok(buffer, " ");
					printf("이름: %s\n", ptr);
					ptr = strtok(NULL, " ");
					printf("학번: %s\n", ptr);
					ptr = strtok(NULL, " ");
					printf("번호: %s\n", ptr);
					ptr = strtok(NULL, " ");
					printf("주소: %s\n", ptr);
				}
				fclose(fp);
			}
		}
		else if (select==3) {
			printf("학생정보가 저장됩니다.");
			break;
		}
		else {
			printf("select 입력이 틀렸습니다. 다시 시도해주세요");
		}
	}
}