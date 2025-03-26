/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 15:19:54 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int 	size;
	t_chunk *chunks;
	int		chunk_count;

	if (ac < 2)
		return (0);

	// [1] Parse the arguments and create stack_a. Initialize stack_b
	stack_a = parse_args(ac, av);
	stack_b = NULL;
	/* [2] Converts each value in the stack to its sorted index.
	  	   This is used to simplify the sorting logic for large stacks,
	       allowing algorithms to work with normalized values from 0 to N - 1
		   instead of unpredictable input numbers.*/
	normalize_stack(stack_a);
	// [3] Generate the chunks
	size = stack_size(stack_a);
	chunk_count = get_chunk_count(size);
	chunks = generate_chunks(size, chunk_count);
	// [4] Process chunks from A to B and B to A
	process_chunks(&stack_a, &stack_b, chunks, chunk_count);
	push_back_to_a(&stack_a, &stack_b);
	// [5] Free every memory allocation
	free(chunks);
	free_stack(stack_a);
	return (0);
}
