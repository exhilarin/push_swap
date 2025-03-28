/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by iguney            #+#    #+#             */
/*   Updated: 2025/03/27 22:39:57 by ilyas-guney      ###   ########.fr       */
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
	print_stack(stack_a);
	print_stack(stack_b);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	algorithm(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
