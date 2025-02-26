/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:36:11 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/25 17:48:19 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int push(t_stack *dst, t_stack *src)
{
    t_node *node;

    if (!dst)
        return (ft_printf("Error: push | dst is NULL\n"), 0);
    if (!src)
        return (ft_printf("Error: push | src is NULL\n"), 0);
    if (!src->top)
        return (ft_printf("Error: push | src->top is NULL\n"), 0);
	node = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	if (dst->top)
	{
		node->next = dst->top;
		dst->top->prev = node;
		dst->top = node;
	}
	else
	{
		dst->top = node;
		dst->bottom = node;
		dst->top->next = node;
		dst->bottom->prev = node;
		dst->bottom->next = NULL;
	}
	
	return (1);
}


int	pa(t_stack *stack_a, t_stack *stack_b)
{
	int status;

	status = push(stack_a, stack_b);
	return (ft_printf("pa\n"), status);
}

int	pb(t_stack *stack_b, t_stack *stack_a)
{
	int	status;

	status = push(stack_b, stack_a);
	return (ft_printf("pb\n"), status);
}