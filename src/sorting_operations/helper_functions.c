/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:21:31 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 14:31:05 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find the minimun int of a stack
 * 
 * @param stack The stack structure to search from
 */
int find_min_value(t_node *stack)
{
	int min;

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
 * @brief Find a specific int in a stack
 * 
 * @param stack The stack to search the target from
 * @param target The int to look for
 */
int find_position(t_node *stack, int target)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == target)
			break;
		pos++;
		stack = stack->next;
	}
	return (pos);
}
