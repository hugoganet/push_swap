/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:24 by hganet            #+#    #+#             */
/*   Updated: 2025/03/21 15:42:25 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int main(int ac, char **av)
{
	t_node *stack_a;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	// TODO: use stack_a for sorting, then free it
	return (0);
}
