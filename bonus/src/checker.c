/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:02:32 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 17:18:12 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int get_move_code(char *move)
{
	if (ft_strncmp(move, "ra", 2) == 0)
		return (RA);
	else if (ft_strncmp(move, "rb", 2) == 0)
		return (RB);
	else if (ft_strncmp(move, "rr", 2) == 0)
		return (RR);
	else if (ft_strncmp(move, "rrb", 2) == 0)
		return (RRB);
	else if (ft_strncmp(move, "rra", 2) == 0)
		return (RRA);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		return (RRR);
	else if (ft_strncmp(move, "sa", 2) == 0)
		return (SA);
	else if (ft_strncmp(move, "sb", 2) == 0)
		return (SB);
	else if (ft_strncmp(move, "ss", 2) == 0)
		return (SS);
	else if (ft_strncmp(move, "pa", 2) == 0)
		return (PA);
	else if (ft_strncmp(move, "pb", 2) == 0)
		return (PB);
	else
		return (0);
}

int	aplly_the_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	int	move_code;

	move_code = get_move_code(move);
	if (move_code == 0)
		return (0);
	if (move_code == RA)
		ra(stack_a);
	else if (move_code == RB)
		rb(stack_b);
	else if (move_code == RR)
		rr(stack_a, stack_b);
	else if (move_code == RRA)
		rra(stack_a);
	else if (move_code == RRB)
		rrb(stack_b);
	else if (move_code == RRR)
		rrr(stack_a, stack_b);
	else if (move_code == SA)
		sa(stack_a);
	else if (move_code == SB)
		sb(stack_b);
	else if (move_code == SS)
		ss(stack_a, stack_b);
	else if (move_code == PA)
		pa(stack_a, stack_b);
	else 
		pb(stack_b, stack_a);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_b;
	t_stack	*stack_a;

	if (ac == 1)
		return (0);
	stack_a = new_stack();
	stack_b = new_stack();
	if (!stack_a || !stack_a || load_inputs(stack_a, av, ac) == 0)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	init_indexes(stack_a);
	char *move;
	move = get_next_line(0);
	int status = 1;
	while (move && status)
	{
		status = aplly_the_move(stack_a, stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (is_stack_sorted(stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
