#include <locale.h>

#include <stdio.h>

void main()
{
	setlocale(LC_CTYPE, "RUS");
	puts("             *                              ");
	puts("            **                       ");
	puts("          _**                        ");
	puts("         /__/|  ___________                    ");
	puts("         |  || /    \     \ /|                    ");
	puts("         |  ||/      \    / |                    ");
	puts("         |  |/        \  /  |                    ");
	puts("         |  /          \/  /|                    ");
	puts("         *************** | |                    ");
	puts("         *         __  * |/|                    ");
	puts("         *  ___   |  | *   |                    ");
	puts("         *  | |   |__| *   |                    ");
	puts("         *  | |        *  /                     ");
	puts("         ****************/                      ");
	getchar();
	return 1;

}