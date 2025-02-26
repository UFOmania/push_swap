/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:46:20 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:06 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (ft_putendl_fd("Error", 2), NULL);
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
		return (ft_putendl_fd("Error:push node | struct is NULL", 2), 0);
	if (node == NULL)
		return (ft_putendl_fd("Error:push node | node is NULL", 2), 0);
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
