/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:22:48 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 00:24:34 by iguney           ###   ########.fr       */
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

int	stack_size(t_stack *stack)
{
	int	size;
	t_stack *tmp;
	
	size = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}


int	get_index(t_stack *node, t_stack *stack)
{
	int	index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current == node)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last && last->next)
		last = last->next;
	return (last);
}

int error()
{
	ft_printf("Error!\n");
	exit(0);
	return (0);
}
