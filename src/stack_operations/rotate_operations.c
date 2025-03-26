/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:45:48 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 15:48:10 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/**
 * @brief Rotates stack A upwards: the first element becomes the last.
 *
 * If the stack has less than 2 elements, does nothing.
 *
 * @param stack A pointer to the head of stack A.
 */
void	ra(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

/**
 * @brief Reverse rotates stack A: the last element becomes the first.
 *
 * If the stack has less than 2 elements, does nothing.
 *
 * @param stack A pointer to the head of stack A.
 */
void	rra(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rra\n", 4);
}

/**
 * @brief Rotates stack B upwards: the first element becomes the last.
 *
 * @param stack Pointer to the top of stack B.
 */
void	rb(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

/**
 * @brief Reverse rotates stack B: the last element becomes the first.
 *
 * @param stack Pointer to the top of stack B.
 */
void	rrb(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rrb\n", 4);
}
