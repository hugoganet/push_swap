/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 17:02:29 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	t_chunk	*chunks;
	int		chunk_count;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	stack_b = NULL;
	normalize_stack(stack_a);
	size = stack_size(stack_a);
	chunk_count = get_chunk_count(size);
	chunks = generate_chunks(size, chunk_count);
	process_chunks(&stack_a, &stack_b, chunks, chunk_count);
	push_back_to_a(&stack_a, &stack_b);
	free(chunks);
	free_stack(stack_a);
	return (0);
}
