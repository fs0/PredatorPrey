#include "prey.h"

int preysearch(int **matrix, int row, int column, int r, int c)
{
	// r and c are the matrix dimensions

	int rmin, cmin, rmax, cmax, i, j, rand;
	struct timespec timesp; // nanoseconds for random number

	// distance sight
	rmin = row - r*0.1;
	if (rmin < 0)
		rmin = 0;

	cmin = column - c*0.1;
	if (cmin < 0)
		cmin = 0;

	rmax = row + r*0.1;
	if (rmax > r-1)
		rmax = r-1;

	cmax = column + c*0.1;
	if (cmax > c-1)
		cmax = c-1;
	
	for (i=rmin; i<rmax; i++)
	{
		for (j=cmin; j<cmax; j++)
		{
			if ((matrix[i][j] == 1) || (matrix[i][j] == 2))
			{
				if (i <= row)
				{
					if (j <= column)
						return 3;
					else
						return 2;
				}
				else
				{
					if (j < column)
						return 0;
					else
						return 1;
				}
			}
		}
	}

	clock_gettime(CLOCK_REALTIME, &timesp);
	rand = timesp.tv_nsec%4; // 1 out of 4 times go to other predators
	if (rand == 0)
	{
		for (i=rmin; i<rmax; i++)
		{
			for (j=cmin; j<cmax; j++)
			{
				if (((matrix[i][j] == 0) || (matrix[i][j] == 3)) && ( (i!=row) && (j!=column)))
				{
					if (i < row)
					{
						if (j <= column)
							return 1;
						else
							return 0;
					}
					else
					{
						if (j < column)
							return 2;
						else
							return 3;
					}
				}
			}
		}
	}
	clock_gettime(CLOCK_REALTIME, &timesp);
	return timesp.tv_nsec%4;
}

void preymove(int field, int **matrix, int row, int column, int r, int c)
{
	int rorigin, corigin, x, b;
	struct timespec timesp; // nanoseconds for random number

	clock_gettime(CLOCK_REALTIME, &timesp);
	x = timesp.tv_nsec%3;
	rorigin = row;
	corigin = column;
	b = 0; // for break if can't move

	if ((row < r*0.3) && (column < c*0.3)) // left top corner
	{
		for (;;)
		{
			if (x == 0)
			{
				row++;
			}
			else if (x == 1)
			{
				row++;
				column++;
			}
			else if (x == 2)
			{
				column++;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
	else if ((row < r*0.3) && (column > (c-c*0.3))) // right top corner
	{
		for (;;)
		{
			if (x == 0)
			{
				row++;
			}
			else if (x == 1)
			{
				row++;
				column--;
			}
			else if (x == 2)
			{
				column--;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
	else if ((row > (r-r*0.3)) && (column < c*0.3)) // left bottom corner
	{
		for (;;)
		{
			if (x == 0)
			{
				row--;
			}
			else if (x == 1)
			{
				row--;
				column++;
			}
			else if (x == 2)
			{
				column++;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
	else if ((row > (r-r*0.3)) && (column > (c-c*0.3))) // right bottom corner
	{
		for (;;)
		{
			if (x == 0)
			{
				row--;
			}
			else if (x == 1)
			{
				row--;
				column--;
			}
			else if (x == 2)
			{
				column--;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}

	else if (field == 0)
	{
		for (;;)
		{
			if (x == 0)
			{
				row--;
			}
			else if (x == 1)
			{
				row--;
				column++;
			}
			else if (x == 2)
			{
				column++;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
	else if (field == 1)
	{
		for (;;)
		{
			if (x == 0)
			{
				row--;
			}
			else if (x == 1)
			{
				row--;
				column--;
			}
			else if (x == 2)
			{
				column--;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
	else if (field == 2)
	{	
		for (;;)
		{
			if (x == 0)
			{
				row++;
			}
			else if (x == 1)
			{
				row++;
				column--;
			}
			else if (x == 2)
			{
				column--;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
	else if (field == 3)
	{
		for (;;)
		{
			if (x == 0)
			{
				row++;
			}
			else if (x == 1)
			{
				row++;
				column++;
			}
			else if (x == 2)
			{
				column++;
			}

			if ((row < 0) || (column < 0) || (row >= r) || (column >= c))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 2) || (matrix[row][column] == 1))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else if ((matrix[row][column] == 3) || (matrix[row][column] == 0))
			{
				if (b > 10)
				{
					matrix[rorigin][corigin] = 3;
					break;
				}
			}
			else
			{
				matrix[rorigin][corigin] = 8;
				matrix[row][column] = 3;
				break;
			}
			b++;
		}
	}
}
