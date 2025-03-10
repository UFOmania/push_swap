/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:41:14 by massrayb          #+#    #+#             */
/*   Updated: 2025/03/06 17:11:47 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	rotate(t_stack *stack)
{
	t_node	*old_top;

	if (stack == NULL)
		return ;
	if (stack->top == NULL || stack->bottom == NULL)
		return ;
	if (stack->top == stack->bottom)
		return ;
	old_top = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	old_top->next = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
	return ;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
