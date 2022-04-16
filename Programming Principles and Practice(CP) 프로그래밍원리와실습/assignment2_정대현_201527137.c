#include <stdio.h>
#define boss 9200
#define employee 6300
#define boss_tax 0.88
#define employee_tax 0.91

int main() {
	int time_1, time_2;
	char name_1[3], name_2[3];
	printf("부장의 이름을 입력하세요 : ");
	scanf("%s", &name_1);
	fflush(stdin);
	printf("부장의 근무시간을 입력하세요 : ");
	scanf("%d", &time_1);
	fflush(stdin);
	printf("\n");
	printf("사원의 이름을 입력하세요 : ");
	scanf("%s", &name_2);
	fflush(stdin);
	printf("사원의 근무시간을 입력하세요 : ");
	scanf("%d", &time_2);
	fflush(stdin);

	float salary_1, salary_2, total;
	salary_1 = time_1 * boss * boss_tax;
	salary_2 = time_2 * employee * employee_tax;
	total = salary_1 + salary_2;

	printf("===================================\n");
	printf("%s 부장님의 월급은 %1.f 원 입니다.\n", name_1, salary_1);
	printf("%s 사원님의 월급은 %1.f 원 입니다.\n", name_2, salary_2);
	printf("===================================\n");
	printf("회사가 지불할 총 월급은 %1.f 원 입니다.\n", total);

	return 0;
}