/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:15:36 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 20:46:07 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int check_limits_then_push(t_stack *stack, char *sub_str)
{
	t_node	*node;
	long	value;

	value = ft_atoi(sub_str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	node = node_new(value);
	if (node == NULL)
		return (ft_putendl_fd("Error", 2), 0);
	return (push_node(stack, node), 1);
}

static int validate_arg(t_stack *stack, char **sub_str)
{
	
	int		i;
	int		j;

	i = -1;
	while (sub_str[++i])
	{
		j = 0;
		while (sub_str[i][j] == ' ')
			j++;
		if (sub_str[i][j] == '+' || sub_str[i][j] == '-')
			j++;
		if (!sub_str[i][j] || !ft_isdigit(sub_str[i][j]) || !check_limits_then_push(stack, sub_str[i]))
			return (ft_putendl_fd("Error", 2), 0);
		while (ft_isdigit(sub_str[i][j]))
			j++;
		if (sub_str[i][j] != '\0')
			return (ft_putendl_fd("Error", 2), 0);
	}
	return (1);
}

static int	check_for_empty_numbers_and_alien_chars(char *str)
{
	int i;
	int num_found;

	num_found = 0;
	if (str[0] == '\0')
		return (ft_putendl_fd("Error", 2), 0);
	i = -1;
	while (str[++i])
	{	
		if (num_found == 0 && ft_isdigit(str[i]))
			num_found = 1;
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (ft_putendl_fd("Error", 2), 0);
	}
	if (num_found == 0)
		return (ft_putendl_fd("Error", 2), 0);
	return (1);
}

static int check_for_repeat(t_stack *stack)
{
	t_node *head;
	t_node *tmp;

	head = stack->top;
	while (head)
	{
		tmp = head->next;
		while(tmp)
		{
			if(head->value == tmp->value)
				return (ft_putendl_fd("Error", 2), 0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}

int	load_inputs(t_stack *stack, char **args, int count)
{
	int	i;
	int j;
	int status;
	char **sub_strs;

	i = 0;
	status = 1;
	while (++i < count && status)
	{
		if (check_for_empty_numbers_and_alien_chars(args[i]) == 0)
			return (0);
		sub_strs = ft_split(args[i], ' ');
		if (sub_strs == NULL)
			return (ft_putendl_fd("Error", 2),status = 0, 0);
		if (validate_arg(stack, sub_strs) == 0)
			status = 0;
		j = -1;
		while (sub_strs[++j])
			free(sub_strs[j]);
		free(sub_strs);
	}
	if (check_for_repeat(stack) == 0)
		status = 0;
	return (status);
}
