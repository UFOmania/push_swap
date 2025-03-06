/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:30:56 by massrayb          #+#    #+#             */
/*   Updated: 2025/03/06 16:59:07 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*get_smallest_value(t_stack *stack_a)
{
	t_node	*node;
	t_node	*smallest;
	int		s_value;

	smallest = stack_a->top;
	s_value = INT_MAX;
	node = stack_a->top;
	while (node)
	{
		if (node->value < s_value && node->index == -1)
		{
			smallest = node;
			s_value = node->value;
		}
		node = node->next;
	}
	return (smallest);
}

void	init_indexes(t_stack *stack_a)
{
	int		i;
	t_node	*node;
	t_node	*smallest;

	node = stack_a->top;
	i = 0;
	while (node)
	{
		smallest = get_smallest_value(stack_a);
		smallest->index = i++;
		node = node->next;
	}
}
