#include "search.h"

/**
 * linear_skip - Function to check a value in a linked list
 * @list: Pointer to the head of the list
 * @value: Value to be search
 *
 * Return: Pointer to the value or null if fail
 **/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *next, *prev;

	if (!list)
		return (NULL);
	next = list->express;
	prev = list;
	while (next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       next->index, next->n);
		if (next->n >= value || !next->express)
		{
			if (!next->express && next->n < value)
			{
				prev = next;
				while (next->next)
					next = next->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, next->index);
			while (prev)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				       prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				if (prev->n > value)
					return (NULL);
				prev = prev->next;
			}
			break;
		}
		prev = next;
		next = next->express;
	}
	return (NULL);
}
