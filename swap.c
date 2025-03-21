/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:50:29 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/03/21 06:15:50 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int temp;
	t_stack *head;

	if (!stack_a || !stack_a->next)
		return ;
	else
	{
		head = stack_a;
		temp = head->data;
		head->data = head->next->data;
		head->next->data = temp;
	}
}

void	swap_b(t_stack *stack_b)
{
	int temp;
	t_stack *head;

	if (!stack_b || !stack_b->next)
		return ;
	else
	{
		head = stack_b;
		temp = head->data;
		head->data = head->next->data;
		head->next->data = temp;
	}
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_a(stack_b);
}