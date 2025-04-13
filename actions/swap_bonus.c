/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:50:29 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/04/13 02:43:41 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stack_a, int flag)
{
	int		temp;
	t_stack	*head;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	head = (*stack_a);
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	if (!flag)
		message("sa");
}

void	swap_b(t_stack **stack_b, int flag)
{
	int		temp;
	t_stack	*head;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	head = (*stack_b);
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	if (!flag)
		message("sb");
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	message("ss");
}
