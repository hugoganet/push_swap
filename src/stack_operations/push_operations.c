/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:13:22 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 14:50:19 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element of stack A to stack B.
 *
 * If stack A is empty, does nothing.
 *
 * @param a A pointer to stack A (source).
 * @param b A pointer to stack B (destination).
 */
void pb(t_node **a, t_node **b)
{
	t_node *tmp;

	if (!*a)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

/**
 * @brief Pushes the top element of stack B to stack A.
 *
 * If stack B is empty, does nothing.
 *
 * @param a A pointer to stack A (destination).
 * @param b A pointer to stack B (source).
 */
void pa(t_node **a, t_node **b)
{
	t_node *tmp;

	if (!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}
