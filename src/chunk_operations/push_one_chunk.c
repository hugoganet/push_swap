/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_one_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:48:21 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 17:50:59 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks whether a value falls inside a chunk range.
 *
 * @param value The value to check.
 * @param chunk The chunk range (low to high).
 * @return 1 if the value is inside the chunk, 0 otherwise.
 */
int in_chunk(int value, t_chunk chunk)
{
	return (value >= chunk.low && value <= chunk.high);
}

/**
 * @brief Counts how many nodes in A fall inside a chunk range.
 *
 * @param stack The stack to search.
 * @param chunk The chunk range.
 * @return The number of values inside the chunk.
 */
int count_in_chunk(t_node *stack, t_chunk chunk)
{
	int count = 0;

	while (stack)
	{
		if (in_chunk(stack->value, chunk))
			count++;
		stack = stack->next;
	}
	return (count);
}

/**
 * @brief Pushes all elements from stack A to B that fall in the chunk.
 *
 * If a value is in the lower half of the chunk, also rotates B (rb)
 * to keep small values deep and larger values near the top.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param chunk The chunk range to process.
 */
void push_chunk_to_b(t_node **a, t_node **b, t_chunk chunk)
{
	int to_push;
	int value;

	to_push = count_in_chunk(*a, chunk);
	while (to_push > 0)
	{
		value = (*a)->value;
		if (in_chunk(value, chunk))
		{
			pb(a, b);
			if (value < chunk.low + (chunk.high - chunk.low) / 2) // check if is in the lower half of the chunk
				rb(b); // bury smaller values in B
			to_push--;
		}
		else
			ra(a); // bring new value to top
	}
}
