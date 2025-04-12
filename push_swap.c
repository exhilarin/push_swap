/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 00:29:10 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Write algorithms.

#include "push_swap.h"

int main(int ac, char *av[])
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	first_control(ac, av);
	take_argv(&stack_a, av);
	algorithm(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted_a(*stack_a))
		return (free_stack(*stack_a), exit(0));
	if (stack_size(*stack_a) == 2)
		return(swap_a(stack_a, 0), exit(0));
	if (stack_size(*stack_a) == 3)
		sort_for_three(stack_a);
	else
	{
		push_b(stack_a, stack_b);
		if (stack_size(*stack_a) > 3)
			push_b(stack_a, stack_b);
		while (stack_size(*stack_a) > 3)
			throw_b(stack_a, stack_b);
		move_to_top(stack_b, find_max_value(*stack_b), 'b');
		sort_for_three(stack_a);
		while (stack_size(*stack_b) != 0)
			throw_a(stack_a, stack_b);
		while (!is_sorted_a(*stack_a))
			rev_rotate_a(stack_a, 0);
	}
}
