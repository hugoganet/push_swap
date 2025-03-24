/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:16:20 by hganet            #+#    #+#             */
/*   Updated: 2025/03/24 15:11:17 by hganet           ###   ########.fr       */
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
	if (first > second && second < third && first < third) // 2, 1, 3
		sa(*a); // 1, 2, 3
	else if (first > second && second > third) // 3, 2 , 1
	{
		sa(*a); // 2, 3, 1
		rra(a); // 1, 2, 3
	}
	else if (first > second && second < third && first > third) // 3, 1, 2
		ra(a); // 1, 2, 3
	else if (first < second && second > third && first < third) // 1, 3, 2
	{
		sa(*a); // 3, 1, 2
		ra(a); // 1, 2, 3
	}
	else if (first < second && second > third && first > third) // 2, 3, 1
		rra(a); // 1, 2, 3
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
	else if (pos == 2) // 4, 3, 1, 2
	{
		ra(a); // 3, 1, 2, 4
		ra(a); // 1, 2, 4, 3
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);	   // push smallest to B : 2, 4, 3
	sort_three(a); // sort remaining 3 : 2, 3, 4
	pa(a, b);	   // bring back min : 1, 2 , 3, 4
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
	else if (pos == 3) // 3, 5, 2, 1, 4
	{
		rra(a); // 4, 3, 5, 2, 1
		rra(a); // 1, 4, 3, 5, 2
	}
	else if (pos == 4)
		rra(a);
	pb(a, b);		 // push smallest to B : 4, 3, 5, 2
	sort_four(a, b); // sort remaining 4 : 2, 3, 4, 5
	pa(a, b);		 // bring back min : 1, 2, 3, 4, 5
}
