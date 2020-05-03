#include "binary_trees.h"

/**
 * heap_size - function to take the size in a tree.
 * @root: The pointer to the root of the tree.
 * Return: The size of the tree.
 */
int heap_size(binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * helper_insertion - function to insert in correct order.
 * @root: The pointer to the root of the tree.
 * @val: The value of the node to insert.
 * @idx: The index of the current node.
 * @size: The new position to insert the new node.
 * Return: The pointer to the inserted node.
 */
heap_t *helper_insertion(binary_tree_t *root, int val, int idx, int size)
{
	heap_t *new_node;

	if (root == NULL)
		return (NULL);
	if (idx + 1 == size / 2)
	{
		if (size % 2 == 1)
		{
			root->right = binary_tree_node(root, val);
			return (root->right);
		}
		else
		{
			root->left = binary_tree_node(root, val);
			return (root->left);
		}
	}
	new_node = helper_insertion(root->left, val, 2 * idx + 1, size);
	if (new_node)
		return (new_node);
	return (helper_insertion(root->right, val, 2 * idx + 2, size));
}

/**
 * heap_insert - Inserts a new value in a Max Binary Heap.
 * @root: The pointer to the root of the tree.
 * @value: The value of the node to insert.
 * Return: The pointer to the inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new_node = helper_insertion(*root, value, 0, heap_size(*root) + 1);
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}
