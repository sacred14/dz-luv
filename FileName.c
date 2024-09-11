#include <locale.h>

#include <stdio.h>

void main()
{
	setlocale(LC_CTYPE, "RUS");
	puts("             *     ____                         ");
	puts("            **    /    \                        ");
	puts("          _**    /\     \                       ");
	puts("         /__/|  /  \     \                      ");
	puts("         |  || /    \     \                     ");
	puts("         |  ||/      \    /|                    ");
	puts("         |  |/        \  / |                    ");
	puts("         |  /          \/ /|                    ");
	puts("         *************** | |                    ");
	puts("         *         __  * |/|                    ");
	puts("         *  ___   |  | *   |                    ");
	puts("         *  | |   |__| *   |                    ");
	puts("         *  | |        *  /                     ");
	puts("         ****************/                      ");
	getchar();
	return 1;

}