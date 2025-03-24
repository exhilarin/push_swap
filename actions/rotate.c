/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:11:38 by iguney            #+#    #+#             */
/*   Updated: 2025/03/24 14:32:55 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	int tmp;
	t_stack *head;

	head = (*stack_a)->next;
	tmp = (*stack_a)->data;
	del_one_from_stack(stack_a, (*stack_a)->data);
	while (head->next)
		head = head->next;
	add_back_to_stack(stack_a, tmp);
	message("ra");
	if (is_sorted(*stack_a) &&  (*stack_a)->size == 8)
		return ;
}

void	rotate_b(t_stack **stack_b)
{
	int tmp;
	t_stack *head;

	head = (*stack_b)->next;
	tmp = (*stack_b)->data;
	del_one_from_stack(stack_b, (*stack_b)->data);
	while (head->next)
		head = head->next;
	add_back_to_stack(stack_b, tmp);
	message("rb");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	message("rr");
}