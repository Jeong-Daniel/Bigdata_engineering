#include <stdio.h>
#include <math.h>

int main() {
	int num;
	int i, k;
	printf("정수 값을 하나 입력해주세요 : ");
	scanf("%d", &num);
	printf("정수 i와 k입력하기(스페이스바로 구분) : ");
	scanf("%d%d", &i, &k);

	//비트가 몇자리수인지 확인
	int check = 0;
	int j = 0;
	for (j;;j++) {
		int temp_1 = pow(2, j);
		int temp_2 = pow(2, j + 1);
		if ((temp_1 <= num) && (num < temp_2)) {
			check = j + 1;
			break;
		}
	}
	//printf("자리수는 %d \n",j+1);
	//범위를 벗어나는 i,k 예외처리하기
	if ((i > check) || (k > check)) {
		printf("i 또는 k값이 비트 범위를 벗어났습니다");
		return 0;
	}

	//첫번재 조건 i번째 비트값이 얼마인지 출력하기
	int result = num >> (i - 1) & 1;
	printf("%d번째 비트 값은 : %d\n", i, result);

	//두번째 조건 k번째 비트값을 무조건 1로 변경해서 출력하기
	int check_2 = (num >> (k - 1) & 1);
	if (check_2 == 1) {
		printf("%d번째 비트를 1로 변환했을때 : %d", k, num);
		return 0;
	}
	else {
		num += 1 << (k - 1);
		printf("%d번째 비트를 1로 변환했을때 : %d", k, num);
		return 0;
	}
}