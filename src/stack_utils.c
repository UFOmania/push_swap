/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:16:25 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 13:53:40 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_stack_size(t_stack *stack)
{
	int 	lenth;
	t_node	*node;

	lenth = 0;
	node = stack->top;
	while (node)
	{
		lenth++;
		node = node->next;
	}
	return (lenth);
}

void free_stack(t_stack **stack)
{
	t_node	*tmp;
	t_node	*node;

	if (*stack == NULL)
		return ;
	node = (*stack)->top;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(*stack);
	*stack = NULL;
}

t_stack	*new_stack()
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if(stack == NULL)
		return NULL;
	stack->bottom = NULL;
	stack->top = NULL;
	return (stack);
}
