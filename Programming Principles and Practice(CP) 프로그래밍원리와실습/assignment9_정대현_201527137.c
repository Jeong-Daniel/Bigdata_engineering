#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct IntLinked {
	int num;
	struct IntLinked* link;
}IntLinked;
//연결리스트 구조체 작성

void print_list(IntLinked* plist);
int get_integer();

int main(void) {
	IntLinked* plist;
	IntLinked* curr = NULL, * prev = NULL;

	int i;
	plist = NULL;

	int list_num = 0;
	printf("생성할 리스트의 개수 입력: ");
	scanf("%d", &list_num);

	for(int j=0;j<list_num;j++){
		i = get_integer();
		curr = (IntLinked*)malloc(sizeof(IntLinked));
		curr->num = i;
		curr->link = NULL;
		if (prev == NULL)
			plist = curr;
		else
			prev->link = curr;
		prev = curr;
	}
	print_list(plist);
	return 0;
}

void print_list(IntLinked* plist) {
	IntLinked* p;
	p = plist;
	while (p) {
		printf("저장된 노드: %d\n", p->num);
		p = p->link;
	}
}//출력 리스트 함수

int get_integer() {
	int num;
	printf("정수를 입력하세요: ");
	scanf("%d", &num);
	return num;
}//노드 입력 함수