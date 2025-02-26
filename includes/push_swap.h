/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:22 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 15:28:51 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../_libft/libft.h"
# include "../_printf/ft_printf2.h"
# include <limits.h>
// #include <stdio.h>

# define NULL_TERMINATOR 1
# define SPACE 1

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}				t_stack;

typedef struct
{
	t_node	*smallest;
	t_node	*target;
}				t_best;

int		load_inputs(t_stack *stack, char **args, int count);
int		push_node(t_stack *stack, t_node *node);
t_node	*node_new(int value);

void	free_stack(t_stack **stack);
t_stack	*new_stack();
int		get_stack_size(t_stack *stack);

int get_biggest_index(t_stack *stack);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack * stack_b);
void	pb(t_stack *stack_b, t_stack * stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	print_stacks(t_stack *stack,t_stack *stack2);

void	print_stack(t_stack *stack, char *msg);
void	print_stack_adrs(t_stack *stack);

t_best	generate_cost(t_stack *stack_a, t_stack *stack_b);

void	befor_sorting(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	after_sorting(t_stack *stack_a);
void	init_indexes(t_stack *stack_a);

void sort_three(t_stack *stack_a);

int	get_element_pos(t_stack *stack, int element);

#endif