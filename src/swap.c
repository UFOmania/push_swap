/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:42:31 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:37 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack *stack)
{
	t_node	*second;
	t_node	*third;
	t_node	*first;

	if (stack == NULL && stack->top == stack->bottom)
		return ;
	first = stack->top;
	second = stack->top->next;
	third = stack->top->next->next;
	first->prev = second;
	if (third)
		first->next = third;
	else
		first->next = NULL;
	second->prev = NULL;
	second->next = first;
	if (third)
		third->prev = first;
	stack->top = second;
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}