/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 15:11:55 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int stack_size(t_node *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int main(int ac, char **av)
{
	t_node *stack_a;
	t_node *stack_b;
	int size;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	stack_b = NULL;
	size = stack_size(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	ft_printf("Sorted stack:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
