#include <stdio.h>
#include <locale.h>



int task3()
{
	float n = 3, L = 313;
	int k = 4, m = 2;
	printf("%-s\n %8.0f\n %8.0f\n %12s\n %-122s %+08.02f\n ", "����:", n, L, "__", "�����:", n / L);

}
int lab()
{
	int num;
	setlocale(LC_CTYPE, "RUS");
	puts("������� �����\n");
	scanf("%d", &num);
	printf("������� �����  %d\n", num);

	int num2;
	puts("������� ������\n");
	scanf("%d", &num2);
	printf("������� ������  %d\n", num2);

	printf("�������� �������������� ����� %d\n", num * num2);
	printf("������� �������������� ����� %d\n", (num + num2) * 2);
}

int main()
{
	setlocale(LC_CTYPE, "RUS");
	task3();
	lab();
}