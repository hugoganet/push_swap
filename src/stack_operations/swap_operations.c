/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:11:34 by hganet            #+#    #+#             */
/*   Updated: 2025/03/25 16:55:05 by hganet           ###   ########.fr       */
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

/**
 * @brief Swaps the first two elements of stack B.
 *
 * Does nothing if the stack has less than 2 elements.
 *
 * @param stack A pointer to the head of stack B.
 */
void sb(t_node *stack)
{
	int temp;

	if (!stack || !stack->next)
		return;
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
void ss(t_node *stack_a, t_node *stack_b)
{
	int swapped;
	int temp;

	swapped = 0;
	if (stack_a && stack_a->next)
	{
		temp = stack_a->value; // store the value of the head
		stack_a->value = stack_a->next->value; // set the value of the 1rst to the 2nd node
		stack_a->next->value = temp; // set the value of the 2nd node to the previously 1rst
		swapped = 1;
	}
	if (stack_b && stack_b->next)
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
		swapped = 1;
	}
	if (swapped) // check that at least one has been swapped
		write(1, "ss\n", 3);
}