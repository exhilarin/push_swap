/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 05:58:53 by iguney            #+#    #+#             */
/*   Updated: 2025/03/22 04:08:00 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return ;
	add_front_to_stack(stack_a, (*stack_b)->data);
	del_one_from_stack(stack_b, (*stack_b)->data);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
		return ;
	add_front_to_stack(stack_b, (*stack_a)->data);
	del_one_from_stack(stack_a, (*stack_a)->data);
}
