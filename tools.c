/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:22:48 by iguney            #+#    #+#             */
/*   Updated: 2025/03/21 03:12:47 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_zero(const char *str)
{
	int	i;
	int len;
	int check;

	i = 0;
	check = 0;
	len = ft_strlen(str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '0')
			check++;
		i++;
	}
	if (check == len)
		return (1);
	return (0);
}

void free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    free(stack);
}

