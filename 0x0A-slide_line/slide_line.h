#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

#endif /* SLIDE_LINE */
