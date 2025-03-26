/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:41:52 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 17:02:21 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else if (size > 100 && size <= 200)
		return (6);
	else if (size > 200 && size <= 300)
		return (7);
	else if (size > 300 && size <= 400)
		return (9);
	else if (size > 400 && size <= 500)
		return (11);
	return (13);
}

/**
 * @brief Creates an array of chunks for a given stack size.
 *
 * Each chunk is a range of normalized values to be processed together.
 *
 * @param size The size of the normalized stack (i.e., max value + 1).
 * @param chunk_count The number of chunks to divide the stack into.
 * @return A dynamically allocated array of t_chunk structs.
 */
t_chunk	*generate_chunks(int size, int chunk_count)
{
	t_chunk	*chunks;
	int		chunk_size;
	int		i;

	chunks = malloc(sizeof(t_chunk) * chunk_count);
	if (!chunks)
		error_exit();
	chunk_size = size / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		chunks[i].low = i * chunk_size;
		if (i == chunk_count - 1)
			chunks[i].high = size - 1;
		else
			chunks[i].high = (i + 1) * chunk_size - 1;
		i++;
	}
	return (chunks);
}
