/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:51 by iguney            #+#    #+#             */
/*   Updated: 2025/03/26 11:09:06 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a)->size = stack_size(*stack_a);
	if ((*stack_a)->size <= 3)
		sort_for_three(*stack_a);
	else
	{
		push_b(stack_a, stack_b);
		if ((*stack_a)->size >= 4)
			push_b(stack_a, stack_b);
		// while ((*stack_a) || (*stack_b))
		// {
		// 	find_best_match(&stack_a, &stack_b);
		// 	(*stack_a) = (*stack_a)->next;
		// }
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
	t_stack	*current;
	int		min_cost;
	t_stack	*best_match_node;

	best_match = NULL;
	current = stack_b;
	min_cost = INT_MAX;
	best_match_node = NULL;
	while (current)
	{
		if (current->data < stack_a->data && (best_match == NULL ||
			current->data > best_match->data))
			best_match = current;
		int current_cost = calculate_total_cost(current, stack_a, stack_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best_match_node = current;
		}
		current = current->next;
	}
	return (best_match);
}

int	calculate_cost_a(int index_a, int size_a)
{
	if (index_a <= size_a / 2)
		return (index_a);
	else
		return (size_a - index_a);
}

int	calculate_cost_b(int index_b, int size_b)
{
	if (index_b <= size_b / 2)
		return (index_b);
	else
		return (size_b - index_b);
}

int	calculate_total_cost(t_stack *best_match, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	int		index_a;
	t_stack	*current_b;
	int		index_b;
	int		cost_a;
	int		cost_b;

	current_a = stack_a;
	index_a = 0;
	while (current_a != NULL)
	{
		if (current_a == best_match)
			break ;
		index_a++;
		current_a = current_a->next;
	}
	current_b = stack_b;
	index_b = 0;
	while (current_b != NULL)
	{
		if (current_b == best_match)
			break ;
		index_b++;
		current_b = current_b->next;
	}
	cost_a = calculate_cost_a(index_a, index_a);
	cost_b = calculate_cost_b(index_b, index_b);

	return (cost_a + cost_b);
}
