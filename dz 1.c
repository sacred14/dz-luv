#include <stdio.h>
#include<locale.h>
void main();
{
	setlocale(LC_CTYPE, "RUS");
	puts("             *     ____                         ")
	puts("            **    / /  \                        ")
	puts("          _**    / /    \                       ")
	puts("         /__/|  /  \     \                      ")
	puts("         |  || /    \     \                     ")
	puts("         |  ||/      \    /|                    ")
	puts("         |  |/        \  / |                    ")
	puts("         |  /          \/ /|                    ")
    punt("         *************** | |                    ")
	punt("         *         __  * |/|                    ")
	punt("         *  ___   |  | *   |                    ")
	punt("         *  | |   |__| *   |                    ")
	punt("         *  | |        *  /                     ")
	punt("         ****************/                                ")
	return 1;
}
