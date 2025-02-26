/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:36:11 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:10 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push(t_stack *dst, t_stack *src)
{
    t_node *node;

    if (!dst)
        return ;//(ft_printf("Error: push | dst is NULL\n"), 0);
    if (!src)
        return ;//(ft_printf("Error: push | src is NULL\n"), 0);
    if (!src->top)
        return ;//(ft_printf("Error: push | src->top is NULL\n"), 0);
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
	
	return ;//(1);
}


void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	// ft_printf("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	// ft_printf("pb\n");
}