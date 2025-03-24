/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:55:31 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 18:08:17 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Loops through all chunks and pushes each one from A to B.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param chunks Array of t_chunk ranges.
 * @param chunk_count Number of chunks in the array.
 */
void process_chunks(t_node **a, t_node **b, t_chunk *chunks, int chunk_count)
{
	int i;

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
void push_back_to_a(t_node **a, t_node **b)
{
	int pos;
	int size;
	int max;

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
