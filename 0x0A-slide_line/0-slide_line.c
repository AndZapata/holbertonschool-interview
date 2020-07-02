#include "slide_line.h"

/**
 * slide_line - slides an array to sum numbers
 *
 * @line: line of elements to be checked
 * @size: Number of elements in an array
 * @direction: where numbers have to be added
 * Return: 1 if possible, otherwise 0
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == 1)
	{
		for (i = size; i > 0; i--)
		{
			for (j = size - 1; j > 0; j--)
			{
				if (line[i - 1] == 0)
					continue;
				if (i != j && line[i - 1] == line[j - 1])
				{
					line[i - 1] += line[j - 1];
					line[j - 1] = 0;
					break;
				}
			}
		}
		return (1);
	}
	else if (direction == 2)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 1; j < size; j++)
			{
				if (line[i] == 0)
					continue;
				if (j != i && line[i] == line[j])
				{
					line[j] += line[i];
					line[i] = 0;
					break;
				}
			}
		}
		return (1);
	}
	else
		return (0);
}
