#include <stdio.h>
#include <locale.h>



int task3()
{
	float n = 3, L = 313;
	int k = 4, m = 2;
	printf("%-s\n %8.0f\n %8.0f\n %12s\n %-122s %+08.02f\n ", "Дано:", n, L, "__", "Ответ:", n / L);

}
int lab()
{
	int num;
	setlocale(LC_CTYPE, "RUS");
	puts("введите длину\n");
	scanf("%d", &num);
	printf("введена длина  %d\n", num);

	int num2;
	puts("введите ширину\n");
	scanf("%d", &num2);
	printf("введена ширина  %d\n", num2);

	printf("перимент прямоугольника равен %d\n", num * num2);
	printf("площадь прямоугольника равна %d\n", (num + num2) * 2);
}

int main()
{
	setlocale(LC_CTYPE, "RUS");
	task3();
	lab();
}