#include "predator.h"
#include "prey.h"
#include "functions.h"

int main()
{
	int r, c, cycle, lifeCycle, lifeCycleCount, lifeCycleRandom, i, j, **matrix, field, pred, prey;
	double predProportion, preyProportion, kill0, kill1; // dying of predators
	struct timespec timesp; // get nanoseconds for random number

	// get values
	printf("rows: ");
	scanf("%d", &r);
	printf("columns: ");
	scanf("%d", &c);
	printf("prey cycles: ");
	scanf("%d", &lifeCycle);

	// create matrix
	if ((matrix = (int **)malloc(r*sizeof(int *))) == NULL)
	{
		printf("ERROR malloc\n");
	}
	for (i=0; i<r; i++)
	{
		if ((*(matrix+i) = (int *)malloc(c*sizeof(int))) == NULL)
		{
			printf("ERROR malloc\n");
		}
	}

	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
		{
			matrix[i][j] = 8;
		}
	}

	clock_gettime(CLOCK_REALTIME, &timesp);
	matrix[timesp.tv_nsec%r][timesp.tv_nsec%c] = 1; // predator random position

	lifeCycleCount = lifeCycle; // lifecyclecount for prey
	cycle = 0; // cycles of algorithm
	pred = 0; // predator count
	prey = 0; // prey count
	kill1 = 0; // dying of predators

	// general algorithm
	for (;;)
	{
		lifeCycleCount++;
		cycle++;
		system("clear");
		printf("predator: %d\n", pred);
		printf("prey: %d\n", prey);
		printf("cycle: %d\n",cycle);
		pred = 0;
		prey = 0;
		print(matrix,r,c); // print
		usleep(100000); // wait
		for (i=0; i<r; i++) // go through matrix
		{
			for (j=0; j<c; j++)
			{
				if (matrix[i][j] == 1) // if predator
				{
					field = predsearch(matrix,i,j,r,c); // look around
					predmove(field,matrix,i,j,r,c); // move
				}
				else if (matrix[i][j] == 0)
				{
					field = preysearch(matrix,i,j,r,c);
					preymove(field,matrix,i,j,r,c);
				}
			}
		}
		refresh(matrix,r,c); // refresh matrix

		// create new prey
		if (lifeCycleCount >= lifeCycle)
		{
			clock_gettime(CLOCK_REALTIME, &timesp);
			lifeCycleRandom = timesp.tv_nsec%4;
			if (lifeCycleRandom == 0)
				matrix[0][0] = 0;
			else if (lifeCycleRandom == 1)
				matrix[0][c-1] = 0;
			else if (lifeCycleRandom == 2)
				matrix[r-1][0] = 0;
			else if (lifeCycleRandom == 3)
				matrix[r-1][c-1] = 0;
			lifeCycleCount = 0;
		}

		for (i=0; i<r; i++) // count predators and preys
		{
			for (j=0; j<c; j++)
			{
				if (matrix[i][j] == 1)
				{
					pred++;
				}
				else if (matrix[i][j] == 0)
				{
					prey++;
				}
			}
		}

		if (prey == 0) // if no more prey
		{
			// uncomment for dying of predators
			/*predProportion = pred;
			kill0 = predProportion*0.5;
			for (i=0; i<r; i++) 
			{
				for (j=0; j<c; j++)
				{
					if ((kill0 > 0) && (matrix[i][j] == 1))
					{
						matrix[i][j] = 8;
						kill0--;
					}
				}
			}*/
			break;
		}


		predProportion = pred;
		preyProportion = prey;
		/*if((preyProportion/predProportion < 0.2) || kill1 > 0)
		{
			
			if (kill1 <= 0)
			{
				kill1 = pred*1.3;
			}
			kill1--;
			kill0 = 1;
			for (i=0; i<r; i++) 
			{
				for (j=0; j<c; j++)
				{
					if ((kill0 > 0) && (matrix[i][j] == 1))
					{
						matrix[i][j] = 8;
						kill0--;
					}
				}
			}
		}*/

		if (pred == 0)
		{
			clock_gettime(CLOCK_REALTIME, &timesp);
			matrix[timesp.tv_nsec%r][timesp.tv_nsec%c] = 1;
		}
	}

	system("clear");
	printf("predator: %d\n", pred);
	printf("prey: %d\n", prey);
	printf("cycle: %d\n",cycle);
	print(matrix,r,c);

	return 0;
}

