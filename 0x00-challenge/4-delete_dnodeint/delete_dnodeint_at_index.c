#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}

	saved_head = *head;
	p = 0;

	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}

	if (index == 0)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;

		// Check if the new head is not NULL
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		tmp = *head;

		// Traverse to the node to be deleted
		for (p = 0; p < index && tmp != NULL; p++)
		{
			tmp = tmp->next;
		}

		if (tmp != NULL)
		{
			// Update the next pointer of the previous node
			tmp->prev->next = tmp->next;

			// Update the previous pointer of the next node
			if (tmp->next != NULL)
			{
				tmp->next->prev = tmp->prev;
			}

			free(tmp);
		}
		*head = saved_head;
	}

	return (1);
}

