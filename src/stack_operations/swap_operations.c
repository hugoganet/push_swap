/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:11:34 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 10:12:47 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/**
 * @brief Swaps the first two elements of stack A.
 *
 * Does nothing if the stack has less than 2 elements.
 *
 * @param stack A pointer to the head of stack A.
 */
void sa(t_node *stack)
{
	int temp;

	if (!stack || !stack->next)
		return;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	write(1, "sa\n", 3);
}

// TODO sb and ss