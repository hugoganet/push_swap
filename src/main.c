/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/25 15:38:14 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints the contents of a stack for debugging.
 *
 * @param stack Pointer to the top of the stack.
 */
// static void print_stack(t_node *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// }

static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	return (11);
}

int main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int 	size;
	t_chunk *chunks;
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
