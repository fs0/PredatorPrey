#ifndef _FUNCS_
#define _FUNCS_

#include <unistd.h>
#include <stdio.h>

// linuxgazette.net Pradeep Padala
#define RESET		0
#define BRIGHT 		1

// linuxgazette.net Pradeep Padala
#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void refresh(int **matrix, int r, int c);
void print(int **matrix, int r, int c);
void textcolor(int attr, int fg, int bg);

#endif
