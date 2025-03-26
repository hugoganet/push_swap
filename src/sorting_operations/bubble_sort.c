/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:10:29 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 11:34:56 by hganet           ###   ########.fr       */
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
void bubble_sort(int *arr, int size)
{
	int i;
	int temp;
	int sorted;

	sorted = 0; // flag initialize to false
	while (!sorted) // continue while flag is false
	{
		sorted = 1; // set flag to true
		i = 0;
		while (i < size - 1) // loop on size-1 (to make avoid segfault with arr[i + 1])
		{
			if (arr[i] > arr[i + 1]) // if current value > next value (in the array), swap them and set the flag to fal
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
