#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct IntLinked {
	int num;
	struct IntLinked* link;
}IntLinked;
//���Ḯ��Ʈ ����ü �ۼ�

void print_list(IntLinked* plist);
int get_integer();

int main(void) {
	IntLinked* plist;
	IntLinked* curr = NULL, * prev = NULL;

	int i;
	plist = NULL;

	int list_num = 0;
	printf("������ ����Ʈ�� ���� �Է�: ");
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
		printf("����� ���: %d\n", p->num);
		p = p->link;
	}
}//��� ����Ʈ �Լ�

int get_integer() {
	int num;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &num);
	return num;
}//��� �Է� �Լ�