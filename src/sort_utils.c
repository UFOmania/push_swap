/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:24:18 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/27 17:28:38 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_biggest_index(t_stack *stack)
{
	int		biggest;
	t_node	*node;

	biggest = 0;
	node = stack->top;
	while (node)
	{
		if (node->index > biggest)
			biggest = node->index;
		node = node->next;
	}
	return (biggest);
}

void	sort_three(t_stack *stack_a)
{
	int	max;

	max = get_biggest_index(stack_a);
	if (stack_a->top->index == max)
		ra(stack_a);
	else if (stack_a->top->next->index == max)
		rra(stack_a);
	if (stack_a->top->index != 0)
		sa(stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (stack_a->top->index == 0 || stack_a->top->index == 1)
		{
			pb(stack_b, stack_a);
			if (stack_b->top->index < stack_b->bottom->index)
				rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	if (stack_a->top->index == get_biggest_index(stack_a))
		ra(stack_a);
	else if (stack_a->top->next->index == get_biggest_index(stack_a))
		rra(stack_a);
	if (stack_a->top->index != 2)
		sa(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	get_element_pos(t_stack *stack, int element)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (node->index == element)
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}
