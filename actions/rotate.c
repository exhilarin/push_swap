/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:11:38 by iguney            #+#    #+#             */
/*   Updated: 2025/03/22 04:08:10 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	int i;
	int tmp;
	t_stack *head;

	i = 0;
	head = (*stack_a)->next;
	tmp = (*stack_a)->data;
	del_one_from_stack(stack_a, (*stack_a)->data);
	while (head->next)
		head = head->next;
	add_back_to_stack(stack_a, tmp);
}

void	rotate_b(t_stack **stack_b)
{
	int i;
	int tmp;
	t_stack *head;

	i = 0;
	head = (*stack_b)->next;
	tmp = (*stack_b)->data;
	del_one_from_stack(stack_b, (*stack_b)->data);
	while (head->next)
		head = head->next;
	add_back_to_stack(stack_b, tmp);
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}