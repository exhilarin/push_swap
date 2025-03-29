/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:51 by iguney            #+#    #+#             */
/*   Updated: 2025/03/29 16:34:12 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_match;

	(*stack_a)->size = stack_size(*stack_a);
	if ((*stack_a)->size <= 3)
		sort_for_three(stack_a);
	else
	{
		push_b(stack_a, stack_b);
		if ((*stack_a)->size > 3)
			push_b(stack_a, stack_b);
		while (stack_size(*stack_a) > 3)
		{
			best_match = find_best_match(*stack_a, *stack_b);
			(*stack_b)->target = find_target_in_b(*stack_b, best_match->data);
			move_to_top(stack_a, stack_b, best_match, (*stack_b)->target);
			push_b(stack_a, stack_b);
		}
		while (stack_size(*stack_b) != 0)
		{
			(*stack_a)->target = find_target_in_a(*stack_a, (*stack_b)->data);
			move_to_top(stack_a, stack_b, (*stack_a)->target, *stack_b);
			push_a(stack_a, stack_b);
		}
	}
}


t_stack	*find_best_match(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*best_match;
	t_stack	*target_b;
	t_stack	*current;
	int		min_cost;
	int		cost;

	best_match = NULL;
	current = stack_a;
	min_cost = INT_MAX;
	while (current)
	{
		target_b = find_target_in_b(stack_b, current->data);
		cost = calculate_total_cost(current, stack_a, target_b, stack_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_match = current;
		}
		current = current->next;
	}
	if (best_match == NULL)
		best_match = stack_a;
	return (best_match);
}

t_stack *find_target_in_a(t_stack *stack_a, int data)
{
    t_stack *target = NULL;
    t_stack *current = stack_a;

    while (current)
    {
        if (current->data > data && (!target || current->data < target->data))
            target = current;
        current = current->next;
    }
	if (target == NULL)
		target = stack_a;
    return (target);
}


t_stack	*find_target_in_b(t_stack *stack_b, int data)
{
	t_stack	*target;
	t_stack	*current;
	int		max_smaller;

	target = NULL;
	current = stack_b;
	max_smaller = INT_MIN;
	while (current)
	{
		if (current->data < data && current->data > max_smaller)
		{
			max_smaller = current->data;
			target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		target = stack_b;
	return (target);
}

void	move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	int	mid_a = (*stack_a)->size / 2;
	int	mid_b = (*stack_b)->size / 2;
	
	(*stack_a)->index = get_index(node_a, *stack_a);
	(*stack_b)->index = get_index(node_b, *stack_b);

	if ((*stack_a)->index == 0 && (*stack_b)->index == 0)
		return ;

	while ((*stack_a)->index > 0 && (*stack_b)->index > 0 
		&& (*stack_a)->index <= mid_a && (*stack_b)->index <= mid_b)
		rotate_rotate(stack_a, stack_b);
	while ((*stack_a)->index > mid_a && (*stack_b)->index > mid_b)
		rev_rotate_rotate(stack_a, stack_b);
	while ((*stack_a)->index-- > 0 && (*stack_a)->index <= mid_a)
		rotate_a(stack_a);
	while ((*stack_a)->index-- > mid_a)
		rev_rotate_a(stack_a);
	while ((*stack_b)->index-- > 0 && (*stack_b)->index <= mid_b)
		rotate_b(stack_b);
	while ((*stack_b)->index-- > mid_b)
		rev_rotate_b(stack_b);
}


