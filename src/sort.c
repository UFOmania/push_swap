/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:17:55 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/27 18:09:07 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	befor_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	int		top_index;
	int		left_to_push;
	int		size;

	left_to_push = get_stack_size(stack_a);
	top_index = left_to_push - 1;
	size = get_stack_size(stack_a);
	while (left_to_push)
	{
		index = stack_a->top->index;
		if (index != 0 && index != top_index && index != top_index - 1)
		{
			pb(stack_b, stack_a);
			if (stack_b->top->index <= size / 2 && \
			stack_b->top != stack_b->bottom)
				rb(stack_b);
		}
		else
			ra(stack_a);
		left_to_push--;
	}
}

void	after_sorting(t_stack *stack_a)
{
	int	zero_pos;
	int	size;

	size = get_stack_size(stack_a);
	zero_pos = get_element_pos(stack_a, 0);
	if (zero_pos > size / 2)
		while (stack_a->top->index != 0)
			rra(stack_a);
	else
		while (stack_a->top->index != 0)
			ra(stack_a);
}

void	get_element_to_top_a(t_stack *stack, t_node *target)
{
	int	size;
	int	target_pos;

	target_pos = get_element_pos(stack, target->index);
	size = get_stack_size(stack);
	if (target_pos <= size / 2)
		while (stack->top->index != target->index)
			ra(stack);
	else
		while (stack->top->index != target->index)
			rra(stack);
}

void	get_element_to_top_b(t_stack *stack, t_node *target)
{
	int	size;
	int	target_pos;

	target_pos = get_element_pos(stack, target->index);
	size = get_stack_size(stack);
	if (target_pos <= size / 2)
		while (stack->top->index != target->index)
			rb(stack);
	else
		while (stack->top->index != target->index)
			rrb(stack);
}

void	normal_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_best	best;
	t_vars	v;

	(befor_sorting(stack_a, stack_b), sort_three(stack_a));
	while (stack_b->top)
	{
		best = generate_cost(stack_a, stack_b);
		while (stack_a->top != best.target && stack_b->top != best.smallest)
		{
			v.size_a = get_stack_size(stack_a);
			v.size_b = get_stack_size(stack_b);
			v.trgt_pos = get_element_pos(stack_a, best.target->index);
			v.sml_pos = get_element_pos(stack_b, best.smallest->index);
			if (v.trgt_pos > v.size_a / 2 && v.sml_pos > v.size_b / 2)
				rrr(stack_a, stack_b);
			else if (v.trgt_pos <= v.size_a / 2 && v.sml_pos <= v.size_b / 2)
				rr(stack_a, stack_b);
			else
				break ;
		}
		get_element_to_top_a(stack_a, best.target);
		get_element_to_top_b(stack_b, best.smallest);
		pa(stack_a, stack_b);
	}
	after_sorting(stack_a);
}
