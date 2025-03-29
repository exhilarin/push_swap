/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:50:29 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/03/29 01:51:07 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_a(t_stack **stack_a) 
{
    int temp;
    t_stack *head;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;

    head = (*stack_a);
    temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;

    message("sa");
}

void	swap_b(t_stack **stack_b)
{
	int temp;
	t_stack *head;

	if (!stack_b || !(*stack_b)->next)
		return ;

	head = (*stack_b);
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;

	message("sb");
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	message("ss");
}
