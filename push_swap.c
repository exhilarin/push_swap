/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by iguney            #+#    #+#             */
/*   Updated: 2025/03/21 15:27:39 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Write actions.
// TODO: Write algorithms.

#include "push_swap.h" 

int main(int ac, char *av[])
{
	t_stack *stack_a = NULL;
	t_stack *stack_b;

	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (error());

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (0);
	take_argv(&stack_a, av);
	print_stack(stack_a);
	push_b(stack_a, stack_b);
	swap_a(stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);
	return (0);
}
