/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:51 by iguney            #+#    #+#             */
/*   Updated: 2025/03/24 17:50:36 by iguney           ###   ########.fr       */
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
		push_b(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		// while (stack_a->size > 3)
		// {

		// }
	}
}

void	sort_for_three(t_stack *stack_a)
{
	t_stack *tmp;

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

void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	 
}