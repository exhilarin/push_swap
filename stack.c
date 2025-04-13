/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:13:11 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 05:59:49 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_control(int ac, char *av[])
{
	int	i;

	if (ac < 2)
		exit(0);
	i = 1;
	while (i < ac)
	{
		if (is_all_spaces(av[i]))
			return (error());
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (error());
		i++;
	}
	return (1);
}

void	take_argv(t_stack **stack_a, char *av[])
{
	int		i;
	char	**splitted;

	splitted = seperate_argv(av);
	if (check_argv(splitted, stack_a))
	{
		i = -1;
		while (splitted[++i])
			add_back_to_stack(stack_a, ft_atol(splitted[i]));
	}
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

char	**seperate_argv(char *av[])
{
	int		i;
	char	*str;
	char	*tmp;
	char	**splitted;

	splitted = NULL;
	str = ft_strdup(av[1]);
	if (!av[2])
		splitted = seperate_str(str, ' ');
	else
	{
		i = 1;
		while (av[++i])
		{
			tmp = all_in_one(str, av[i]);
			free(str);
			str = tmp;
		}
		splitted = seperate_str(str, ' ');
	}
	free(str);
	return (splitted);
}

int	check_argv(char **splitted, t_stack **stack_a)
{
	int	i;
	int	j;

	i = -1;
	while (splitted[++i])
	{
		j = 1;
		if (!is_digit(splitted[i]))
			return (free_stack(*stack_a), free_str(splitted), error());
		if (!(!check_zero(splitted[i])) || ft_atol(splitted[i]) == 0)
			return (free_stack(*stack_a), free_str(splitted), error());
		if (INT_MAX < ft_atol(splitted[i])
			|| INT_MIN > ft_atol(splitted[i]))
			return (free_stack(*stack_a), free_str(splitted), error());
		while (splitted[i + j])
		{
			if (ft_atol(splitted[i]) == ft_atol(splitted[i + j]))
				return (free_stack(*stack_a), free_str(splitted), error());
			j++;
		}
	}
	return (1);
}
