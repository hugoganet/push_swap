/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:11:23 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 15:49:50 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Helper function for rotate (rr) 
 */
static void	ft_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

/** 
 * @brief Combined rotate: performs ra and rb 
 */
void	rr(t_node **stack_a, t_node **stack_b)
{
	int	r;

	r = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		ft_rotate(stack_a);
		r = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		ft_rotate(stack_b);
		r = 1;
	}
	if (r)
		write(1, "rr\n", 3);
}

/** 
 * @brief Helper function for reverse rotate (rrr) 
 */
static void	ft_revrotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/**
 * @brief reverse rotate: performs rra and rrb 
 */
void	rrr(t_node **stack_a, t_node **stack_b)
{
	int	r;

	r = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		ft_revrotate(stack_a);
		r = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		ft_revrotate(stack_b);
		r = 1;
	}
	if (r)
		write(1, "rrr\n", 4);
}
