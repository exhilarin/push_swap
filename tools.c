/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:22:48 by iguney            #+#    #+#             */
/*   Updated: 2025/04/12 12:07:31 by ilyas-guney      ###   ########.fr       */
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

int	is_sorted_b(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted_a(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last && last->next)
		last = last->next;
	return (last);
}


