/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:10:29 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 15:52:46 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts an array of integers in ascending order using bubble sort.
 *
 * This simple sort is enough for small to mid-sized input,
 * as push_swap uses it just once during indexing.
 *
 * @param arr The array to sort.
 * @param size Number of elements in the array.
 */
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	temp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}
