/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:21:31 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 15:51:12 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find the minimun int of a stack
 * 
 * @param stack The stack structure to search from
 */
int	find_min_value(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Returns the largest value in a stack.
 *
 * @param stack The stack to search.
 * @return The maximum integer value found.
 */
int	find_max_value(t_node *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/**
 * @brief Find a specific int in a stack
 * 
 * @param stack The stack to search the target from
 * @param target The int to look for
 */
int	find_position(t_node *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == target)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

/**
 * @brief Get the size of a stack
 *
 * @param stack The stack to get the size of
 */
int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
