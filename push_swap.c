/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by iguney            #+#    #+#             */
/*   Updated: 2025/03/30 01:52:04 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Write algorithms.

#include "push_swap.h" 

int main(int ac, char *av[])
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	int i;
	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (error());
		i++;
	}

	take_argv(&stack_a, av);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	algorithm(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a)->size = stack_size(*stack_a);
	if ((*stack_a)->size <= 3)
		sort_for_three(stack_a);
	else
	{
		push_b(stack_a, stack_b);
		if ((*stack_a)->size > 3)
			push_b(stack_a, stack_b);
		while (stack_size(*stack_a) > 3)
			throw_b(stack_a, stack_b);
		sort_for_three(stack_a);
		while (stack_size(*stack_b) > 0)
			throw_a(stack_a, stack_b);
		while (is_sorted(*stack_a) == 0)
			rev_rotate_a(stack_a, 0);
	}
	
}
