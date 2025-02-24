/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:46:20 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/16 17:55:36 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (ft_printf("Error: can't create a new node\n"), NULL);
	node->value = value;
	node->index = -1;
	node->cost = -2;
	node->next = NULL;
	node->prev = NULL;
	return(node);
}

int	push_node(t_stack *stack, t_node *node)
{
	if (stack == NULL)
		return (ft_printf("Error:push node | struct is NULL\n"), 0);
	if (node == NULL)
		return (ft_printf("Error:push node | node is NULL\n"), 0);
	if (stack->top == NULL && stack->bottom == NULL)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
	return 1;
}
