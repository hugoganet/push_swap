/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:27:40 by hganet            #+#    #+#             */
/*   Updated: 2025/03/27 12:18:31 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Decides how to sort the stack based on its size.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int		size;
	int		chunk_count;
	t_chunk	*chunks;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		chunk_count = get_chunk_count(size);
		chunks = generate_chunks(size, chunk_count);
		process_chunks(stack_a, stack_b, chunks, chunk_count);
		push_back_to_a(stack_a, stack_b);
		free(chunks);
	}
}
