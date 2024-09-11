#include <locale.h>

#include <stdio.h>
void date()
{
	puts("   __      __      __   __ ");
	puts("/|  /  /|   _|    |  | |__ ");
	puts(" |  |   |  |__    |__| |__|");
	getchar();
	return 0;
}
void figures()
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
void main()
{
	setlocale(LC_CTYPE, "RUS");
	
	date();
	figures();
}
