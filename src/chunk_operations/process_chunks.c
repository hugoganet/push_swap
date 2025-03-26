/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:55:31 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 14:59:15 by hganet           ###   ########.fr       */
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
 * @brief Pushes all elements from A to B that fall within the given chunk.
 *
 * If the current value in A is part of this chunk, push it to B.
 * If it's small, bury it using rb().
 * And if the next value in A isn't interesting, combine the A + B rotations using rr()
 *
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 * @param chunk The current chunk to push from A to B
 */
void push_chunk_to_b(t_node **a, t_node **b, t_chunk chunk)
{
	int to_push;
	int value;
	int rotate_b;

	to_push = count_in_chunk(*a, chunk);
	while (to_push > 0) // loop on the number of node found in stack_a that fall into current chunk
	{
		value = (*a)->value; // store the value of the head node
		if (in_chunk(value, chunk)) // if the value fall into the min/max of the chunk
		{
			pb(a, b); // push the head node to stack_b
			rotate_b = value < chunk.low + (chunk.high - chunk.low) / 2; // boolean expression. Evaluate to true (1) or false (0)
			if (rotate_b && (*a) && !in_chunk((*a)->value, chunk))		 // check if the current head value is in check (because we did pb, the head value changed)
				rr(a, b); // rotate both: A (preparing for next) and B (bury small)
			else if (rotate_b) // rr() case didn't apply (e.g. next A value *is* in chunk or A is empty)
				rb(b);
			to_push--;
		}
		else
			ra(a); // If the current value in A isn't part of the currrent chuck, rotate it in A (goes to the tail)
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
		if (pos <= size / 2) // 
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
