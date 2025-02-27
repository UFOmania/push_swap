/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:41:14 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/27 17:27:01 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
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

void	reverse_rotate(t_stack *stack)
{
	t_node	*old_bottom;

	if (!stack || !stack->top || !stack->bottom || stack->top == stack->bottom)
		return ;
	old_bottom = stack->bottom;
	stack->bottom = old_bottom->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
	return ;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
