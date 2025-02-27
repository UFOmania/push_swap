/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:36:11 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/27 17:23:13 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!dst || !src || !src->top)
		return ;
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
	return ;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
