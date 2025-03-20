/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:13:11 by iguney            #+#    #+#             */
/*   Updated: 2025/03/20 02:22:25 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char *av[])
{
	int i;
	int j;

	i = 0;
	while (av[++i])
	{
		j = 1;
		if (!(!check_zero(av[i]) || ft_atol(av[i]) == 0))
			return (error());;
		if (2147483647 < ft_atol(av[i]) || -2147483648 > ft_atol(av[i]))
			return (error());
		while (av[i + j])
		{
			if (ft_atol(av[i]) == ft_atol(av[i + j]))
				return (error());
			j++;
		}
	}
	return (1);
}

void	take_argv(t_stack **stack_a, char *av[])
{
	int i;

	if (check_argv(av))
	{
		i = 0;
		while (av[++i])
			add_to_stack(stack_a, ft_atol(av[i]));
		print_stack(*stack_a);
	}
}
