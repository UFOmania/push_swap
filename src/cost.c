/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:19:23 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/24 16:05:56 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



/// @brief //////////////////////////////////////
/// @param stack 
void init_stack_cost(t_stack *stack, int B)
{
	int		size;
	int		i;
	t_node	*node;


	size = get_stack_size(stack);
	i = 0;
	node = stack->top;
	while (node)
	{
		if (i < size / 2)
		{

				node->cost = i;
		}
		else
		{

				node->cost =size - i ;
		}
		i++;	
		node = node->next;
	}
}

t_node	*choose_target(t_stack *stack_a, int calee)
{
	t_node	*target;
	t_node	*node;
	int		best_index;
	
	best_index = INT_MAX;
	target = stack_a->top;
	node = stack_a->top;
	while (node)
	{
		if (node->index > calee && node->index < best_index)
		{
			best_index = node->index;
			target = node;
		}
		node = node->next;
	}
	return (target);
}

void	total_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	t_node	*target;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	node = stack_b->top;
	while (node)
	{
		target = choose_target(stack_a, node->index);
		// ft_printf("%d >>> %d\n", node->index, target->index);
		int node_pos = get_element_pos(stack_b, node->index);
		int target_pos = get_element_pos(stack_b, target->index);
		if ((target_pos < size_a / 2 && node_pos < size_b / 2) || (target_pos >= size_a / 2 && node_pos >= size_b / 2))
		{
			if (target->cost > node->cost)
				node->cost = target->cost;
		}
		else
			node->cost += target->cost;
		node = node->next;
	}
}

t_node	*get_smallest_cost(t_stack *stack_b)
{
	t_node	*node;
	t_node	*smallest;

	smallest = stack_b->top;
	node = stack_b->top;
	while (node)
	{
		if (node->cost < smallest->cost)
			smallest = node;
		node = node->next;
	}
	return (smallest);
}

t_best generate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_best best;
	int biggest = get_biggest_index(stack_a);
	// ft_printf("biggest = %d\n", biggest);
	init_stack_cost(stack_a, biggest);
	init_stack_cost(stack_b, biggest);
	total_cost(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	best.smallest = get_smallest_cost(stack_b);
	best.target = choose_target(stack_a, best.smallest->index);
	// printf("s %d| t %d\n", best.smallest->cost, best.target->cost);
	return (best);
}