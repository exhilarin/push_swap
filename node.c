/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:52:50 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/03/21 05:04:09 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void add_to_stack(t_stack **stack, int data)
{
	t_stack *new;
	t_stack *tmp;

	new = new_node(data);
	if (!new)
		return;

	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}


void print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("[%d]", stack->data);
		if (stack->next)
			ft_printf(" -> ");
		stack = stack->next;
	}
	ft_printf("\n");
}
