/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:17:55 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/26 20:46:20 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_biggest_index(t_stack *stack)
{
	int biggest;
	t_node *node;

	biggest = 0;
	node = stack->top;
	while (node)
	{
		if (node->index > biggest)
			biggest = node->index;
		node = node->next;
	}
	return (biggest);
}
// int get_smallest_index(t_stack *stack)
// {
// 	int smallest;
// 	t_node *node;

// 	smallest = 0;
// 	node = stack->top;
// 	while (node)
// 	{
// 		if (node->index < smallest)
// 			smallest = node->index;
// 		node = node->next;
// 	}
// 	return (smallest);
// }

void sort_three(t_stack *stack_a)
{
	int	max;

	max = get_biggest_index(stack_a);
	if (stack_a->top->index == max)
		ra(stack_a);
	else if (stack_a->top->next->index == max)
		rra(stack_a);
	if (stack_a->top->index != 0)
		sa(stack_a);
}

void	befor_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	int		top_index;
	int		left_to_push;
	int	size;
	

	left_to_push = get_stack_size(stack_a);
	top_index = left_to_push - 1;
	size = get_stack_size(stack_a);
	while (left_to_push)
	{
		index = stack_a->top->index;
		if (index != 0 && index != top_index && index != top_index - 1)
		{
			pb(stack_b, stack_a);
			if (stack_b->top->index <= size / 2 && stack_b->top != stack_b->bottom)//&& get_stack_size(stack_b) > 2
				rb(stack_b);
		}
		else
			ra(stack_a);
		left_to_push--;
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (stack_a->top->index == 0 || stack_a->top->index == 1)
		{
			pb(stack_b, stack_a);
			if (stack_b->top->index < stack_b->bottom->index)
				rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	if (stack_a->top->index == get_biggest_index(stack_a))
		ra(stack_a);
	else if (stack_a->top->next->index == get_biggest_index(stack_a))
		rra(stack_a);
	if (stack_a->top->index != 2)
		sa(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	get_element_pos(t_stack *stack, int element)
{
	t_node *node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (node->index == element)
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}
void	after_sorting(t_stack *stack_a)
{
	int	zero_pos;
	int	size;

	size = get_stack_size(stack_a);
	zero_pos = get_element_pos(stack_a, 0);
	if (zero_pos > size / 2)
		while (stack_a->top->index != 0)
			rra(stack_a);
	else
		while (stack_a->top->index != 0)
			ra(stack_a);
}

void get_element_to_top_a(t_stack *stack, t_node *target)
{
    int size = get_stack_size(stack);
    int target_pos = get_element_pos(stack, target->index);
    
    if (target_pos <= size / 2)
        while (stack->top->index != target->index) 
            ra(stack);  // Rotate up
    else
        while (stack->top->index != target->index)
            rra(stack);  // Rotate down
}

void get_element_to_top_b(t_stack *stack, t_node *target)
{
    int size = get_stack_size(stack);
    int target_pos = get_element_pos(stack, target->index);
    
    if (target_pos <= size / 2)
        while (stack->top->index != target->index) 
            rb(stack);  // Rotate up
    else
        while (stack->top->index != target->index)
            rrb(stack);  // Rotate down
}

// void sort(t_stack *stack_a, t_stack *stack_b)
// {
//     t_best best;

//     // Sorting three elements initially
//     sort_three(stack_a);
    
//     while (stack_b->top)
//     {
//         best = generate_cost(stack_a, stack_b);
        
//         // Optimized double rotation handling
//         while ((stack_a->top != best.target) && (stack_b->top != best.smallest))
//         {
//             int target_pos = get_element_pos(stack_a, best.target->index);
//             int smallest_pos = get_element_pos(stack_b, best.smallest->index);
//             int size_a = get_stack_size(stack_a);
//             int size_b = get_stack_size(stack_b);

//             if (target_pos > size_a / 2 && smallest_pos > size_b / 2)
//                 rrr(stack_a, stack_b);
//             else if (target_pos <= size_a / 2 && smallest_pos <= size_b / 2)
//                 rr(stack_a, stack_b);
//             else
//                 break;
//         }
        
//         // Fine-tune positioning of elements
//         get_element_to_top_a(stack_a, best.target);
//         get_element_to_top_b(stack_b, best.smallest);
        
//         pa(stack_a, stack_b);  // Push the best element back to A
//     }
// }


void sort(t_stack *stack_a, t_stack *stack_b)
{
    t_best	best;
    int		size_a;
    int		size_b;
    int		target_pos, smallest_pos;

    sort_three(stack_a);
    while (stack_b->top)
    {

        best = generate_cost(stack_a, stack_b);
        while (stack_a->top != best.target && stack_b->top != best.smallest)
		{
			size_a = get_stack_size(stack_a);
    		size_b = get_stack_size(stack_b);
			target_pos = get_element_pos(stack_a, best.target->index);
			smallest_pos = get_element_pos(stack_b, best.smallest->index);
			if (target_pos > size_a / 2 && smallest_pos > size_b / 2)
				rrr(stack_a, stack_b);  // Reverse rotations for both stacks
			else if (target_pos <= size_a / 2 && smallest_pos <= size_b / 2)
				rr(stack_a, stack_b);  // Forward rotations for both stacks
			else
				break ;
		}
        get_element_to_top_a(stack_a, best.target);
		get_element_to_top_b(stack_b, best.smallest);
        pa(stack_a, stack_b);  // Push the smallest element back to A
    }
}
