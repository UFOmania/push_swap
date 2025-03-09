/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:44:02 by massrayb          #+#    #+#             */
/*   Updated: 2025/03/09 15:30:06 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

static int	is_stack_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->next)
			if (node->next->index < node->index)
				return (0);
		node = node->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;

	if (ac == 1)
		return (0);
	stack_a = new_stack();
	stack_b = new_stack();
	if (!stack_a || !stack_a || load_inputs(stack_a, av, ac) == 0)
		return (free_stacks(&stack_a, &stack_b), 1);
	init_indexes(stack_a);
	s_size = get_stack_size(stack_a);
	if (is_stack_sorted(stack_a))
		(void)NULL;
	else if (s_size < 3 && stack_a->top->index > stack_a->bottom->index)
		sa(stack_a);
	else if (s_size == 3)
		sort_three(stack_a);
	else if (s_size == 5)
		sort_five(stack_a, stack_b);
	else
		normal_sort(stack_a, stack_b);
	return (free_stacks(&stack_a, &stack_b), 0);
}
