/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:35:23 by iguney            #+#    #+#             */
/*   Updated: 2025/03/24 14:33:16 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rev_rotate_a(t_stack **stack_a)
{
	int tmp;
	t_stack *head;

	head = (*stack_a);
	while (head->next)
		head = head->next;
    tmp = head->data;
	del_one_from_stack(stack_a, head->data);
	add_front_to_stack(stack_a, tmp);
	message("rra");
	if (is_sorted(*stack_a) && (*stack_a)->size == 8)
		return ;
}

void rev_rotate_b(t_stack **stack_b)
{
	int tmp;
	t_stack *head;

	head = (*stack_b);
	while (head->next)
		head = head->next;
    tmp = head->data;
	del_one_from_stack(stack_b, head->data);
	add_front_to_stack(stack_b, tmp);
	message("rrb");
}

void	rev_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	message("rrr");
}