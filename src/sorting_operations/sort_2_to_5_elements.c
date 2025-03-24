/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:16:20 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 13:49:52 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort a stack with 2 elements
 * 
 * @param a A pointer to the stack to sort
 */
void sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}

/**
 * @brief Sort a stack with 3 elements
 *
 * @param a A pointer to the stack to sort
 */
void sort_three(t_node **a)
{
	int first;
	int second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(*a);
	else if (first > second && second > third)
	{
		sa(*a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(*a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}


/**
 * @brief Sort a stack of 4 elements
 * 
 * @param a A pointer to the stack_a
 * @param b A pointer to the stack_b
 */
void sort_four(t_node **a, t_node **b)
{
	int min;
	int pos;

	min = find_min_value(*a);
	pos = find_position(*a, min);
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);	   // push smallest to B
	sort_three(a); // sort remaining 3
	pa(a, b);	   // bring back min
}

/**
 * @brief Sort a stack of 5 elements
 *
 * @param a A pointer to the stack_a
 * @param b A pointer to the stack_b
 */
void sort_five(t_node **a, t_node **b)
{
	int min;
	int pos;

	min = find_min_value(*a);
	pos = find_position(*a, min);
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (pos == 4)
		rra(a);
	pb(a, b);		 // push smallest to B
	sort_four(a, b); // sort remaining 4
	pa(a, b);		 // bring back min
}
