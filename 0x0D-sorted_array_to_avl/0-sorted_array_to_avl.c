#include "binary_trees.h"

/**
 * sorted_array_to_avl - Function to sort an array in a AVL tree
 *
 * @array: The array to be printed
 * @size: Size of the array
 * Return: node insertion or null if fail
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (node_avl_insertion(array, 0, size - 1, NULL));
}

/**
 * node_avl_insertion - Function to insert a node a AVL tree
 *
 * @array: The array to be printed
 * @first: first element of the array index
 * @last: last element of the array index
 * @root: root of the tree
 * Return: node insertion or null if fail
 */
avl_t *node_avl_insertion(int *array, size_t first, size_t last, avl_t *root)
{
	size_t half;
	avl_t *newNode;

	if (first > last)
		return (NULL);

	half = (first + last) / 2;
	newNode = new_node(root, array[half]);

	if (!newNode)
		return (NULL);
	if (half != first)
		newNode->left = node_avl_insertion(array, first,
						   half - 1, newNode);
	if (half != last)
		newNode->right = node_avl_insertion(array, half + 1,
						    last, newNode);
	return (newNode);
}

/**
 * new_node - Function to create a new node in a AVL tree
 *
 * @root: parent root of the tree
 * @data: data to be inserted in the new node
 * Return: node insertion or null if fail
 */
avl_t *new_node(avl_t *root, size_t data)
{
	avl_t *newNode;

	newNode = malloc(sizeof(avl_t));
	if (!newNode)
		return (NULL);
	newNode->n = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = root;

	return (newNode);
}
