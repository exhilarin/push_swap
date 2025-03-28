/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 05:58:53 by iguney            #+#    #+#             */
/*   Updated: 2025/03/28 16:55:35 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return ;
	add_front_to_stack(stack_a, (*stack_b)->data);
	del_one_from_stack(stack_b, (*stack_b)->data);
	if ((*stack_a)->size <= 3)
			sort_for_three(*stack_a);
	message("pa");
	if (is_sorted(*stack_a) && (*stack_a)->size == stack_size(*stack_a))
		return ;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
		return ;
	add_front_to_stack(stack_b, (*stack_a)->data);
	del_one_from_stack(stack_a, (*stack_a)->data);
	(*stack_a)->size = stack_size(*stack_a);
	(*stack_b)->size = stack_size(*stack_b);
	(*stack_a)->size--;
	(*stack_b)->size++;
	if ((*stack_a)->size <= 3)
			sort_for_three(*stack_a);
	message("pb");
}
