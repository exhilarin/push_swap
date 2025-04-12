/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:13:11 by iguney            #+#    #+#             */
/*   Updated: 2025/04/12 23:04:08 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void take_argv(t_stack **stack_a, char *av[])
{
    int i;
    char **splitted;

    splitted = seperate_argv(av);
    if (check_argv(splitted))
	{
        i = -1;
        while (splitted[++i])
            add_back_to_stack(stack_a, ft_atol(splitted[i]));
    }
    i = 0;
    while(splitted[i])
        free(splitted[i++]);
    free(splitted);
}

char	**seperate_argv(char *av[])
{
	int		i;
	char	*str;
	char	*tmp;
	char	**splitted = NULL;

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

int	check_argv(char **splitted)
{
	int i;
	int j;
	
	i = -1;
	while (splitted[++i])
	{
		j = 1;
		if (!is_digit(splitted[i]))
			return(error());
		if (!(!check_zero(splitted[i]) || ft_atol(splitted[i]) == 0))
			return (error());
		if (INT_MAX < ft_atol(splitted[i]) || INT_MIN > ft_atol(splitted[i]))
			return (error());
		if (ft_strlen(splitted[i]) > 11)
			return(error());
		while (splitted[i + j])
		{
			if (ft_atol(splitted[i]) == ft_atol(splitted[i + j]))
				return (error());
			j++;
		}
	}
	return (1);
}
