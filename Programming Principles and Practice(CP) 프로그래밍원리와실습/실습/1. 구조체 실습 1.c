#include <stdio.h>
#include <math.h>
# define _CRT_SECURE_NO_WARNINGS

struct point {
	int x, y;
};

struct rect {
	struct point p1, p2;
};

int main() {
	struct rect r;
	int round, area, height, width;

	printf("���� �� ���� ��ǥ �Է�(x,y) : ");
	scanf_s("%d %d", &r.p1.x, &r.p1.y);

	printf("������ �Ʒ� ���� ��ǥ �Է�(x,y) : ");
	scanf_s("%d %d", &r.p2.x, &r.p2.y);

	height = r.p1.y - r.p2.y;
	width = r.p1.x - r.p1.x;
	round = 2 * (height + width);
	area = height * width;

	printf("�ѷ� : %d, ���� : %d\n", round, area);

	return 0;
}