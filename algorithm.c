/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:51 by iguney            #+#    #+#             */
/*   Updated: 2025/03/29 20:26:00 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	throw_a(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a)->target = find_target_in_a(*stack_a, (*stack_b)->data);
	ft_printf("%d <----target \n", (*stack_a)->target->data);
	move_to_top(stack_a, (*stack_a)->target);
	push_a(stack_a, stack_b);
}

void	throw_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_match;

	best_match = find_best_match(*stack_a, *stack_b);
	(*stack_b)->target = find_target_in_b(*stack_b, best_match->data);
	move_to_top(stack_a, best_match);
	move_to_top(stack_b, (*stack_b)->target);
	push_b(stack_a, stack_b);
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
    t_stack *smallest = stack_a;

    while (current)
    {
        if (current->data > data && (!target || current->data < target->data))
            target = current;
        if (current->data < smallest->data)
            smallest = current;
        current = current->next;
    }
    if (target == NULL)
        target = smallest;
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
