/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by iguney            #+#    #+#             */
/*   Updated: 2025/03/20 20:32:34 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Write actions.
// TODO: Write algorithms.

#include "push_swap.h" 

int main(int ac, char *av[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	if (ac > 1)
	{
		take_argv(&stack_a, &stack_b, av);
		print_stack(stack_a);
		swap_a(stack_a);
		print_stack(stack_a);
	}
	ft_printf("\n");
}
