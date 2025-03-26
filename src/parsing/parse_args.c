/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:46:38 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 11:18:56 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Handles invalid argument cases in parse_args.
 *
 * Frees args if needed, exits the program with error.
 *
 * @param args The args array.
 * @param ac The argument count.
 */
static t_node *handle_invalid_args(char **args, int ac)
{
	if (ac == 2)
		free_args(args);
	error_exit();
	return (NULL);
}

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
 * @brief Returns the list of argument tokens from av.
 *
 * If there is only one argument (quoted string), splits it.
 * Otherwise, returns av + 1.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return A NULL-terminated string array of tokens.
 */
char **get_args(int ac, char **av)
{
	if (ac == 2)
		return (ft_split(av[1], ' '));
	return (av + 1);
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
	args = get_args(ac, av);
	if (!args || !args[0])
		return (handle_invalid_args(args, ac));
	i = 0;
	while (args[i]) // loop on each number of the argument 
	{
		if (!ft_atoi_safe(args[i], &num) || is_duplicate(stack, num))
		{
			// if convertion failed or if a duplicate has been detected, free and exit 
			if (ac == 2)
				free_args(args); // if params where "1 6 9 4...", free the allocated memory in ft_split
			free_stack(stack); // free every node
			error_exit();	   // Prints an error message to stderr and exits with code 1.
		}
		add_back(&stack, new_node(num)); // create a new node and add it at the back of the linked list
		i++;
	}
	if (ac == 2)
		free_args(args); // if params where "1 6 9 4...", free the allocated memory in ft_split
	return (stack);
}
