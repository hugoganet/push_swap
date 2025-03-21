/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:17 by hganet            #+#    #+#             */
/*   Updated: 2025/03/21 17:55:11 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/**
 * @brief Creates a new linked list node with the given value.
 *
 * Allocates memory for a t_node and initializes its value
 * and next pointer.
 *
 * @param value The integer value to store.
 * @return A pointer to the newly created node, or NULL on failure.
 */
t_node *new_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/**
 * @brief Adds a node to the end of the linked list.
 *
 * If the list is empty, sets the new node as the head.
 * Otherwise, traverses to the last node and appends it.
 *
 * @param stack A pointer to the head of the stack (linked list).
 * @param new The node to add.
 */
void add_back(t_node **stack, t_node *new)
{
	t_node *temp;

	// if list is empty, new node is the first one
	if (!*stack)
	{
		*stack = new;
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

/**
 * @brief Frees all nodes in a linked list.
 *
 * Traverses the stack and frees each node one by one.
 *
 * @param stack The head of the stack (linked list).
 */
void free_stack(t_node *stack)
{
	t_node *temp;

	while (stack)
	{
		temp = stack->next; // Keep the pointer to the next node
		free(stack); // free the node
		stack = temp; // give the current node the value of the previous stack->next pointer
	}
}
