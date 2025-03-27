/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/27 11:30:41 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	if (!stack_a || is_sorted(stack_a) || stack_size(stack_a) == 1)
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = NULL;
	normalize_stack(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
