/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:44:02 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 13:16:34 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void f() {system("leaks push_swap");}

int	main(int ac, char **av)
{
	// atexit(f);
	t_stack	*stack_a;
	t_stack	*stack_b;
	if (ac == 1)
		return (ft_printf("Error: arguments count is invalid\n"), 1);
	stack_a = new_stack();
	stack_b = new_stack();

	if (!stack_a || !stack_a || load_inputs(stack_a, av, ac) == 0)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	// print_stack(stack_a, "A");
	// rra(stack_a);
	init_indexes(stack_a);
	if (get_stack_size(stack_a) == 3)
		sort_three(stack_a);
	else if (get_stack_size(stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
	}
	else
	{
		befor_sorting(stack_a, stack_b);
		sort(stack_a, stack_b);
	}
	
	
	after_sorting(stack_a);
	
	// print_stack(stack_a, "A");
	// print_stack(stack_b, "B");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
