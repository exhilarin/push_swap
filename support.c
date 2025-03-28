/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:58:00 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/03/28 17:20:23 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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