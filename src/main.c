/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/21 18:27:52 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * @brief Prints the contents of a stack for debugging.
 *
 * @param stack Pointer to the top of the stack.
 */
void print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int main(int ac, char **av)
{
	t_node *stack_a;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
