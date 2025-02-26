/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:41:14 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:14 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void rotate(t_stack *stack)
{
	t_node	*old_top;
	
	if (stack == NULL)
		return ;//(ft_printf("Error:rotate_a | satck_a is NULL"), 0);
	if (stack->top == NULL || stack->bottom == NULL)
		return ;//(ft_printf("Error:rotate_a | satck_a emety"), 0);
	if (stack->top == stack->bottom)
		return ;//(0);
	old_top = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;

	old_top->next = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;

	return ;//(1);
}

// int reverse_rotate(t_stack *stack)
// {
//     t_node *old_bottom;

//     if (!stack || !stack->top || !stack->bottom || stack->top == stack->bottom)
//         return (ft_printf("Error: reverse_rotate | stack is empty or too small"), 0);

//     old_bottom = stack->bottom;
//     stack->bottom = old_bottom->prev;

//     if (stack->bottom) // Only update next if stack->bottom is not NULL
//         stack->bottom->next = NULL;
    
//     old_bottom->next = stack->top;
//     stack->top->prev = old_bottom;
//     stack->top = old_bottom;
//     stack->top->prev = NULL;
// 	// stack->bottom->next = NULL;

//     return (1);
// }

void reverse_rotate(t_stack *stack)
{
    t_node *old_bottom;

    if (!stack || !stack->top || !stack->bottom || stack->top == stack->bottom)
        return ;//(ft_printf("Error: reverse_rotate | stack is empty or too small"), 0);

    old_bottom = stack->bottom;
    stack->bottom = old_bottom->prev;

    if (stack->bottom) // Only update next if stack->bottom is not NULL
        stack->bottom->next = NULL;
    
    old_bottom->prev = NULL;  // Ensure the old bottom has no previous
    old_bottom->next = stack->top; // Move old bottom to the top
    stack->top->prev = old_bottom; // Link the old top to the new top
    stack->top = old_bottom; // Set the new top

    return ;//(1);
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	// ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	// ft_printf("rb\n");
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	// ft_printf("rra\n");
}


void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	// ft_printf("rrb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	// ft_printf("rr\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	// ft_printf("rrr\n");
}