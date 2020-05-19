#include "sandpiles.h"

/**
 * sandpiles_sum - Function to call sum for sandpiles
 * @grid1: First array of arrays to be sum
 * @grid2: Second array of arrays to be sum
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);
}

/**
 * new_print_grid - Function to print a grid
 * @grid1: First array of arrays to be sum
 */

void new_print_grid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sum - Function to sum sandpiles
 * @grid1: First array of arrays to be sum
 * @grid2: Second array of arrays to be sum
 */

void sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (check(grid1))
	{
		printf("=\n");
		new_print_grid(grid1);
		toppling(grid1);
	}

}

/**
 * check - Function to check the status of the sandpile
 * @grid1: First array of arrays to be sum
 * Return: 1 if the sandpile has integers greaters than 3, 0 if not
 */

int check(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * toppling - Function to create a new grid depending on the status
 * of a previous grid then call function sum
 * @grid1: First array of arrays to be sum
 */

void toppling(int grid1[3][3])
{
	int i, j, tmp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tmp[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				tmp[i][j] -= 4;
				if (i + 1 < 3)
					tmp[i + 1][j] += 1;
				if (i - 1 >= 0)
					tmp[i - 1][j] += 1;
				if (j + 1 < 3)
					tmp[i][j + 1] += 1;
				if (j - 1 >= 0)
					tmp[i][j - 1] += 1;
			}
		}
	}
	sum(grid1, tmp);
}
