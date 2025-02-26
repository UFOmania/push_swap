/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:44:02 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 20:49:34 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	if (ac == 1)
		return (ft_putendl_fd("Error: arguments count is invalid", 2), 1);
	stack_a = new_stack();
	stack_b = new_stack();

	if (!stack_a || !stack_a || load_inputs(stack_a, av, ac) == 0)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	init_indexes(stack_a);
	int s_size = get_stack_size(stack_a);
	if (s_size < 3)
	{
		if(stack_a->top->index > stack_a->bottom->index)
			sa(stack_a);
	}
	else if (s_size == 3)
		sort_three(stack_a);
	else if (s_size == 5)
	{
		sort_five(stack_a, stack_b);
	}
	else
	{
		befor_sorting(stack_a, stack_b);
		sort(stack_a, stack_b);
		after_sorting(stack_a);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
