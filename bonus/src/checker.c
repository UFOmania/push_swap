/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:02:32 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 20:49:50 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int get_move_code(char *move)
{
	if (ft_strncmp(move, "ra\n", 3) == 0)
		return (RA);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		return (RB);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		return (RR);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		return (RRB);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		return (RRA);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		return (RRR);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		return (SA);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		return (SB);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		return (SS);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		return (PA);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		return (PB);
	else
		return (-(move == NULL));
}

static int	apply_the_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	int	move_code;

	move_code = get_move_code(move);
	if (move_code == 0 || move_code == -1)
		return (move_code);
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
	else if (move_code == PB)
		pb(stack_b, stack_a);
	return (1);
}

static void	put_result(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (status == 0)
		ft_putendl_fd("Error", 2);
	else if (is_stack_sorted(stack_a) == 0 || stack_b->top != NULL)	
		ft_putendl_fd("KO", 2);
	else
		ft_putendl_fd("OK", 1);
}

// void f(){system("leaks checker");}

int	main(int ac, char **av)
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	char	*move;
	int		status;

	if (ac == 1)
		return (0);
	stack_a = new_stack();
	stack_b = new_stack();
	if (!stack_a || !stack_a || load_inputs(stack_a, av, ac) == 0)
		return (free_stack(&stack_a), free_stack(&stack_b), 1);
	init_indexes(stack_a);
	status = 1;
	while (status != 0 && status != -1)
	{
		move = get_next_line(0);
		status = apply_the_move(stack_a, stack_b, move);
		free(move);
	}
	put_result(stack_a, stack_b, status);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (status == 1)
		return (0);
	return (0);
}
