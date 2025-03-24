/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:21:55 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 14:30:44 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Frees a NULL-terminated array of strings.
 *
 * @param args The array of strings to free.
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
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
		free(stack);		// free the node
		stack = temp;		// give the current node the value of the previous stack->next pointer
	}
}