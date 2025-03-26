/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:11:34 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 15:43:49 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of stack A.
 *
 * Does nothing if the stack has less than 2 elements.
 *
 * @param stack A pointer to the head of stack A.
 */
void	sa(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	write(1, "sa\n", 3);
}

/**
 * @brief Swaps the first two elements of stack B.
 *
 * Does nothing if the stack has less than 2 elements.
 *
 * @param stack A pointer to the head of stack B.
 */
void	sb(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	write(1, "sb\n", 3);
}

/**
 * @brief Swaps the first two elements of stack A and B
 * 
 * Does nothing if the stack has less than 2 elements
 */
void	ss(t_node *stack_a, t_node *stack_b)
{
	int	swapped;
	int	temp;

	swapped = 0;
	if (stack_a && stack_a->next)
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
		swapped = 1;
	}
	if (stack_b && stack_b->next)
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
		swapped = 1;
	}
	if (swapped)
		write(1, "ss\n", 3);
}
