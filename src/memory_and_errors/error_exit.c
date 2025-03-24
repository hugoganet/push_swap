/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:21:13 by hganet            #+#    #+#             */
/*   Updated: 2025/03/21 15:21:15 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * Prints an error message to stderr and exits with code 1.
 *
 * This function should be called on any fatal error:
 * - invalid input
 * - allocation failure
 * - duplicate values
 */
void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
