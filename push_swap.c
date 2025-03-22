/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by iguney            #+#    #+#             */
/*   Updated: 2025/03/22 06:41:37 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Write actions.
// TODO: Write algorithms.

#include "push_swap.h" 

int main(int ac, char *av[])
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (error());

	take_argv(&stack_a, av);
	print_stack(stack_a);
	rotate_a(&stack_a);
	print_stack(stack_a);
	rev_rotate_a(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);
	return (0);
}
