/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:11:23 by hganet            #+#    #+#             */
/*   Updated: 2025/03/25 16:32:13 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Helper function for rotate (rr) 
 */
static void ft_rotate(t_node **stack)
{
	t_node *first;
	t_node *last;

	first = *stack; // 1rst node adress
	*stack = first->next; // moves the head to the 2nd node
	last = *stack; 
	while (last->next) // go to the last node
		last = last->next;
	last->next = first; // 1rst node takes the last place
	first->next = NULL; // first node is remove
}

/** 
 * @brief Combined rotate: performs ra and rb 
 */
void rr(t_node **stack_a, t_node **stack_b)
{
	int r;

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
static void ft_revrotate(t_node **stack)
{
	t_node *prev;
	t_node *last;

	prev = NULL;
	last = *stack; // 1rst node
	while (last->next) // go to last node
	{
		prev = last; // prev become current
		last = last->next; // last become next
	}
	if (prev) 
		prev->next = NULL; // disconnect the last from the 2nd to last node
	last->next = *stack; // last node point to the head
	*stack = last; // moves last to be the head
}

/**
 * @brief reverse rotate: performs rra and rrb 
 */
void rrr(t_node **stack_a, t_node **stack_b)
{
	int r;

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
