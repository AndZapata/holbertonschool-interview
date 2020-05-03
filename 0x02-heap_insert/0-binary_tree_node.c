#include "binary_trees.h"

/**
 * binary_tree_node - function to create a new binary tree node.
 *
 * @parent: pointer to the parent node of the node to create
 * @value: is the value to insert in the new node.
 * Return: newNode or NULL if fail
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode)
	{
		newNode->n = value;
		newNode->parent = parent;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	return (newNode);
}
