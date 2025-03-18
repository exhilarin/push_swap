/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:13:11 by iguney            #+#    #+#             */
/*   Updated: 2025/03/18 06:12:51 by iguney           ###   ########.fr       */
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
		if (!check_zero(av[i]) || ft_atol(av[i]) == 0)
			;
		if (2147483647 < ft_atol(av[i]) || -2147483648 > ft_atol(av[i]))
			return (error(), 0);
		while (av[i + j])
		{
			if (ft_atol(av[i]) == ft_atol(av[i + j]))
				return (error(), 0);
			j++;
		}
	}
	return (1);
}

// void	take_argv(t_stack **stack_a, int ac, char *av[])
// {
	
// }