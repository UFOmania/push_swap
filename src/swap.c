/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:42:31 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/23 14:52:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int swap(t_stack *stack)
{
	t_node	*second;
	t_node	*third;
	t_node	*first;

	if (stack == NULL)
		return (ft_printf("Error: swap | stack is NULL\n"), 0);
	if (stack->top == stack->bottom)
		return (ft_printf("Error: swap: can't swap stack of one element\n"), 0);

	first = stack->top;
	second = stack->top->next;
	third = stack->top->next->next;
	
	first->prev = second;
	first->next = third;

	second->prev = NULL;
	second->next = first;

	third->prev = first;
	
	stack->top = second;
	
	return (1);
}

int	sb(t_stack *stack_b)
{
	swap(stack_b);
	return (ft_printf("sb\n"), 1);
}

int	sa(t_stack *stack_a)
{
	swap(stack_a);
	return (ft_printf("sa\n"), 1);
}

int ss(t_stack *stack_a, t_stack *stack_b)
{
	int state;

	state = swap(stack_a);
	if (state)
		state = swap(stack_b);
	return (ft_printf("ss\n"), 1);
}