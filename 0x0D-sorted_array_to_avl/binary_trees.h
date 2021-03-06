#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
void binary_tree_print(const binary_tree_t *);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *node_avl_insertion(int *array, size_t first, size_t last, avl_t *root);
avl_t *new_node(avl_t *root, size_t data);

#endif /* _BINARY_TREES_H_ */
