/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:25:38 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 19:49:26 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../_libft/libft.h"
# include "../../_libft/get_next_line.h"
# include <limits.h>
#include <stdio.h>

#define RA 1
#define RB 2
#define RR 3
#define RRA 4
#define	RRB 5
#define RRR 6
#define PA 7
#define PB 8
#define SA 9
#define SB 10
#define SS 11

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

int		push_node(t_stack *stack, t_node *node);
t_node	*node_new(int value);

int		load_inputs(t_stack *stack, char **args, int count);

void	free_stack(t_stack **stack);
t_stack	*new_stack();

int	is_stack_sorted(t_stack *stack);

void	init_indexes(t_stack *stack_a);

void print_stack(t_stack *stack, char *msg);

#endif