/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:00:16 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 19:48:36 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void print_stack(t_stack *stack, char *msg)
{
	t_node *node;
	
	
	node = stack->top;
	printf("%s-----------------------------------\n", msg);
	while (node)
	{
		sleep(2);
		printf("%d: i=[%d]\n",node->value, node->index);
		node = node->next;
	}
}

void print_stacks(t_stack *stack,t_stack *stack2)
{
	t_node *node;
	t_node *node2;
	
	node2 = stack2->top;
	node = stack->top;
	printf("-A-----B-------------------------\n");
	while (node || node2)
	{
		if(node)
			printf(" %d <<%d",  node->index, node->cost);
		else
			printf(" *");
		printf("     ");
		if(node2)
			printf("%d >>%d",  node2->index,  node2->cost);
		else
			printf("*");
		printf("\n");
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
	printf("-----------------------------------\n");
	while (node)
	{
		printf("prev %p\n",  node->prev);
		printf("node %p\n",  node);
		printf("value %d\n", node->value);
		printf("next %p\n",  node->next);
		printf("bottom: %p\n", stack->bottom);
		printf("+++++++++++++++++++++++++++\n");
		sleep(1);
		node = node->next;
	}
}