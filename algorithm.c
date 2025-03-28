/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:51 by iguney            #+#    #+#             */
/*   Updated: 2025/03/28 16:37:27 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_match;
	t_stack	*target_b;
	t_stack *target_a;

	(*stack_a)->size = stack_size(*stack_a);
	if ((*stack_a)->size <= 3)
		sort_for_three(*stack_a);
	else
	{
		push_b(stack_a, stack_b);
		if ((*stack_a)->size >= 4)
			push_b(stack_a, stack_b);
		while (stack_size(*stack_a) > 4)
		{
			best_match = find_best_match(*stack_a, *stack_b);
			target_b = find_target_in_b(*stack_b, best_match->data);
			move_to_top(stack_a, stack_b, best_match, target_b);
			push_b(stack_a, stack_b);
		}
		while (stack_size(*stack_b) > 1)
		{
			target_a =  find_target_in_a(*stack_a, (*stack_b)->data);
			move_to_top(stack_a, stack_b, target_a, *stack_b);
			push_a(stack_a, stack_b);
		}
	}
}

void	sort_for_three(t_stack *stack_a)
{
	t_stack	*tmp;
	tmp = stack_a;
	while (stack_a->next)
	{
		if (tmp->data > tmp->next->data)
		{
			swap_a(tmp);
			tmp = stack_a;
		}
		else
			tmp = tmp->next;
		if (is_sorted(stack_a))
			return ;
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

int	calculate_cost(t_stack *node, t_stack *stack)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current == node)
			break ;
		index++;
		current = current->next;
	}
	node->index = index;
	if (index <= stack->size / 2)
		node->cost = index;
	else
		node->cost = stack->size - index;

	return (node->cost);
}

int	calculate_total_cost(t_stack *node_a, t_stack *stack_a,
	t_stack *node_b, t_stack *stack_b)
{
	stack_a->size = stack_size(stack_a);
	stack_b->size = stack_size(stack_b);

	calculate_cost(node_a, stack_a);
	calculate_cost(node_b, stack_b);
	if ((node_a->index <= stack_a->size / 2 && node_b->index <= stack_b->size / 2) ||
		(node_a->index > stack_a->size / 2 && node_b->index > stack_b->size / 2))
	{
		if (node_a->cost > node_b->cost)
			node_a->total_cost = node_a->cost;
		else
			node_a->total_cost = node_b->cost;
	}
	else
		node_a->total_cost = node_a->cost + node_b->cost;
	return (node_a->total_cost);
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

int	get_index(t_stack *node, t_stack *stack)
{
	int		index;
	t_stack	*current;

	if (!node || !stack)
		return (-1);

	index = 0;
	current = stack;
	while (current)
	{
		if (current == node)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

