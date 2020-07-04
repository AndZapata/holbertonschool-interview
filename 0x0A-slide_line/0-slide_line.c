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
        if (direction == 1)
                return (slide_left(line, size));
        if (direction == 2)
                return (slide_right(line, size));
        else
                return (0);
}

/**
 * slide_left - slides an array to sum numbers
 *
 * @line: line of elements to be checked
 * @size: Number of elements in an array
 * Return: 1 if success
 */

int slide_left(int *line, size_t size)
{
        int current = 0, next = 0;
        size_t i, idx = 0;

        for (i = 0; i < size; i++)
        {
                if (line[i] != 0 && current == 0)
                        current = line[i];
                else if (current != 0 && line[i] != 0)
                        next = line[i];
                if (current != 0 && next != 0)
                {
                        if (current == next)
                        {
                                line[idx++] = current + next;
                                current = 0;
                                next = 0;
                        }
                        else
                        {
                                line[idx++] = current;
                                current = next;
                                next = 0;
                                if (i == size - 1)
                                        line[idx++] = current;
                        }
                }
                if (current != next && i == size - 1)
                        line[idx++] = current;
        }
        for (i = idx; i < size; i++)
                line[i] = 0;
        return (1);
}

/**
 * slide_right - slides an array to sum numbers
 *
 * @line: line of elements to be checked
 * @size: Number of elements in an array
 * Return: 1 if success
 */

int slide_right(int *line, size_t size)
{
        int current = 0, prev = 0;
        size_t i, idx = size - 1;

        for (i = size - 1; i < size; i--)
        {
                if (line[i] != 0 && current == 0)
                        current = line[i];
                else if (current != 0 && line[i] != 0)
                        prev = line[i];
                if (current != 0 && prev != 0)
                {
                        if (current == prev)
                        {
                                line[idx--] = current + prev;
                                current = 0;
                                prev = 0;
                        }
                        else
                        {
                                line[idx--] = current;
                                current = prev;
                                prev = 0;
                                if (i == 0)
                                        line[idx--] = current;
                        }
                }
                else if (current != prev && i == 0)
                        line[idx--] = current;
        }
        for (i = 0; i < idx + 1; i++)
                line[i] = 0;
        return (1);
}
