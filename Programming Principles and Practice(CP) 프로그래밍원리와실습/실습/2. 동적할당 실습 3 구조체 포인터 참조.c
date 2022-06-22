#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

struct point{
	int x, y;
};

int main() {
	int angleNum;
	struct point* pnt;
	int temp1, temp2;
	float area;
	
	while (1) {
		temp1 = 0;
		temp2 = 0;
		printf("몇각형? (종료 -1) : ");
		scanf("%d", &angleNum);
		
		if (angleNum == -1)
			break;

		pnt = (struct point*)malloc(sizeof(struct point) * angleNum);
		for (int i = 0; i < angleNum; i++) {
			printf("%d 번째 점의 좌표 (x,y) : ", i + 1);
			scanf("%d %d", &(pnt + i)->x, &(pnt + i)->y);
		}

		for (int i = 0; i < angleNum - 1; i++) {
			temp1 += (pnt + i)->x * (pnt + i + 1)->y;
			temp2 += (pnt + i + 1)->x * (pnt + i)->y;
		}
		temp1 += (pnt + angleNum - 1)->x * pnt->y;
		temp2 += pnt->x * (pnt + angleNum - 1)->y;
		area = abs(temp1 - temp2)/2;
		printf("넓이 : %f\n", area);
	}

	return 0;
}