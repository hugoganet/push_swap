/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:29:09 by hganet            #+#    #+#             */
/*   Updated: 2025/03/26 10:33:02 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/**
 * @brief Converts a string to an int with strict validation and overflow check.
 *
 * Parses the string manually and checks for valid characters and integer bounds.
 *
 * @param str The numeric string to parse.
 * @param out Pointer to store the converted int if valid.
 * @return 1 if conversion is valid and stored in *out, 0 if invalid or overflow.
 */
int ft_atoi_safe(char *str, int *out)
{
	int i;
	int sign;
	long result; 

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
	}
	*out = (int)(result * sign); // convert result to an int after having check the overflow
	return (1);
}
