/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:46:38 by hganet            #+#    #+#             */
/*   Updated: 2025/03/21 17:30:01 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Checks if the given value already exists in the stack.
 *
 * Walks through the linked list and compares each node’s value
 * to the input value.
 *
 * @param stack Pointer to the head of the stack.
 * @param value The value to check for.
 * @return 1 if duplicate exists, 0 otherwise.
 */
int is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * @brief Parses command-line arguments and builds the initial stack.
 *
 * Supports two formats: multiple args or one quoted string.
 * Converts and validates each number with ft_atoi_safe().
 * Rejects invalid, duplicate, or out-of-bound values.
 *
 * @param ac Argument count.
 * @param av Argument values.
 * @return A pointer to the built stack (linked list).
 */
t_node *parse_args(int ac, char **av)
{
	char **args;
	int i;
	int num;
	t_node *stack;

	stack = NULL;
	args = (ac == 2) ? ft_split(av[1], ' ') : av + 1;
	if (!args || !args[0])
		return (free_args(args), error_exit(), NULL);
	i = 0;
	while (args[i])
	{
		if (!ft_atoi_safe(args[i], &num) || is_duplicate(stack, num))
		{
			if (ac == 2)
				free_args(args);
			free_stack(stack);
			error_exit();
		}
		add_back(&stack, new_node(num));
		i++;
	}
	if (ac == 2)
		free_args(args);
	return (stack);
}
