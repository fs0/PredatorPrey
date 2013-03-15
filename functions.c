#include "functions.h"

void refresh(int **matrix, int r, int c)
{
	int i, j;

	// set 1s and 0s 
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
		{
			if (matrix[i][j] == 2)
			{
				matrix[i][j] = 1;
			}
			else if (matrix[i][j] == 3)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void print(int **matrix, int r, int c)
{
	int i, j;

	// print top-line
	for (i=0; i<c*2; i++)
	{
		printf("-");
	}
	printf("-\n");

	// print matrix
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
		{
			if (matrix[i][j] == 8)
			{
				printf("  ");
			}
			else if (matrix[i][j] == 1)
			{
				// linuxgazette.net Pradeep Padala
				textcolor(BRIGHT,RED,BLACK);
				printf("+ ");
				// linuxgazette.net Pradeep Padala
				textcolor(BRIGHT,WHITE,BLACK);
			}
			else
			{
				// linuxgazette.net Pradeep Padala
				textcolor(BRIGHT,BLUE,BLACK);
				printf("# ");
				// linuxgazette.net Pradeep Padala
				textcolor(BRIGHT,WHITE,BLACK);
			}
		}
		printf("|\n");
	}

	// print bottom-line
	for (i=0; i<c*2; i++)
	{
		printf("-");
	}
	printf("-\n");
}

// linuxgazette.net Pradeep Padala
void textcolor(int attr, int fg, int bg)
{	char command[13];

	// Command is the control command to the terminal
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

