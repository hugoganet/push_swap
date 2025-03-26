/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:18 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 16:08:28 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the index of a value inside a sorted array.
 *
 * Used during normalization to replace values by their index.
 *
 * @param sorted The sorted array.
 * @param size Size of the array.
 * @param value The value to search for.
 * @return The index of the value inside the array.
 */
int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Fills an array with values from the stack, in order.
 *
 * Used to prepare the values for sorting/indexing.
 *
 * @param stack The stack to copy from.
 * @param arr The array to fill.
 */
void	fill_array_from_stack(t_node *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
}

/**
 * @brief Converts each value in the stack to its sorted index.
 *
 * This is used to simplify the sorting logic for large stacks,
 * allowing algorithms to work with normalized values from 0 to N-1
 * instead of unpredictable input numbers.
 *
 * @param stack The stack to normalize (stack A).
 */
void	normalize_stack(t_node *stack)
{
	int		size;
	int		*values;
	t_node	*temp;

	size = stack_size(stack);
	values = malloc(sizeof(int) * size);
	if (!values)
		error_exit();
	fill_array_from_stack(stack, values);
	bubble_sort(values, size);
	temp = stack;
	while (temp)
	{
		temp->value = find_index(values, size, temp->value);
		temp = temp->next;
	}
	free(values);
}
