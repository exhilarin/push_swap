/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:58:00 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/04/12 16:12:25 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *node, t_stack *stack)
{
	int	index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current == node)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	sort_for_three(t_stack **stack_a)
{
	int a;
	int b;
	int c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		rev_rotate_a(stack_a, 0);
		swap_a(stack_a, 0);
	}
	else if (b < a && a < c)
		swap_a(stack_a, 0);
	else if (b < c && c < a)
		rotate_a(stack_a, 0);
	else if (c < a && a < b)
		rev_rotate_a(stack_a, 0);
	else if (c < b && b < a)
	{
		swap_a(stack_a, 0);
		rev_rotate_a(stack_a, 0);
	}
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
	if (index <= stack_size(stack) / 2)
		node->cost = index;
	else
		node->cost = stack_size(stack) - index;

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

void	move_to_top(t_stack **stack, t_stack *node_to_move, char flag)
{
	int	index;
	int	size;

	size = stack_size(*stack);
	index = get_index(node_to_move, *stack);
	if (node_to_move == NULL || index == 0)
		return ;
	if (flag == 'a')
	{
		if (index <= size / 2)
			while (index-- > 0)
				rotate_a(stack, 0);
		else
			while (index++ < size)
				rev_rotate_a(stack, 0);
	}
	else if (flag == 'b')
	{
		if (index <= size / 2)
			while (index-- > 0)
				rotate_b(stack, 0);
		else
			while (index++ < size)
				rev_rotate_b(stack, 0);
	}
}
