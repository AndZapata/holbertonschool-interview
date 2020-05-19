#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int grid1[3][3]);
void new_print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void sum(int grid1[3][3], int grid2[3][3]);
void toppling(int grid1[3][3]);

#endif /* _SANDPILES_H_ */
