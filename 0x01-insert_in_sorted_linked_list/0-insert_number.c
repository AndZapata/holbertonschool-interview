#include "lists.h"

/**
 * insert_node - insert a new node in a sorted linked list
 * @head: pointer to head of list
 * @number: data to add in the linked list
 * Return: New node
*/

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *current, *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;

	if (*head == NULL || (*head)->n >= new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next && current->next->n < new_node->n)
		current = current->next;
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
