#include "menger.h"

/**
 * menger - function to print a menger sponge
 * @level: Level of the menger sponge to be drawn
 *
 */
void menger(int level)
{
	int i, j, pow_res, div_i, div_j;
	char c;

	pow_res = pow(3, level);

	for (i = 0; i < pow_res; i++)
	{
		for (j = 0; j < pow_res; j++)
		{
			c = '#';
			div_i = i;
			div_j = j;
			while (div_i > 0)
			{
				if (div_i % 3 == 1 && div_j % 3 == 1)
					c = ' ';
				div_i /= 3;
				div_j /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
