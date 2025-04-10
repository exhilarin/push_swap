/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:35:23 by iguney            #+#    #+#             */
/*   Updated: 2025/03/30 00:25:52 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rev_rotate_a(t_stack **stack_a, int flag)
{
	int tmp;
	t_stack *head;

	head = (*stack_a);
	while (head->next)
		head = head->next;
	tmp = head->data;
	del_one_from_stack(stack_a, head->data);
	add_front_to_stack(stack_a, tmp);
	if (!flag)
		message("rra");
}

void rev_rotate_b(t_stack **stack_b, int flag)
{
	int tmp;
	t_stack *head;

	head = (*stack_b);
	while (head->next)
		head = head->next;
	tmp = head->data;
	del_one_from_stack(stack_b, head->data);
	add_front_to_stack(stack_b, tmp);
	if (!flag)
		message("rrb");
}

void rev_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_a(stack_a, 1);  
	rev_rotate_b(stack_b, 1); 
	message("rrr");       
}
