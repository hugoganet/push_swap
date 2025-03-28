/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:10:20 by hganet            #+#    #+#             */
/*   Updated: 2025/03/27 11:29:01 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/**
 * @struct s_node
 * @brief Represents an element in a singly linked stack.
 *
 * Each node stores an integer value and a pointer to the next node.
 */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/**
 * @brief Represents a chunk range with a lower and upper bound.
 */
typedef struct s_chunk
{
	int	low;
	int	high;
}	t_chunk;

// ##### chunk_operations #####
	// generate_chunks.c
int		get_chunk_count(int size);
t_chunk	*generate_chunks(int size, int chunk_count);
	// process_chunks.c
void	process_chunks(
			t_node **a,
			t_node **b,
			t_chunk *chunks,
			int chunk_count);
void	push_back_to_a(t_node **a, t_node **b);
	// push_one_chunk.c
int		in_chunk(int value, t_chunk chunk);
int		count_in_chunk(t_node *stack, t_chunk chunk);
void	push_chunk_to_b(t_node **a, t_node **b, t_chunk chunk);

// ##### indexing #####
int		find_index(int *sorted, int size, int value);
void	fill_array_from_stack(t_node *stack, int *arr);
void	normalize_stack(t_node *stack);

// ##### memory_and_errors #####
void	error_exit(void);
	// free.c
void	free_args(char **args);
void	free_stack(t_node *stack);

// ##### parsing #####
int		ft_atoi_safe(char *str, int *out);
	// parse_args.c
t_node	*parse_args(int ac, char **av);
int		is_duplicate(t_node *stack, int value);
char	**get_args(int ac, char **av);

// ##### stack_operations
	// stack.c
t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
	// push_operations.c
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
	// rotate_both_stacks.c
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
	// rotate_operations.c
void	ra(t_node **stack);
void	rra(t_node **stack);
void	rb(t_node **stack);
void	rrb(t_node **stack);
	// swap_operations.c
void	sa(t_node *stack);
void	sb(t_node *stack);
void	ss(t_node *stack_a, t_node *stack_b);

// ##### sorting_operations #####
	// sort_stack.c
void	sort_stack(t_node **a, t_node **b);
	// helper_functions.c
int		find_min_value(t_node *stack);
int		find_max_value(t_node *stack);
int		find_position(t_node *stack, int target);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
	// sort_2_to_5_elements.c
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
	// bubble_sort.c
void	bubble_sort(int *arr, int size);
#endif