/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:55:31 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 17:19:17 by hganet           ###   ########.fr       */
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
int	in_chunk(int value, t_chunk chunk)
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
int	count_in_chunk(t_node *stack, t_chunk chunk)
{
	int	count;

	count = 0;
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
void	push_chunk_to_b(t_node **a, t_node **b, t_chunk chunk)
{
	int	to_push;
	int	value;
	int	rotate_b;

	to_push = count_in_chunk(*a, chunk);
	while (to_push > 0)
	{
		value = (*a)->value;
		if (in_chunk(value, chunk))
		{
			pb(a, b);
			rotate_b = value < chunk.low + (chunk.high - chunk.low) / 2;
			if (rotate_b && (*a) && !in_chunk((*a)->value, chunk))
				rr(a, b);
			else if (rotate_b)
				rb(b);
			to_push--;
		}
		else
			ra(a);
	}
}

/**
 * @brief Loops through all chunks and pushes each one from A to B.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param chunks Array of t_chunk ranges.
 * @param chunk_count Number of chunks in the array.
 */
void	process_chunks(t_node **a, t_node **b, t_chunk *chunks, int chunk_count)
{
	int	i;

	i = 0;
	while (i < chunk_count)
	{
		push_chunk_to_b(a, b, chunks[i]);
		i++;
	}
}

/**
 * @brief Pushes all elements back from stack B to A in descending order.
 *
 * Finds the largest value in B, rotates B to bring it to top,
 * then pushes it to A. Repeats until B is empty.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	push_back_to_a(t_node **a, t_node **b)
{
	int	pos;
	int	size;
	int	max;

	while (*b)
	{
		max = find_max_value(*b);
		pos = find_position(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}
