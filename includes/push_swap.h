/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:10:20 by hganet            #+#    #+#             */
/*   Updated: 2025/03/21 15:54:50 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

/**
 * @struct s_node
 * @brief Represents an element in a singly linked stack.
 *
 * Each node stores an integer value and a pointer to the next node.
 */
typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

t_node *parse_args(int ac, char **av);

int is_valid_token(char *str);
int has_overflow(char *str, int *out);
int is_duplicate(t_node *stack, int value);

t_node *new_node(int value);
void add_back(t_node **stack, t_node *new);
void free_args(char **args);
void free_stack(t_node *stack);
void error_exit(void);

#endif