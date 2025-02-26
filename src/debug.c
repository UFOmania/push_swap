/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:00:16 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 13:55:39 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack, char *msg)
{
	t_node *node;
	
	
	node = stack->top;
	ft_printf("%s-----------------------------------\n", msg);
	while (node)
	{
		sleep(2);
		ft_printf("%d: i=[%d]\n",node->value, node->index);
		node = node->next;
	}
}

void print_stacks(t_stack *stack,t_stack *stack2)
{
	t_node *node;
	t_node *node2;
	
	node2 = stack2->top;
	node = stack->top;
	ft_printf("-A-----B-------------------------\n");
	while (node || node2)
	{
		if(node)
			ft_printf(" %d <<%d",  node->index, node->cost);
		else
			ft_printf(" *");
		ft_printf("     ");
		if(node2)
			ft_printf("%d >>%d",  node2->index,  node2->cost);
		else
			ft_printf("*");
		ft_printf("\n");
		if(node)
			node = node->next;
		if (node2)
			node2 = node2->next;
			
	}
}

void print_stack_adrs(t_stack *stack)
{
	t_node *node;

	node = stack->top;
	ft_printf("-----------------------------------\n");
	while (node)
	{
		ft_printf("prev %p\n",  node->prev);
		ft_printf("node %p\n",  node);
		ft_printf("value %d\n", node->value);
		ft_printf("next %p\n",  node->next);
		ft_printf("bottom: %p\n", stack->bottom);
		ft_printf("+++++++++++++++++++++++++++\n");
		sleep(1);
		node = node->next;
	}
}